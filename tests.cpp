/*
Name: Dev KishorKumar Shah
UIN: 658560014
Professor: Ethan Ordentlich
Project 3 – Shape List
Class - CS251
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(0) no tests")
{
  //
  // done
  //
}

TEST_CASE("(1) Shape class")
{
  Shape s;
  REQUIRE(s.getX() == 0);
  REQUIRE(s.getY() == 0);

  s.setX(5);
  s.setY(10);
  REQUIRE(s.getX() == 5);
  REQUIRE(s.getY() == 10);
}

TEST_CASE("(2) Circle class")
{
  Circle c;
  REQUIRE(c.getX() == 0);
  REQUIRE(c.getY() == 0);
  REQUIRE(c.getRadius() == 0);

  c.setX(5);
  c.setY(10);
  c.setRadius(15);
  REQUIRE(c.getX() == 5);
  REQUIRE(c.getY() == 10);
  REQUIRE(c.getRadius() == 15);
}

TEST_CASE("(3) Rect class")
{
  Rect r;
  REQUIRE(r.getX() == 0);
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getWidth() == 0);
  REQUIRE(r.getHeight() == 0);

  r.setX(5);
  r.setY(10);
  r.setWidth(15);
  r.setHeight(20);
  REQUIRE(r.getX() == 5);
  REQUIRE(r.getY() == 10);
  REQUIRE(r.getWidth() == 15);
  REQUIRE(r.getHeight() == 20);
}

TEST_CASE("(4) RightTriangle class")
{
  RightTriangle rt;
  REQUIRE(rt.getX() == 0);
  REQUIRE(rt.getY() == 0);
  REQUIRE(rt.getBase() == 0);
  REQUIRE(rt.getHeight() == 0);

  rt.setX(5);
  rt.setY(10);
  rt.setBase(15);
  rt.setHeight(20);
  REQUIRE(rt.getX() == 5);
  REQUIRE(rt.getY() == 10);
  REQUIRE(rt.getBase() == 15);
  REQUIRE(rt.getHeight() == 20);
}

TEST_CASE("(5) CanvasList class - Basic Operations")
{
  CanvasList clist;
  REQUIRE(clist.isempty() == true);
  REQUIRE(clist.size() == 0);

  // Adding shapes to the list and testing basic functions
  Shape *s1 = new Circle(5, 5, 10);
  clist.push_front(s1);
  REQUIRE(clist.isempty() == false);
  REQUIRE(clist.size() == 1);
  REQUIRE(clist.front()->value == s1);

  Shape *s2 = new Rect(10, 10, 20, 30);
  clist.push_back(s2);
  REQUIRE(clist.size() == 2);
  REQUIRE(clist.shapeAt(1) == s2);

  // Removing shapes
  Shape *popped_shape = clist.pop_front();
  REQUIRE(popped_shape == s1);
  delete popped_shape;
  REQUIRE(clist.size() == 1);

  popped_shape = clist.pop_back();
  REQUIRE(popped_shape == s2);
  delete popped_shape;
  REQUIRE(clist.size() == 1);
}

TEST_CASE("(6) CanvasList class - Advanced Operations")
{
  CanvasList clist;

  // Adding shapes
  Shape *s1 = new Circle(5, 5, 10);
  Shape *s2 = new Rect(10, 10, 20, 30);
  Shape *s3 = new RightTriangle(15, 15, 10, 20);

  clist.push_back(s1);
  clist.push_back(s2);
  clist.push_back(s3);

  REQUIRE(clist.size() == 3);

  // Testing find function
  int index = clist.find(5, 5);
  REQUIRE(index == 0);

  index = clist.find(10, 10);
  REQUIRE(index == 1);

  // Removing every other shape
  clist.removeEveryOther();
  REQUIRE(clist.size() == 2);
  REQUIRE(clist.shapeAt(0) == s1);
  REQUIRE(clist.shapeAt(1) == s3);

  // delete s1;

  // delete s3;
  // Note: s2 was removed and its memory was already deallocated
}
