#include <iostream>

/* Classes ********************************************************************/
class Node {
public:
    Node(int v) : value(v), next(nullptr), prev(nullptr){};
    ~Node(){};
    int get_val(void) const;
    void set_val(int v);
    Node *get_next(void) const;
    void set_next(Node *n);
    Node *get_prev(void) const;
    void set_prev(Node *n);

private:
    int value;
    Node *next;
    Node *prev;
};

class List {
public:
    List() : head(nullptr), tail(nullptr), len(0){};
    ~List(); // Must free all allocated memory
    void push_front(int i);
    void push_back(int i);
    int pop_front(void);
    int pop_back(void);
    void print(void) const;
    int get_length(void) const;

private:
    int len;    // Number of nodes
    Node *head; // Front of the list
    Node *tail; // End of the list
};

/* Function Definitions *******************************************************/
int main(void) {
    List l;

    l.push_back(13);
    l.print();
    l.push_front(5);
    l.print();
    l.push_back(42);
    l.print();
    l.pop_back();
    l.print();
    l.push_back(42);
    l.print();
    l.pop_front();
    l.print();

    std::cout << "Number of elements: " << l.get_length() << std::endl;
}

// Definitions for class Node
int Node::get_val(void) const { return value; }
void Node::set_val(int v) { value = v; }
Node *Node::get_next(void) const { return next; }
void Node::set_next(Node *n) { next = n; }
Node *Node::get_prev(void) const { return prev; }
void Node::set_prev(Node *n) { prev = n; }

// Definitions for class List
List::~List() {
    Node *node = head;
    Node *tmp = nullptr;

    while (node != nullptr) {
        tmp = node->get_next();
        delete node;
        node = tmp;
    }
}
void List::push_front(int i) {
    Node *new_node = new Node(i);

    if (head != nullptr) {
        new_node->set_next(head);
        head->set_prev(new_node);
    } else {
        tail = new_node;
    }
    head = new_node;

    len++;
}
void List::push_back(int i) {
    Node *new_node = new Node(i);

    if (tail != nullptr) {
        new_node->set_prev(tail);
        tail->set_next(new_node);
    } else {
        head = new_node;
    }
    tail = new_node;

    len++;
}
int List::pop_front(void) {
    int i = 0;
    if (head != nullptr) {
        Node *node = head;

        i = head->get_val();
        head = head->get_next();
        head->set_prev(nullptr);
        delete node;

        len--;
    }
    return i;
}
int List::pop_back(void) {
    int i = 0;
    if (tail != nullptr) {
        Node *node = tail;

        i = tail->get_val();
        tail = tail->get_prev();
        tail->set_next(nullptr);
        delete node;

        len--;
    }
    return i;
}
void List::print(void) const {
    Node *node = head;
    while (node != nullptr) {
        std::cout << node->get_val() << ", ";
        node = node->get_next();
    }
    std::cout << std::endl;
}
int List::get_length(void) const { return len; }
