#include "Cylinder.h"

//------------------------------------------------------------------------------
Cylinder::Cylinder()
    :Cylinder(1, 1)
{
}

//------------------------------------------------------------------------------
Cylinder::Cylinder(double r, double h)
    :Polyhedron("Cylinder"),
     height(h),
     radius(r)
{
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

//------------------------------------------------------------------------------
void Cylinder::read(std::istream& ins)
{
    // Implement this function

    ins >> height >> radius;
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

//------------------------------------------------------------------------------
void Cylinder::display(std::ostream& outs) const
{
    Polyhedron::display(outs);
    
    outs << "Radius: " << radius << " Height: " << height; 
}

//------------------------------------------------------------------------------
void Cylinder::scale(double scalingFactor)
{
    Polyhedron::scale(scalingFactor);
    // Implement this function
    radius *= scalingFactor;
    height *= scalingFactor;
}

Polyhedron* Cylinder::clone() const
{
    return new Cylinder(*this);
}

void Cylinder::setRadius(double r)
{
    radius = r;
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

void Cylinder::setHeight(double h)
{
    height = h;
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}