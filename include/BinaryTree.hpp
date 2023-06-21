#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cstddef>

namespace ft {

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class BinaryTree {
   private:

    // template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
    template <class Type, class C = Compare, class A = Allocator >
    class BinaryTreeNode {
    public:
        A               _allocator;
        C               _compare;
        Type            _content;
        BinaryTreeNode  *_smaller;
        BinaryTreeNode  *_greater;
        BinaryTreeNode  *_parent;

    public:
        BinaryTreeNode(const Type &value, const C& comp = C(), const A& alloc = A()) : _allocator(alloc)
                                                                                    , _compare(comp)
                                                                                    , _content(value)
                                                                                    , _smaller(NULL)
                                                                                    , _greater(NULL)
                                                                                    , _parent(NULL) {};
        BinaryTreeNode(const BinaryTreeNode &other) : _allocator(other._allocator)
                                                    , _compare(other._compare)
                                                    , _content(other._content)
                                                    , _smaller(other._smaller)
                                                    , _greater(other._greater)
                                                    , _parent(other._parent) {};
        ~BinaryTreeNode() {};
        BinaryTreeNode &operator=(const BinaryTreeNode &other) {
            if (other != *this) {
                _allocator = other._allocator;
                _compare = other._compare;
                _content = other._content;
                _smaller = other._smaller;
                _greater = other._greater;
                _parent = other._parent;
            }
        };
    };

    Allocator                               _allocator;
    Compare                                 _compare;
    BinaryTreeNode<T, Compare, Allocator>   *_root;
    size_t                                  _size;
    size_t                                  _height;
    bool                                    _cleared;

    void _insertRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T &value, BinaryTreeNode<T, Compare, Allocator> *&parent);
    void _deleteRecursive(BinaryTreeNode<T, Compare, Allocator> *&current);
    bool _lookupRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T&value);
    void _inOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current);
    void _preOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current);
    void _postOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current);
    void _printTreeHelper(BinaryTreeNode<T, Compare, Allocator>* current, int level);

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    typedef Allocator allocator_type;
    typedef Compare key_compare;

    BinaryTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    BinaryTree(const BinaryTree &other);
    ~BinaryTree();
    BinaryTree &operator=(const BinaryTree &other);

    // Accessors
    size_t  getSize(void) const;
    size_t  getHeight(void) const;

    // Public function to print the tree
    void    printTree();

    // Modifiers
    void    insert(const T &newValue);
    void    clear(void);

    // Lookup
    bool    has(const T&value);

    // Element Access
    BinaryTreeNode<T, Compare, Allocator> *getNextNode(T searchValue);
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
// TODO: só vai sair quando tiver ITERADORES CARAI
// template <class T, class Compare, class Allocator>
// bool operator==(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator!=(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs);

}  // namespace ft

#include "BinaryTree.tpp"

#endif