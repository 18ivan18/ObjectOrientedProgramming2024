#ifndef VECTOR
#define VECTOR

// dynamic array with a specified capacity and with certain number of elements (size)

// reason why the input argument for the array is of type int*&?
// create a header file with the declarations of the functions,
// move the definitions to a .cpp file
// show how they are used in main.cpp

// allocate the memory
void allocateMemory(int *&array, size_t capacity);

// delete the allocated memory
void freeMemory(int *&array, size_t &size, size_t &capacity);

// reallocate memory with different capacity
bool reallocateMemory(int *&array, size_t size, size_t newCapacity);

// resize the array, if necessary
// double the size
bool resize(int *&array, size_t size, size_t &capacity);

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool addElement(int *&array, size_t &size, size_t &capacity, int newElem);
// add element at a specified position of the array
// resize if necessary

bool addElement(int *&array, size_t &size, size_t &capacity, int newElem, size_t position);

// print the elements of the array
void print(const int *array, size_t size, size_t capacity);

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool removeElement(int *&array, size_t &size, size_t &capacity, size_t position);

#endif