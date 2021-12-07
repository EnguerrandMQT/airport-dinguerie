#include "Plane.hpp"


class Airport 
{
	private:
		vector<Plane> planes;
		Point2D location;

	public:
		Airport();
		void addPlane(Plane &plane);
};

