#include "../headers/Airport.hpp"
#include <thread>

std::mutex waiting_planes_mutex;
std::mutex airport_mutex;

Point2D WaitCircuit[6] = {Point2D(-100, 0),  Point2D(-50, -100),
                          Point2D(50, -100), Point2D(100, 0),
                          Point2D(50, 100),  Point2D(-50, 100)};
Point2D LandCircuit[2] = {Point2D(-50, 0), Point2D(50, 0)};

//!---------------------------------------------------------------------!//

/* void flyPlane(Plane &plane, bool &stop_thread) {
  plane.position();
  plane.joinWaitCircuit();
  while (!stop_thread) {
    plane.rotate();
  }
} */

void Plane::flyPlane(Plane &planeq, bool &stop_thread) {
  planeq.joinWaitCircuit();
  if(autoLand == false){}
  bool landed = false;
  bool flying = true; // bool pour l'état de l'avion

  Point2D PtLand(-100, 0); // Point d'aterrissage et de décollage
  Point2D PtTO(100, 0);

  int rdnTime = random(500, 600); // counter et random pour crée un "timer"
  int counter = 0; // pour l'aterrissage et evite d'utiliser un sleep

  while (!stop_thread) {
    if (flying == true) {
      planeq.rotate();
      counter += 1;

      if (planeq == PtLand) {
        if (counter >= rdnTime) { // si l'avion est au point d'aterrissage

          planeq.land();
          flying = false; // aterrissage
          cout << "successfully landed !" << endl;
          landed = true;

          if (landed == true && !stop_thread) {
            planeq.driveToPark();
            planeq.rdnTIME(); // l'avion va se garer et resort aprés un temps
                              // aléatoire
            planeq.driveToTO();
            cout << "ready to TAKE OFF !" << endl;

            planeq.takeoff();
            cout << "je redemarreeeeeeeee" << endl; // l'avion redécolle
            // this_thread::sleep_for(5s);
            landed = false;
            counter = 0;
            flying = true;

            planeq.joinWaitCircuit();
            // stop_thread =true;
          }
        }
      }
    }
  }
}

//!---------------------------------------------------------------------!//

Plane::Plane() {
  identification = "AF" + to_string(random(100, 999));
  alt = 10000;

  pos = Point2D(random(-300, 300), random(-300, 300));

  t_ = thread(this.flyPlane, ref(*this), ref(stop_thread));
}

void Plane::rdnTIME() {
  int sleep = random(0, 10);
  this_thread::sleep_for(std::chrono::seconds(sleep));
}

Point2D Plane::getPos() { return pos; }

/* Plane::Plane(string &name) {
  identification = name;
  alt = 5000;

  pos = Point2D();
} */

void Plane::joinWaitCircuit() {
  Point2D closer = WaitCircuit[0];
  int tmp;
  for (size_t i = 1; i < 6; i++) {
    if (pos.distanceTo(WaitCircuit[i]) < pos.distanceTo(closer)) {
      closer = WaitCircuit[i];
      tmp = i;
    }
  }
  pos = closer;
  if (tmp >= 5)
    nextPt = WaitCircuit[0];
  else
    nextPt = WaitCircuit[tmp + 1];
  position();
}

void Plane::rotate() {
  int i = -1;
  Equation equa;
  bool found = false;

  equa = calcEquation(pos, nextPt);

  // pos.print();
  // nextPt.print();
  // cout << "equa : ax = " << equa.ax << " || b = " << equa.b << endl;
  // cout << "----------" << endl;

  found = false;
  if (equa.ax == 0) {
    if (pos.getY() < 0) {
      pos.setX(pos.getX() + 1);
    } else if (pos.getY() > 0) {
      pos.setX(pos.getX() - 1);
    }
  } else {
    if (pos.getX() > 0) {

      if (pos.getY() >= 0) {
        float y = equa.ax * (pos.getX() - 1) + equa.b;
        pos.setXY(pos.getX() - 1, y);
      } else {
        float y = equa.ax * (pos.getX() + 1) + equa.b;
        pos.setXY(pos.getX() + 1, y);
      }

    } else {
      if (pos.getY() > 0) {
        float y = equa.ax * (pos.getX() - 1) + equa.b;
        pos.setXY(pos.getX() - 1, y);
      } else {
        float y = equa.ax * (pos.getX() + 1) + equa.b;
        pos.setXY(pos.getX() + 1, y);
      }
    }
  }
  if (nextPt.getX() == pos.getX()) {
    pos = nextPt;
    nextPt = obtainNextPt(nextPt);
  }
  this_thread::sleep_for(0.1s);
}

Point2D Plane::obtainNextPt(Point2D &actual) {
  int tmp;
  for (size_t i = 0; i < 6; i++) {
    if (actual.getX() == WaitCircuit[i].getX() &&
        actual.getY() == WaitCircuit[i].getY()) {
      tmp = i + 1;
    }
  }
  if (tmp == 6)
    tmp = 0;
  return WaitCircuit[tmp];
}

void Plane::land() {
  float tmpX = pos.getX();
  float tmpalt = alt;

  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(0.2s);
    pos.setX(pos.getX() - ((tmpX / 2) / 10));
    alt = (alt - (tmpalt / 10));
    position();
  }
}

void Plane::takeoff() {
  float tmpX = pos.getX();

  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(0.2s);
    pos.setX(pos.getX() + (tmpX / 10));
    alt = (alt + 5000 / 10);
    position();
  }
}

void Plane::driveToPark() {
  float tmpX = pos.getX();
  float tmpY = pos.getY();
  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(0.5s);
    pos.setX(pos.getX() - (tmpX / 10));
    pos.print();
  }
  for (int j = 0; j < 10; j++) {
    this_thread::sleep_for(0.5s);
    pos.setY(pos.getY() - 1);
    pos.print();
  }
}

void Plane::driveToTO() {
  float tmpX = pos.getX();
  float tmpY = pos.getY();
  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(0.5s);
    pos.setY(pos.getY() + 1);
    pos.print();
  }

  for (int i = 0; i < 10; i++) {
    this_thread::sleep_for(0.5s);
    pos.setX(pos.getX() + 5);
    pos.print();
  }
}

string Plane::getName() { return identification; }

void Plane::position() {
  cout << "Plane : " << identification << endl;
  pos.print();
  cout << "alt = " << alt << "ft" << endl;
}

void Plane::setlandStatus(bool status){
  autoLand = status;
}








void Plane::operator=(Point2D &pt) { pos.setXY(pt.getX(), pt.getY()); }

bool Plane::operator==(Point2D &pt1) {
  if ((pos.getX() == pt1.getX()) && (pos.getY() == pt1.getY())) {
    return true;
  } else {
    return false;
  }
}
ostream &operator<<(ostream &out, Plane &c) {
  out << c.pos.getX() << endl;
  return out;
}

Plane::~Plane() {
  stop_thread = true;
  t_.join();
  cout << "Thread was stopped" << std::endl;
}
//?--------

void add_plane_sometimes(bool &stop) {
  default_random_engine generator;
  uniform_int_distribution<int> distribution(100, 800);
  while (stop == false) {
    // std::this_thread::sleep_for(3s);
    Plane plane;
    // waiting_planes.add_a_plane(plane);
  }
}