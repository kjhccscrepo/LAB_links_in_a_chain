#pragma once
template <typename T>
class Node {
private:
    const T* mydata;
    Node *child_node;
public:
    void makeParent(Node &child) {
        child_node = &child;
    }
    explicit Node (const T &elt) {
        mydata = &elt;
        child_node = nullptr;
    }
    explicit Node (const T &elt, Node *parent) {
        parent->makeParent(*this);
        mydata = &elt;
        child_node = nullptr;
    }
    Node next() {
        return *child_node;
    }
    T content() {
        return *mydata;
    }
};

