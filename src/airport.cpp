#include "../headers/Airport.hpp"

Point2D Airports[6] = {Point2D(-100, 0), Point2D(-50, -100)};

void threadAirport(bool &stop_thread) {
  while (!stop_thread) {
    //if (runwayAvailable == true ){}
  }
}

Airport::Airport() {}

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

Airport::~Airport() {
  stop_thread = true;
  t_.join();
  cout << "Thread was stopped" << endl;
}
