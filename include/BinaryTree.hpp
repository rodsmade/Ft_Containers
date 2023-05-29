#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cstddef>

namespace ft {

// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
template <class T>
class BinaryTreeNode {
   public:
    T               _content;
    BinaryTreeNode  *_smaller;
    BinaryTreeNode  *_greater;

   public:
    BinaryTreeNode(const T &value);
    BinaryTreeNode(const BinaryTreeNode &other);
    ~BinaryTreeNode();
    BinaryTreeNode &operator=(const BinaryTreeNode &other);
};

template <class T>
class BinaryTree {
   private:
    BinaryTreeNode<T>   *_root;
    size_t              _size;
    size_t              _height;
    bool                _cleared;

    void insertRecursive(BinaryTreeNode<T> *&current, const T &value);

    void deleteRecursive(BinaryTreeNode<T> *&current);

    // Helper function for printing the tree
    void printTreeHelper(BinaryTreeNode<T>* current, int level);

   public:
    BinaryTree();
    BinaryTree(const BinaryTree &other);
    ~BinaryTree();
    BinaryTree &operator=(const BinaryTree &other);

    // Accessors
    size_t  getSize(void) const;
    size_t  getHeight(void) const;

    // Public function to print the tree
    void printTree();

    // Modifiers
    void    insert(const T &newValue);
    void    clear(void);

    // Lookup
    bool    has(const T&value);
};

}  // namespace ft

#include "BinaryTree.tpp"

#endif