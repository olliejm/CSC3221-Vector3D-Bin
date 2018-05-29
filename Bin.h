//******************************************************************************
//** This class represents a bin which can store Vector3D objects:
//** - Initialises to a default size of 10 or a given size;
//** - It allows access to a pointer to the first element;
//** - A vector can be added at the end from given co-ordinates;
//** - A vector can be removed from a given index and the array will contract;
//** - The co-ordinates of a vector at a given index can be retrieved;
//** - Array size will increase dynamically if required;
//** - Array is implemented as an array of pointers to improve performance.
//**
//** File: Bin.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.1
//******************************************************************************
#ifndef CSC3221_PROJECT_1_BIN_H
#define CSC3221_PROJECT_1_BIN_H

#include <stdexcept>

#include "Vector3D.h"

class Bin {

public:
  // Constructor with a default capacity
  explicit Bin(int size = 10);

  // Copy constructor
  Bin(const Bin& copy);

  // Destructor
  ~Bin();

  // Assignment operator
  Bin& operator=(const Bin& rhs);

  // Add element with given values to the end of the bin
  void add(float x, float y, float z);

  // Remove the b'th element and shift subsequent elements backwards
  void remove(int b);

  // Return a pointer to the first element
  Vector3D* first();

  // Return the size (number of valid elements)
  int size();

  // Get the x, y or z co-ordinate of the a'th element
  float getX(int a) const;
  float getY(int a) const;
  float getZ(int a) const;

private:
  // Our capacity and size
  int capacity_, size_;

  // Pointer to an array of pointers to Vector3Ds
  // May increase performance vs iterating over objects directly
  Vector3D** vectors_;

  // Expand the array when required
  void expand();

  // Initialise elements to null from a given index
  void initialise(int from);

};


#endif //CSC3221_PROJECT_1_BIN_H
