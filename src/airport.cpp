#include "../headers/Airport.hpp"

Point2D Airports[6] = {Point2D(-100, 0), Point2D(-50, -100)};

void threadAirport(bool &stop_thread) {
  while (!stop_thread) {
    //if (runwayAvailable == true ){}
  }
}

Airport::Airport() {
  //location = Point2D(random(0,500),random(0,500));
}

void Airport::addPlane(Plane *plane) {
  airport_mutex.lock();
  planes.push_back(plane);
  airport_mutex.unlock();
}

void Airport::showPlane() {
  for (auto &pl : planes) {
    cout << pl->getName() << endl;
    
  }
  
}
Point2D Airport::getPos(){return location;}

Airport::~Airport() {
  stop_thread = true;
  t_.join();
  cout << "Thread was stopped" << endl;
}
