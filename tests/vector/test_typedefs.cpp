#include "vector_tests.hpp"

void test_vector_typedefs(void) {
    std::cout << "\n=== Typedefs comparison ===" << std::endl;
    my_assert(is_same<ft::vector<int>::size_type, std::vector<int>::size_type>::value, "size_type");
    my_assert(is_same<ft::vector<int>::value_type, std::vector<int>::value_type>::value, "value_type");
    my_assert(is_same<ft::vector<int>::reference, std::vector<int>::reference>::value, "reference");
    my_assert(is_same<ft::vector<int>::const_reference, std::vector<int>::const_reference>::value, "const_reference");
    // my_assert(is_same<ft::vector<int>::iterator, std::vector<int>::iterator>::value, "iterator");
    // my_assert(is_same<ft::vector<int>::const_iterator, std::vector<int>::const_iterator>::value, "const_iterator");
    // my_assert(is_same<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator>::value, "reverse_iterator");
    // my_assert(is_same<ft::vector<int>::const_reverse_iterator, std::vector<int>::const_reverse_iterator>::value, "const_reverse_iterator");
    // TODO: os outros typedefs que não tão aqui 
}