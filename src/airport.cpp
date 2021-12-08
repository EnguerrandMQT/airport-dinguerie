#include "../headers/Airport.hpp"

/*thread Airport::getT(){
    return this->t_;
}*/

Airport::Airport(){
      t_ = thread(threadAirport, ref(*this) ,ref(stop_thread));
}

Airport::~Airport() {
  stop_thread = true;
  t_.join();
  cout << "ThreadAA was stopped" << std::endl;
}

void threadAirport(Airport &airport, bool &stop_thread){
    while(!stop_thread){
        this_thread::sleep_for(10s);
        //airport.rdnTIME();
        airport.avionfront(true);
        
    }
}

void Airport::rdnTIME() {
  int sleep = random(0, 10);
  this_thread::sleep_for(std::chrono::seconds(sleep));
}

void Airport::addPlane(Plane *plane)
{
    airport_mutex.lock();
    avions.push_back(plane);
    airport_mutex.unlock();
}

void Airport::avionfront(bool land){
    cout<<"1"<<endl;
    avions.front()->setAL(false);
    cout<<"2"<<endl;
}

