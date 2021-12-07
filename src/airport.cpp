#include "../headers/Airport.hpp"


Airport::Airport(){
    
}

void Airport::addPlane(Plane &plane)
{
    airport_mutex.lock();
    //planes.push_back(plane);
    airport_mutex.unlock();
}



