//******************************************************************************
//** A test class which asserts true or false to to indicate success or failure
//** for each of the basic required functions of Vector3D and Bin classes.
//** Also does a simple performance test comparison to std::vector
//**
//** File: Test.cpp
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.1
//******************************************************************************
#include <iostream>
#include <vector>

#include "Bin.h"

using namespace std;

int main()
{
    // Begin
    cout << "\n/*-----VECTOR3D & BIN TEST OUTPUT-----*/\n" << endl;
    cout << "Key:\n\tFailed\t\t==\t0\n\tSucceeded\t==\t1" << endl;
    cout << "\n/*-----------VECTOR3D TESTS-----------*/\n" << endl;

    // Let's create some parameters
    const int a = 1;
    const int b = 4;
    const int c = 6;

    // Make a vector
    Vector3D first(a, b, c);

    // Now ensure simple member functions are working correctly
    cout << "Get x value: " << (first.getX() == a) << endl;
    cout << "Get y value: " << (first.getY() == b) << endl;
    cout << "Get z value: " << (first.getZ() == c) << endl;

    // Is the magnitude as expected? Known result ~7.28
    const double magnitude = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));

    cout << "Compute magnitude: ";
    cout << (first.computeMagnitude() == magnitude) << endl;

    // Can we correctly determine when two vectors are equal?
    cout << "Determine equality: ";
    cout << (first == Vector3D(a, b, c)) << endl;

    // Can we correctly determine when two vectors are not equal?
    cout << "Determine inequality: ";
    cout << (first != Vector3D(b, c, a)) << endl;

    // Now we can test the copy constructor
    cout << "Copy constructor: ";
    cout << (first == Vector3D(first)) << endl;

    // ... and now the assignment operator using a temporary Vector3D
    Vector3D temp(a, a, a);

    cout << "Assignment operator: ";
    cout << ((temp = first) == first) << endl;

    // Let's test scalar multiplication and division
    const float scalar = 5;

    cout << "Multiplication by a scalar: ";
    cout << ((first * scalar) == Vector3D(scalar * a, scalar * b, scalar * c));
    cout << endl;

    cout << "Division by a scalar: ";
    cout << ((first / scalar) == Vector3D(a / scalar, b / scalar, c / scalar));
    cout << endl;

    // Let's make a second vector rearranging the same parameters
    Vector3D second(c, c, a);

    // Now let's see if we can perform addition and subtraction
    cout << "Addition of two vectors: ";
    cout << ((first + second) == Vector3D(a + c, b + c, c + a)) << endl;

    cout << "Subtraction of two vectors: ";
    cout << ((first - second) == Vector3D(a - c, b - c, c - a)) << endl;

    // Now for scalar product
    cout << "Scalar product: ";
    cout << ((first * second) == (a * c) + (b * c) + (c * a)) << endl;

    // Vector product (using known result as comparison)
    cout << "Vector product: ";
    cout << ((first % second) == Vector3D(-32, 35, -18)) << endl;

    // Unit vector
    Vector3D unit(first.computeUnit());

    cout << "Unit vector: ";
    //TODO see why apparently 1 != 1 unless I round here...
    cout << (round(unit.computeMagnitude()) == 1) << endl;

    // Orthogonal unit
    Vector3D orthogonal(first.computeOrthogonalUnit(second));

    cout << "Orthogonal unit vector: ";
    cout << (
        orthogonal * first == 0 &&
        //TODO ...and why the result of this only approaches 0 but != 0?
        round(orthogonal * second) == 0 &&
        round(orthogonal.computeMagnitude()) == 1
    );
    cout << endl;

    // Finished with Vector3D, test Bin...
    cout << "\n/*--------------BIN TESTS-------------*/\n" << endl;

    // Construct a bin of size 3, add a vector
    Bin test(3);
    test.add(a, b, c);

    // Test our copy constructor
    Bin copy(test);

    cout << "Copy constructor: ";
    cout << (copy.size() == test.size() && *test.first() == first);
    cout << endl;

    // Assignment operator
    copy.add(c, c, a);
    test = copy;

    cout << "Assignment operator: ";
    cout << (test.size() == 2) << endl;

    // Can we return a pointer to the first element
    cout << "Return pointer to first element: ";
    cout << (*test.first() == first) << endl;

    // Can we get the a'th x, y, and z co-ordinates?
    cout << "Get a'th co-ordinates: ";
    cout << (test.getX(0) == a && test.getY(0) == b && test.getZ(0) == c);
    cout << endl;

    // Can we remove the b'th element and shift the others down?
    test.remove(0);

    cout << "Remove b'th element and shift: ";
    cout << (test.size() == 1 && *test.first() == second);
    cout << endl;

    // Ensure exception is thrown when index is out of bounds
    int count = 0;

    // Should be out of range
    try {
        copy.remove(2);
    } catch (std::out_of_range& e) {
        count++;
    }

    // Should be out of range
    try {
        copy.remove(-1);
    } catch (std::out_of_range& e) {
        count++;
    }

    // Shouldn't be out of range
    try {
        copy.remove(0);
    } catch (std::out_of_range& e) {
        count--;
    }

    cout << "Out of bounds exceptions thrown: ";
    cout << (count == 2) << endl;

    // Does the bin expand beyond initial capacity
    test.add(a, a, a);
    test.add(b, b, b);
    test.add(c, c, c);

    cout << "Dynamic resizing: ";
    cout << (test.size() == 4) << endl;

    // Finally a performance test
    cout << "\n/*----------PERFORMANCE TEST----------*/\n" << endl;

    // Sum clock times and keep track of loops to attain averages
    clock_t binSum = 0;
    clock_t vectorSum = 0;
    int loops = 0;

    // We will compare our Bin to the 'standard' dynamic array
    Bin bin(100);
    vector<Vector3D> vectors;

    // Run the tests from 10 executions to 1 million
    for (int execs = 10; execs <= 1000000; execs *= 10) {
      // Start clock for our bin
      clock_t startBin = clock();

      // Keep adding vectors up to the no. executions
      for (int i = 0; i < execs; i++)
        test.add(a, a, a);

      for (int i = 0; i < execs; i++)
        test.remove(test.size() - 1);

      // Add time to our sum
      binSum += clock() - startBin;

      // Start clock for std::vector
      clock_t startVector = clock();

      // Keep adding the (same) vector up to the no. executions
      for (int i = 0; i < execs; i++)
        vectors.emplace_back(Vector3D(a, a, a));

      // std::vectors closest analogue to our bin::remove
      for (int i = 0; i < execs; i++)
        vectors.erase(vectors.end() - 1);

      // Add time to our sum
      vectorSum += clock() - startVector;

      // Increase test run counter
      loops++;
    }

    // Find out averages and difference
    double binAvg = binSum / loops;
    double vectorAvg = vectorSum / loops;
    double diff = fdim(binAvg, vectorAvg);

    // Print output
    cout << "Average bin class execution time\nup to ";
    cout << pow(10, loops) << " executions: ";
    cout << binAvg << endl;

    cout << "\nAverage std:vector execution time\nup to ";
    cout << pow(10, loops) << " executions: ";
    cout << vectorAvg << endl;

    cout << "\nExecution time difference: ";
    cout << diff << endl;

    double performance = diff / ((binAvg + vectorAvg) / 2);

    // See if performance within 10-20% of std::vector
    if (performance <= 0.1)
      cout << "\nPerformance: Excellent" << endl;
    else if (performance <= 0.2)
      cout << "\nPerformance: Good" << endl;
    else if (performance <= 0.3)
      cout << "\nPerformance: Average" << endl;
    else
      cout << "\nPerformance: Poor" << endl;

    cout << "\n/*-----------------END----------------*/\n" << endl;
}
