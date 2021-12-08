#include "Plane.hpp"

class Airport;
	void threadAirport(Airport &airport, bool &stop_thread);

class Airport 
{
	private:
		vector<Plane*> avions;
		Point2D location;
		thread t_;
		bool stop_thread = false;

	public:
		Airport();
		void addPlane(Plane *plane);
		void rdnTIME();
		~Airport();
		void avionfront(bool land);
		thread getT();
};

