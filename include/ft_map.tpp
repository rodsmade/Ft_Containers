#ifndef FT_MAP_TPP
#define FT_MAP_TPP

#include "BinaryTree.hpp"

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/

// Modifiers:
// template <typename Key, typename T, typename Compare, typename Allocator>
// bool map<Key, T, Compare, Allocator>::insert(const value_type& value) {
    
//     _contents.insert(value);
// };

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc) {
    _contents = new BinaryTree<T>;
    (void) comp;
    (void) alloc;
};

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::~map() {
    delete _contents;
};

/*==============================================================================
===  OPERATOR OVERLOADS                                                      ===
==============================================================================*/

/*==============================================================================
===  PRIVATE FUNCTIONS                                                       ===
==============================================================================*/

/*=============================================================================
===  NON-MEMBER FUNCTIONS                                                   ===
=============================================================================*/
/*****************************************************************************/
/*   OPERATOR OVERLOADS                                                      */
/*****************************************************************************/

/*********************************************/
/*                  OTHER                    */
/*********************************************/

}  // namespace ft

#endif