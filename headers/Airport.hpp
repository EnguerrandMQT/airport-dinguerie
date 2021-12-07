#include "Plane.hpp"


class Airport {
private:
  thread t_;

  vector<Plane *> planes;
  Point2D location;

  bool runwayAvailable = true;

  bool stop_thread;

public:
  Airport();
  void addPlane(Plane *plane);
  void showPlane();

  ~Airport();
};

class Aiport;
void threadAirport(bool &stop_thread);