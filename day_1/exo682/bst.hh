class Bst {
public:
    Bst() : head_(nullptr){};
    ~Bst();
    bool exist(int v) const;
    int findMin(void) const;
    int findMax(void) const;
    void print(void) const;
    void insert(int v);
    bool erase(int v);

private:
    class Node;
    Node *head_;
};
