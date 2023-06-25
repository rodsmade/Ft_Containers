#include <iostream>

namespace ft {
template <typename T>
class BinaryTree {
   private:
    // Prototypes
    template <typename U>
    class BinaryTreeNode;

    template <typename V>
    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode<V>& node);

    // Implementation
    template <typename U>
    class BinaryTreeNode {
       private:
        // Prototypes
        friend class BinaryTree<U>;

        // Private members
        U _content;
        BinaryTreeNode* _smaller;
        BinaryTreeNode* _greater;

       public:
        BinaryTreeNode(U content = U(), BinaryTreeNode* smaller = NULL, BinaryTreeNode* greater = NULL) : _content(content), _smaller(smaller), _greater(greater){};
        ~BinaryTreeNode(){};
        BinaryTreeNode(const BinaryTreeNode& other) {
            _content = U(other._content);
            _smaller = other._smaller;
            _greater = other._greater;
        };

        BinaryTreeNode<U>& operator=(const BinaryTreeNode& other) {
            if (*this != other) {
                _content = other._content;
                _smaller = other._smaller;
                _greater = other._greater;
            }
            return (*this);
        }

        bool operator==(const BinaryTreeNode<U>& rhs) {
            return (this->_content == rhs._content && this->_smaller == rhs._smaller && this->_greater == rhs._greater);
        }

        bool operator!=(const BinaryTreeNode<U>& rhs) {
            return !(*this == rhs);
        }
    };

    // Attributes
    BinaryTreeNode<T>* _root;
    size_t _size;

    // Private member functions
    void _insert_recursively(const T& value, BinaryTreeNode<T>*& current_node) {
        if (current_node == NULL) {
            current_node = new BinaryTreeNode<T>(value);
            _size++;
        } else if (current_node->_content < value) {
            _insert_recursively(value, current_node->_greater);
        } else if (current_node->_content > value) {
            _insert_recursively(value, current_node->_smaller);
        }
    };
    void _delete_in_post_order_traversal(BinaryTreeNode<T>* current_node) {
        if (current_node) {
            _delete_in_post_order_traversal(current_node->_smaller);
            _delete_in_post_order_traversal(current_node->_greater);
            delete current_node;
        }
    };
    BinaryTreeNode<T>* _copy_nodes_in_pre_order_traversal(BinaryTreeNode<T>* current_node) {
        if (current_node) {
            BinaryTreeNode<T>* new_node = new BinaryTreeNode<T>(current_node->_content);
            new_node->_smaller = _copy_nodes_in_pre_order_traversal(current_node->_smaller);
            new_node->_greater = _copy_nodes_in_pre_order_traversal(current_node->_greater);
            return new_node;
        }
        return (NULL);
    };
    void _print_tree_helper(BinaryTreeNode<T>* current_node, int level) {
        if (current_node == NULL) {
            for (int i = 0; i < level; i++) {
                std::cout << "\t";
            }

            std::cout << "🍃" << std::endl;
            return;
        }

        _print_tree_helper(current_node->_greater, level + 1);

        for (int i = 0; i < level; i++) {
            std::cout << "\t";
        }

        std::cout << current_node->_content << std::endl;
        // if (current_node->_parent)
        //     std::cout << current_node->_parent->_content << "/" << current_node->_content << std::endl;
        // else
        //     std::cout << "NULL"
        //               << "/" << current_node->_content << std::endl;

        _print_tree_helper(current_node->_smaller, level + 1);
    }

   public:
    BinaryTree() : _root(NULL), _size(0) {
        std::cout << "Default constructor\n";
    }
    BinaryTree(T value) {
        std::cout << "Value constructor\n";
        _root = new BinaryTreeNode<T>(value);
        _size = 1;
    }
    BinaryTree(const BinaryTree<T>& other) {
        _root = _copy_nodes_in_pre_order_traversal(other._root);
        _size = other._size;
    };
    ~BinaryTree() {
        if (_root)
            _delete_in_post_order_traversal(_root);
    };
    void insert(const T& value) {
        _insert_recursively(value, _root);
    };
    void printTree() {
        _print_tree_helper(_root, 0);
    };
    size_t getSize(void) { return this->_size; };
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const typename BinaryTree<V>::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

int main() {
    ft::BinaryTree<int> teste;
    teste.insert(1);
    teste.insert(2);
    teste.insert(3);
    ft::BinaryTree<int> teste2(42);
    teste2.insert(43);
    teste2.insert(44);
    teste2.insert(45);
    ft::BinaryTree<int> teste3(teste2);
    // ft::BinaryTree<int> teste4;
    // teste4 = teste;

    teste.insert(6);
    teste.insert(5);
    teste.insert(4);
    teste2.insert(41);
    teste2.insert(40);

    std::cout << "\nTeste 1: (size: " << teste.getSize() << ")\n";
    teste.printTree();

    std::cout << "\nTeste 2: (size: " << teste2.getSize() << ")\n";
    teste2.printTree();
    std::cout << "\nTeste 3: (size: " << teste3.getSize() << ")\n";
    teste3.printTree();
    // std::cout << "\nTeste 4: (size: " << teste4.getSize() << ")\n";
    // teste4.printTree();
}

// int main() {
//     ft::BinaryTreeNode<std::string> node2("DOIS");
//     ft::BinaryTreeNode<std::string> node3("TRES");
//     ft::BinaryTreeNode<std::string> node1("UM", &node2, &node3);
//     ft::BinaryTreeNode<std::string> node4(node1);
//     ft::BinaryTreeNode<std::string> node5;
//     node5 = node1;
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
//
//     node1 = ft::BinaryTreeNode<std::string>("NOVO UM");
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
// }
