#include "Vector3D.h"

Vector3D::Vector3D(const float x, const float y, const float z) :
    x_(x), y_(y), z_(z) {}

Vector3D::Vector3D(const Vector3D& copy) = default;

Vector3D::~Vector3D() = default;

Vector3D& Vector3D::operator=(const Vector3D& rhs) = default;

Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
  return Vector3D(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
  return Vector3D(x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_);
}

Vector3D Vector3D::operator*(const float rhs) const
{
  return Vector3D(x_ * rhs, y_ * rhs, z_ * rhs);
}

Vector3D Vector3D::operator/(const float rhs) const
{
  return Vector3D(x_ / rhs, y_ / rhs, z_ / rhs);
}

float Vector3D::operator*(const Vector3D& rhs) const
{
  return (x_ * rhs.x_) + (y_ * rhs.y_) + (z_ * rhs.z_);
}

Vector3D Vector3D::operator%(const Vector3D& rhs) const
{
  return Vector3D(
      (y_ * rhs.z_) - (z_ * rhs.y_),
      (z_ * rhs.x_) - (x_ * rhs.z_),
      (x_ * rhs.y_) - (y_ * rhs.x_)
  );
}

bool Vector3D::operator==(const Vector3D& rhs) const
{
  return (x_ == rhs.x_) && (y_ == rhs.y_) && (z_ == rhs.z_);
}

bool Vector3D::operator!=(const Vector3D& rhs) const
{
  return (x_ != rhs.x_) || (y_ != rhs.y_) || (z_ != rhs.z_);
}

double Vector3D::computeMagnitude() const
{
  return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

Vector3D Vector3D::computeUnit() const
{
  return Vector3D(*this) / computeMagnitude();
}

Vector3D Vector3D::computeOrthogonalUnit(const Vector3D& vector) const
{
  return (Vector3D(*this) % vector).computeUnit(); // Unit of cross product
}

float Vector3D::getX() const
{
  return x_;
}

float Vector3D::getY() const
{
  return y_;
}

float Vector3D::getZ() const
{
  return z_;
}
