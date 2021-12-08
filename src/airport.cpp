#include "../headers/Airport.hpp"


Airport::Airport(){
    t_ = thread(bool &stop_thread);
}

void Airport::addPlane(Plane &plane)
{
    airport_mutex.lock();
    //planes.push_back(plane);
    airport_mutex.unlock();
}



