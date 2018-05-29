//******************************************************************************
//** This class represents a vector in 3D space:
//** - Initialises to 0 vector or given co-ordinates;
//** - Instances can be added and subtracted;
//** - Instances can be multiplied or divided by a scalar;
//** - Operators to find scalar and vector products are defined;
//** - Can be compared for equality;
//** - Can compute its magnitude;
//** - Can compute its norm (unit) vector;
//** - Can compute a unit vector orthogonal to itself and a given vector
//** - Can return its x, y, or z co-ordinates.
//**
//** File: Vector3D.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.1
//******************************************************************************
#ifndef CSC3221_PROJECT_1_VECTOR3D_H
#define CSC3221_PROJECT_1_VECTOR3D_H

#include <cmath>

class Vector3D {

public:
  // Constructor with provided default co-ordinates
  explicit Vector3D(float x = 0, float y = 0, float z = 0);

  // Copy constructor
  Vector3D(const Vector3D& copy);

  // Destructor
  ~Vector3D();

  // Assignment operator
  Vector3D& operator=(const Vector3D& rhs);

  // Add or subtract two vectors
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;

  // Multiply or divide a vector by a scalar
  Vector3D operator*(float rhs) const;
  Vector3D operator/(float rhs) const;

  //Find scalar(*) and vector(%) products of two vectors
  float operator*(const Vector3D& rhs) const;
  Vector3D operator%(const Vector3D& rhs) const;

  // Comparison operators
  bool operator==(const Vector3D& rhs) const;
  bool operator!=(const Vector3D& rhs) const;

  // Return the magnitude of the vector
  double computeMagnitude() const;

  // Return a unit vector in the same direction
  Vector3D computeUnit() const;

  // Return a unit vector orthogonal to self and the given vector
  Vector3D computeOrthogonalUnit(const Vector3D& vector) const;

  // Get methods
  float getX() const;
  float getY() const;
  float getZ() const;

private:
  // Co-ordinates in 3 dimensions
  float x_, y_, z_;

};

#endif //CSC3221_PROJECT_1_VECTOR3D_H
