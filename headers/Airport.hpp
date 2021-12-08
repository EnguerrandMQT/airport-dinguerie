#include "Plane.hpp"

class Airport;
	void threadAirport(bool &stop_thread);

class Airport 
{
	private:
		vector<Plane> planes;
		Point2D location;
		thread t_;

	public:
		Airport();
		void addPlane(Plane &plane);

		~Airport();
};

