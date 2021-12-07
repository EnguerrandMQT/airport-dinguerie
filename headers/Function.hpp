#include <iostream>
#include <math.h>
#include <mutex>
#include <random>
#include <string>
#include <thread>
#include <vector>

//#include <SFML/Graphics.hpp>
//#include <SFML/System/Thread.hpp>

using namespace std;
//using namespace sf;

extern std::mutex waiting_planes_mutex;
extern std::mutex airport_mutex;

int random(int val1, int val2);

class Point2D {
private:
  float x, y; // private attributes

public:
  // constructors
  Point2D(); // fill X Y with random values (from 0 to 100)
  Point2D(const float &newx, const float &newy); // fill XYZ values

  // Setters and getters
  void setXY(const float &newx, const float &newy);
  void setX(const float &newx);
  void setY(const float &newy);
  float getX();
  float getY();

  // other methods
  void print();
  // prints the coordinates of the point
  float distanceTo(Point2D &otherPoint2D);
};

struct Equation {
  float ax = 0;
  float b = 0;
};
Equation calcEquation(Point2D pt1, Point2D pt2);

extern Point2D WaitCircuit[6];
extern Point2D LandCircuit[2];