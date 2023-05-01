#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

namespace ft {

/*=============================================================================
===  MEMBER FUNCTIONS                                                       ===
=============================================================================*/
template <typename T, typename A>
void vector<T, A>::assign(size_type count, const_reference value) {
    if (count <= _capacity) {
        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        for (size_type i = 0; i < count; i++)
            _allocator.construct(&_elements[i], value);
        _size = count;
    } else {
        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        _allocator.deallocate(_elements, _capacity);
        _elements = _allocator.allocate(count);
        for (size_type i = 0; i < count; i++)
            _allocator.construct(&_elements[i], value);
        _size = _capacity = count;
    }
    return ;
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::at(size_type index) {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::at(size_type index) const {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::back() {
    return _elements[_size - 1];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::back() const {
    return _elements[_size - 1];
};

template <typename T, typename A>
void vector<T, A>::clear() {
    for (size_type i = 0; i < _capacity; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _size = 0;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::capacity(void) const { return _capacity; };

template <typename T, typename A>
typename vector<T, A>::value_type* vector<T, A>::data() {
    return (&_elements[0]);
};

template <typename T, typename A>
const typename vector<T, A>::value_type* vector<T, A>::data() const {
    return (&_elements[0]);
};

template <typename T, typename A>
bool vector<T, A>::empty() const {
    if (_size == 0) return true;
    else return false;
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::front() {
    return _elements[0];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::front() const {
    return _elements[0];
};

template <typename T, typename A>
typename vector<T, A>::allocator_type vector<T, A>::get_allocator() const {
    return (_allocator);
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::max_size() const {
    return (_allocator.max_size());
};

template <typename T, typename A>
void vector<T, A>::pop_back() {
    _size--;
    return;
};

template <typename T, typename A>
void vector<T, A>::push_back(const_reference newElem) {
    if (!_capacity)
        reserve(1);
    if (_size == _capacity)
        reserve(_capacity * 2);
    _allocator.construct(&_elements[_size], newElem);
    _size++;
};

template <typename T, typename A>
void vector<T, A>::reserve(size_type newCapacity) {
    if (newCapacity <= _capacity) return;

    T *temp;

    temp = _allocator.allocate(newCapacity); // Allocate more (uninitialized) memory
    for (size_type i = 0; i < _size; i++) // Construct (initialize) allocated memory
        _allocator.construct(&temp[i], _elements[i]);
    for (size_type i = 0; i < _size; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _allocator.deallocate(_elements, _capacity);

    _capacity = newCapacity;
    _elements = temp;
};

template <typename T, typename A>
void vector<T, A>::resize(size_type newSize, value_type value) {
    size_type oldSize = _size;

    if (newSize > oldSize) {
        reserve(newSize);
        for (size_type i = oldSize; i < newSize; i++)
            _elements[i] = value;
    }
    else {
        for (size_type i = newSize; i < oldSize; i++)
            _allocator.destroy(&_elements[i]);
    }
    _size = newSize;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::size(void) const { return _size; };

template <typename T, typename A>
void vector<T, A>::swap(vector& other){
    if (this == &other) { return; };

    value_type* temp = _elements;
    size_type temp_size = _size;
    size_type temp_capacity = _capacity;

    _elements = other._elements;
    _size = other._size;
    _capacity = other._capacity;

    other._elements = temp;
    other._size = temp_size;
    other._capacity = temp_capacity;

    return ;
};

/*=============================================================================
===  CONSTRUCTION / DESTRUCTION                                             ===
=============================================================================*/
template <typename T, typename A>
vector<T, A>::vector(void) : _allocator(A()), _elements(NULL), _size(0), _capacity(0){};

template <typename T, typename A>
vector<T, A>::vector(const allocator_type& alloc) : _allocator(alloc), _elements(NULL), _size(0), _capacity(0) {};

template <typename T, typename A>
vector<T, A>::vector(size_type size, const_reference value, const allocator_type& allocator) {
    if (size > this->max_size())
        throw std::length_error("cannot create std::vector larger than max_size()");

    _size = size;
    _capacity = size;
    _allocator = allocator;

    T *temp = _allocator.allocate(_size);
    for (size_type i = 0; i < _size; i++) {
        _allocator.construct(&temp[i], value);
    }
    _elements = temp;
};

template <typename T, typename A>
vector<T, A>::vector(const vector &other) {
    _size = other._size;
    _capacity = other._size;

    T *temp = _allocator.allocate(_size);
    for (size_type i = 0; i < _size; i++) {
        _allocator.construct(&temp[i], other._elements[i]);
    }
    _elements = temp;

};

template <typename T, typename A>
vector<T, A>::~vector(void) {
    for (size_type i = 0; i < _size; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _allocator.deallocate(_elements, _capacity);
};

/*=============================================================================
===  OPERATOR OVERLOADS                                                     ===
=============================================================================*/
template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &other) {
    if (this == &other) return (*this);

    if (other._size <= _capacity) {
        for (size_type i = 0; i < other._size; i++) {
            _elements[i] = other[i];
            _size = other._size;
        }
    } else {
        T *tempElems = _allocator.allocate(other._size);
        for (size_type i = 0; i < other._size; i++) {
            _allocator.construct(&tempElems[i], other._elements[i]);
        }

        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        _allocator.deallocate(_elements, _capacity);

        _elements = tempElems;
    }
    _capacity = _size = other._size;

    return (*this);
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::operator[](size_type index) {
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::operator[](size_type index) const {
    return _elements[index];
};

/*=============================================================================
===  PRIVATE FUNCTIONS                                                      ===
=============================================================================*/
template <typename T, typename A>
std::string vector<T, A>::getOutOfRangeErrorMessage(size_type index) const {
    std::ostringstream oss;

    oss << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << _size << ")";

    return oss.str();
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
template< class T, class Alloc >
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    if (lhs.empty() && rhs.empty()) return true;

    if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity()) return false;

    for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++) {
        if (lhs.at(i) != rhs.at(i))
            return false;
    }

    return true;
};

}  // namespace ft

#endif