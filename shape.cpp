/*
Name: Dev KishorKumar Shah
UIN: 658560014
Professor: Ethan Ordentlich
Project 3 – Shape List
Class - CS251
*/

#include "shape.h"
#include <sstream>

// Default constructor
Shape::Shape() : x(0), y(0) {}

// Parameterized constructor
Shape::Shape(int x_val, int y_val) : x(x_val), y(y_val) {}

// Virtual destructor
Shape::~Shape() {}

// Accessor for x-coordinate
int Shape::getX() const
{
    return x;
}

// Accessor for y-coordinate
int Shape::getY() const
{
    return y;
}

// Setter for x-coordinate
void Shape::setX(int x_val)
{
    x = x_val;
}

// Setter for y-coordinate
void Shape::setY(int y_val)
{
    y = y_val;
}

// Creates a copy of the shape and returns a pointer to it.
Shape *Shape::copy()
{
    return new Shape(x, y);
}

// Print shape details
string Shape::printShape() const
{
    stringstream ss;
    ss << "It's a Shape at x: " << x << ", y: " << y;
    return ss.str();
}

// Implementation for the Circle class

// Default constructor
Circle::Circle() : Shape(), radius(0) {}

// Constructor with only radius
Circle::Circle(int r) : Shape(), radius(r) {}

// Parameterized constructor
Circle::Circle(int x_val, int y_val, int r) : Shape(x_val, y_val), radius(r) {}

// Virtual destructor
Circle::~Circle() {}

// Copy method
Circle *Circle::copy()
{
    return new Circle(this->getX(), this->getY(), radius);
}

// Accessor for radius
int Circle::getRadius() const
{
    return radius;
}

// Setter for radius
void Circle::setRadius(int r)
{
    radius = r;
}

// Print circle details
string Circle::printShape() const
{
    stringstream ss;
    ss << "It's a Circle at x: " << this->getX() << ", y: " << this->getY() << ", radius: " << radius;
    return ss.str();
}

// Implementation for the Rect class

// Default constructor
Rect::Rect() : Shape(), width(0), height(0) {}

// Constructor with width and height
Rect::Rect(int w, int h) : Shape(), width(w), height(h) {}

// Parameterized constructor
Rect::Rect(int x_val, int y_val, int w, int h) : Shape(x_val, y_val), width(w), height(h) {}

// Virtual destructor
Rect::~Rect() {}

// Copy method
Rect *Rect::copy()
{
    return new Rect(this->getX(), this->getY(), width, height);
}

// Accessors for width and height
int Rect::getWidth() const
{
    return width;
}

int Rect::getHeight() const
{
    return height;
}

// Setters for width and height
void Rect::setWidth(int w)
{
    width = w;
}

void Rect::setHeight(int h)
{
    height = h;
}

// Print rectangle details
string Rect::printShape() const
{
    stringstream ss;
    ss << "It's a Rectangle at x: " << this->getX() << ", y: " << this->getY();
    ss << " with width: " << width << " and height: " << height;
    return ss.str();
}

// Implementation for the RightTriangle class

// Default constructor
RightTriangle::RightTriangle() : Shape(), base(0), height(0) {}

// Constructor with base and height
RightTriangle::RightTriangle(int b, int h) : Shape(), base(b), height(h) {}

// Parameterized constructor
RightTriangle::RightTriangle(int x_val, int y_val, int b, int h) : Shape(x_val, y_val), base(b), height(h) {}

// Virtual destructor
RightTriangle::~RightTriangle() {}

// Copy method
RightTriangle *RightTriangle::copy()
{
    return new RightTriangle(this->getX(), this->getY(), base, height);
}

// Accessors for base and height
int RightTriangle::getBase() const
{
    return base;
}

int RightTriangle::getHeight() const
{
    return height;
}

// Setters for base and height
void RightTriangle::setBase(int b)
{
    base = b;
}

void RightTriangle::setHeight(int h)
{
    height = h;
}

// Print right triangle details
string RightTriangle::printShape() const
{
    stringstream ss;
    ss << "It's a Right Triangle at x: " << this->getX() << ", y: " << this->getY();
    ss << " with base: " << base << " and height: " << height;
    return ss.str();
}
