#include "ft_vector.hpp"

namespace ft {

// __ MEMBER FUNCTIONS ________________________________________________________
unsigned int Vector::size(void) const { return _size; };

unsigned int Vector::capacity(void) const { return _capacity; };

void Vector::resize(unsigned int newCapacity) {
    if (newCapacity <= _capacity) return ;
    _capacity = newCapacity;
    double *temp = new double[_capacity];
    for (unsigned int i = 0; i < _size; i++)
        temp[i] = _elements[i];
    delete[] _elements;
    _elements = temp;
};

void Vector::test(void) {
    std::cout << "calling Map member function, test " << BOLD LIGHT_GREEN "OK" RESET << std::endl;
};

void Vector::printAll(void) {
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _elements[i] << std::endl;
};

// __ CONSTRUCTION/DESTRUCTION ________________________________________________
Vector::Vector(void) : _elements(nullptr), _size(0), _capacity(0) {};

// TODO: e se size for < 0
Vector::Vector(int size) : _elements(new double[size]), _size(size), _capacity(size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = 0;
};

Vector::Vector(const Vector&other) : _elements(new double[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
};

Vector::~Vector(void) {
    delete[] _elements;
};

// __ OPERATOR OVERLOADS ______________________________________________________
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        double *tempElems = new double[other._size];
        for (unsigned int i = 0; i < other._size; i++) {
            tempElems[i] = other._elements[i];
        }

        delete[] _elements;
        _elements = tempElems;
        _size = other._size;
    }
    return (*this);
};

double &Vector::operator[](int index) { // for non-const Vectors
    return _elements[index];
};

const double &Vector::operator[](int index) const { // for const Vectors
    return _elements[index];
};

}  // namespace ft
