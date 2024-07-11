#include "bst.hh"
#include <iostream>

class Bst::Node {
public:
    Node(int v) : value_(v), left_(nullptr), right_(nullptr){};
    ~Node(){};
    Node *get_right(void) const;
    Node *get_left(void) const;
    int get_value(void) const;
    void set_value(int v);
    void print(void) const;
    void insert(int v);
    int erase(int v);

private:
    int value_;
    Node *left_;
    Node *right_;
};

Bst::~Bst() {
    while (head_ != nullptr) {
        (void)this->erase(head_->get_value());
    }
}
bool Bst::exist(int v) const {
    Node *node = head_;
    while (node != nullptr) {
        if (v > node->get_value()) {
            node = node->get_right();
        } else if (v < node->get_value()) {
            node = node->get_left();
        } else {
            return true;
        }
    }
    return false;
}
int Bst::findMin(void) const {
    Node *node = head_;
    while (node->get_left() != nullptr) {
        node = node->get_left();
    }
    return node->get_value();
}
int Bst::findMax(void) const {
    Node *node = head_;
    while (node->get_right() != nullptr) {
        node = node->get_right();
    }
    return node->get_value();
}
void Bst::print(void) const {
    if (head_ != nullptr) {
        head_->print();
        std::cout << std::endl;
    }
}
void Bst::insert(int v) {
    if (head_ == nullptr) {
        head_ = new Node(v);
    } else {
        head_->insert(v);
    }
}
bool Bst::erase(int v) {
    if (head_ != nullptr) {
        int ret = head_->erase(v);
        if (ret == 2) {
            Node *tmp = head_;
            if (head_->get_left() != nullptr) {
                head_ = head_->get_left();
            } else if (head_->get_right() != nullptr) {
                head_ = head_->get_right();
            } else {
                head_ = nullptr;
            }
            delete tmp; // free old head_ memory
            return true;
        } else {
            if (ret == 1) {
                return true;
            }
        }
    }
    return false;
}

Bst::Node *Bst::Node::get_right(void) const { return right_; }
Bst::Node *Bst::Node::get_left(void) const { return left_; }
int Bst::Node::get_value(void) const { return value_; }
void Bst::Node::set_value(int v) { value_ = v; }
void Bst::Node::print(void) const {
    std::cout << "(" << value_ << " l:";

    if (left_ != nullptr) {
        std::cout << " ";
        left_->print();
        std::cout << ", r:";
    } else {
        std::cout << "NULL, r:";
    }

    if (right_ != nullptr) {
        std::cout << " ";
        right_->print();
        std::cout << " ) ";
    } else {
        std::cout << "NULL ) ";
    }
}
void Bst::Node::insert(int v) {
    if (v < value_) {
        // Insert to the left
        if (left_ != nullptr) {
            // Subtree exists, delegate task to subtree's head
            left_->insert(v);
        } else {
            Node *node = new Node(v);
            left_ = node;
        }
    } else if (v > value_) {
        // Insert to the right
        if (right_ != nullptr) {
            // Subtree exists, delegate task to subtree's head
            right_->insert(v);
        } else {
            Node *node = new Node(v);
            right_ = node;
        }
    } else {
        // Value already exist, do not insert
    }
}
int Bst::Node::erase(int v) {
    if (v < value_) {
        if (left_ == nullptr) {
            return 0;
        }
        // Keep searching to the left
        int ret = left_->erase(v);
        if (ret == 2) {
            Node *tmp = left_;
            if (left_->get_left() != nullptr) {
                left_ = left_->get_left();
            } else if (left_->get_right() != nullptr) {
                left_ = left_->get_right();
            } else {
                left_ = nullptr;
            }
            delete tmp;
            ret = 1;
        }
        return ret;
    } else if ((v > value_)) {
        if (right_ == nullptr) {
            return 0;
        }
        // Keep searching to the right
        int ret = right_->erase(v);
        if (ret == 2) {
            Node *tmp = right_;
            if (right_->get_right() != nullptr) {
                right_ = right_->get_right();
            } else if (right_->get_left() != nullptr) {
                right_ = right_->get_left();
            } else {
                right_ = nullptr;
            }
            delete tmp;
            ret = 1;
        }
        return ret;
    } else {
        // Found!
        if ((left_ != nullptr) && (right_ != nullptr)) {
            /* Because the node to delete has 2 children, we'll change its value
            instead of deleting it, and delete the node used for the swap. This
            node is the smallest value in the right subtree */
            Node *child = right_;
            Node *parent = this;
            while (child->get_left() != nullptr) {
                parent = child;
                child = child->get_left();
            }
            // Swap values
            value_ = child->get_value();
            // Update parent's children links
            if (child->get_right() != nullptr) {
                if (parent == this) {
                    parent->right_ = child->get_right();
                } else {
                    parent->left_ = child->get_right();
                }
            } else {
                if (parent == this) {
                    parent->right_ = nullptr;
                } else {
                    parent->left_ = nullptr;
                }
            }
            delete child;
            return 1;
        } else {
            /* Process linkage and node deletion in parent node, or outside of
            this function if current node is the root node */
            return 2;
        }
    }
}
