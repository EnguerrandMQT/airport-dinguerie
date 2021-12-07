#include "../headers/Airport.hpp"




int random(int val1, int val2)
{
    if (val1 > val2)
        swap(val1, val2);
    return (rand() % ((val2 - val1) + 1)) + val1;
}

Point2D::Point2D(const float &newx, const float &newy)
{
    setXY(newx, newy);
    //print();
}

Point2D::Point2D()
{
    setXY(rand() % 100 + 1, rand() % 100 + 1);
    //print();
}

void Point2D::setXY(const float &newx, const float &newy)
{
    setX(newx);
    setY(newy);
}
void Point2D::setX(const float &newx) { this->x = newx; }
void Point2D::setY(const float &newy) { this->y = newy; }

float Point2D::getX() { return x; }
float Point2D::getY() { return y; }

void Point2D::print()
{
    cout << "x = " << getX() << endl;
    cout << "y = " << getY() << endl;
}

float Point2D::distanceTo(Point2D &otherPoint2D)
{
    return (float)sqrt(pow(getX() - otherPoint2D.getX(), 2) + pow(getY() - otherPoint2D.getY(), 2));
}



Equation calcEquation(Point2D pt1, Point2D pt2){
    Equation func;
    func.ax = (pt2.getY()-pt1.getY())/(pt2.getX()-pt1.getX());
    func.b = pt2.getY() - (func.ax*pt2.getX());
    
    return (func); 
}