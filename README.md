# CSC3221-Vector3D-Bin
Exercise in creating a storage bin for Vector3D objects from scratch in C++ for CSC3221 coursework component.

# Feedback

# Vector Implementation
Functionality

    All required functionality present and correct
    Nice addition of comparator operators

Correctness

    Good state representation
    Good use of const and pass by reference
    No catch for divide by zero error
    Nice use of default keyword for assignment and copy constructor

# Bin Implementation
Functionality

    All required functionality present and correct
    Nice addition of print function

Correctness

    Nice check for out of bounds error.
    Correct deep copy in copy constructor
    Correct allocation and deallocation of memory
    Good use of explicit keyword to force custom copy constructor

Testing

    Good thorough unit testing
    Excellent comparison against competition

Performance

    Correctly uses variable to store sqrt in unit vector calculation
    Good use of greedy allocator to avoid resizing the array too often
    Good note about storing as pointer to pointer, for large classes this 
    is a good optimisation.However, for smaller classes the extra cost of 
    indirection can bottleneck read times. (just food for thought, not marked)
    
Total: 19/20
