#include "Bin.h"

Bin::Bin(const int capacity)
{
  capacity_ = capacity;
  size_ = 0;
  vectors_ = new Vector3D*[capacity];
  initialise(0);
}

Bin::Bin(const Bin& copy)
{
  capacity_ = copy.capacity_;
  size_ = copy.size_;
  vectors_ = new Vector3D*[copy.capacity_];

  // Create a copy of the data, don't point to it
  for (int i = 0; i < copy.size_; i++)
    vectors_[i] = new Vector3D(*copy.vectors_[i]);
}

Bin::~Bin()
{
  // Delete it all...
  for (int i = 0; i < size_; i++)
    delete vectors_[i];

  delete[] vectors_;
}

Bin& Bin::operator=(const Bin& rhs)
{
  // First remove all data from memory
  for (int i = 0; i < size_; i++)
    delete vectors_[i];

  // Then the array itself
  delete[] vectors_;

  // Now assign...
  capacity_ = rhs.capacity_;
  size_ = rhs.size_;
  vectors_ = new Vector3D*[capacity_];

  // Copy the data
  for (int i = 0; i < size_; i++)
    vectors_[i] = new Vector3D(*rhs.vectors_[i]);

  return *this;
}

void Bin::add(const float x, const float y, const float z)
{
  if (size_ == capacity_)
    expand(); // Expand the array if needed

  // Add the new vector and increase size
  vectors_[size_++] = new Vector3D(x, y, z);
}

void Bin::remove(const int b)
{
  if (b < 0 || b >= size_)
    throw std::out_of_range("Index out of bounds");

  delete vectors_[b]; // Delete the vector at b from memory

  // Move the rest of the vectors down in its place
  for (int i = b + 1; i < size_; i++)
    vectors_[i - 1] = vectors_[i];

  // Nullify the duplicate at the end and decrease size
  vectors_[--size_] = nullptr;
}

Vector3D* Bin::first()
{
  return vectors_[0];
}

int Bin::size() {
  return size_;
}

float Bin::getX(const int a) const
{
  if (a < 0 || a >= size_)
    throw std::out_of_range("Index out of bounds");

  return vectors_[a]->getX();
}

float Bin::getY(const int a) const
{
  if (a < 0 || a >= size_)
    throw std::out_of_range("Index out of bounds");

  return vectors_[a]->getY();
}

float Bin::getZ(const int a) const
{
  if (a < 0 || a >= size_)
    throw std::out_of_range("Index out of bounds");

  return vectors_[a]->getZ();
}

void Bin::expand()
{
  // Double capacity so we don't need to expand as often
  capacity_ *= 2;
  auto** tempVectors = new Vector3D*[capacity_];

  // Point to the existing data instead of copying
  // Potential performance gains
  for (int i = 0; i < size_; i++)
    tempVectors[i] = vectors_[i];

  // Delete the old array from memory (but not the data this time)
  delete[] vectors_;

  vectors_ = tempVectors; // Assign our new array
  initialise(size_); // Initialise the empty elements
}

void Bin::initialise(const int from) {
  // Set all elements from the given index onward to null
  for (int i = from; i < capacity_; i++)
    vectors_[i] = nullptr;
}
