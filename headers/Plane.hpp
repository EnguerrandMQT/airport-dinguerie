#include "Function.hpp"

class Plane;
void flyPlane(Plane &plane, bool &stop_thread);
class Plane
{
    private:
        thread t_;

        string identification;
        int alt;
        Point2D pos;
        Point2D nextPt;

        bool stop_thread = false;

        //int fuel
        //int speed;
        //bool emergency;


    public:
        Plane();

        //Plane(string &name);
        Point2D getPos();
        void stopThread();
        void joinWaitCircuit();
        void rotate();

            void land();
    void driveToPark();
    void driveToTO();
    void takeoff();


    void rdnTIME();
        
        Point2D obtainNextPt(Point2D &actual);
        void position();
        string getName();
    void operator=(Point2D& pt);

    bool operator==(Point2D& pt1);
    friend ostream & operator << (ostream &out, Plane &c);

        ~Plane();

};

//void flyPlane(Plane &plane);


void add_plane_sometimes();

