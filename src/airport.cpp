#include "../headers/Airport.hpp"


Airport::Airport(){
      //vector<Plane*> planes;

}

void Airport::addPlane(Plane *plane)
{
    airport_mutex.lock();
    planes.push_back(plane);
    airport_mutex.unlock();
}

void Airport::showPlane(){
     for (auto &pl : planes) {
    cout << pl->getName() << endl;
  }
}



