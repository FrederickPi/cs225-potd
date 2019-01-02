#include <iostream>
#include <string>
using namespace std;

#include "Square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

Square & Square::operator=(const Square & other) {
	if (this == &other) {return *this;}
	delete lengthptr;
	lengthptr = new double;
	*lengthptr = other.getLength();
	name = other.name;
	return *this; 
}

Square Square::operator+(const Square & other) {
	Square * newSquare = new Square();
	newSquare->setName(this->getName() + other.getName());
	newSquare->setLength(this->getLength() + other.getLength());
	return *newSquare;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

