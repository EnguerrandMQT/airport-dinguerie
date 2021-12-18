#include "Plane.hpp"

#include <queue>

class Aiport;
void threadAirport(bool &stop_thread);
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
  Point2D getPos();

  ~Airport();
};