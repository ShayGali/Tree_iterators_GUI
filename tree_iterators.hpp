#pragma once

#include <queue>
#include <stack>
#include <vector>

#include "node.hpp"

using std::queue;
using std::stack;
using std::vector;

template <typename T>
class in_order_iterator {
   private:
    stack<Node<T>*> stck;

   public:
    in_order_iterator(Node<T>* root) {
        stck.push(nullptr);
        while (root != nullptr) {
            stck.push(root);
            if (root->get_childrens().size() > 0 && root->get_childrens().at(0) != nullptr) {
                root = root->get_childrens().at(0);
            } else {
                root = nullptr;
            }
        }
    }

    T& operator*() { return stck.top()->get_data(); }
    Node<T>* operator->() { return stck.top(); }

    in_order_iterator& operator++() {
        Node<T>* node = stck.top();
        stck.pop();
        if (node->get_childrens().size() > 1 && node->get_childrens().at(1) != nullptr) {
            Node<T>* right_child = node->get_childrens().at(1);
            stck.push(right_child);
            // push all the left children of the right child
            Node<T>* right_child_left_child = right_child;
            while (right_child_left_child->get_childrens().size() > 0 && right_child_left_child->get_childrens().at(0) != nullptr) {
                right_child_left_child = right_child_left_child->get_childrens().at(0);
                stck.push(right_child_left_child);
            }
        }
        return *this;
    }

    bool operator==(const in_order_iterator& other) const { return stck.top() == other.stck.top(); }
    bool operator!=(const in_order_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class pre_order_iterator {
   private:
    stack<Node<T>*> stck;

   public:
    pre_order_iterator(Node<T>* root) {
        stck.push(nullptr);
        stck.push(root);
    }

    T& operator*() { return stck.top()->get_data(); }

    Node<T>* operator->() { return stck.top(); }

    pre_order_iterator& operator++() {
        Node<T>* node = stck.top();
        stck.pop();
        // push the right child first, and then the left child (if exists)
        if (node->get_childrens().size() > 1 && node->get_childrens().at(1) != nullptr) {
            stck.push(node->get_childrens().at(1));
        }
        if (node->get_childrens().size() > 0 && node->get_childrens().at(0) != nullptr) {
            stck.push(node->get_childrens().at(0));
        }
        return *this;
    }

    bool operator==(const pre_order_iterator& other) const {
        return stck.top() == other.stck.top();
    }

    bool operator!=(const pre_order_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class post_order_iterator {
   private:
    vector<Node<T>*> post_order;
    int index;

   public:
    post_order_iterator(Node<T>* root) {
        index = 0;
        if (root == nullptr) {
            return;
        }
        stack<Node<T>*> stck;
        stck.push(root);
        Node<T>* prev = nullptr;
        while (!stck.empty()) {
            Node<T>* current = stck.top();
            // if we are going down the tree
            if (prev == nullptr || (prev->get_childrens().size() > 0 && prev->get_childrens().at(0) == current) || (prev->get_childrens().size() > 1 && prev->get_childrens().at(1) == current)) {
                if (current->get_childrens().size() > 0 && current->get_childrens().at(0) != nullptr) {         // has left child
                    stck.push(current->get_childrens().at(0));                                                  // go left
                } else if (current->get_childrens().size() > 1 && current->get_childrens().at(1) != nullptr) {  // has right child
                    stck.push(current->get_childrens().at(1));                                                  // go right
                } else {                                                                                        // leaf
                    post_order.push_back(current);
                    stck.pop();
                }
                // if we are going up the tree from left child
            } else if (current->get_childrens().size() > 0 && prev == current->get_childrens().at(0)) {
                if (current->get_childrens().size() > 1 && current->get_childrens().at(1) != nullptr) {  // has right child
                    stck.push(current->get_childrens().at(1));
                } else {
                    post_order.push_back(current);
                    stck.pop();
                }
                // if we are going up the tree from right child
            } else if (current->get_childrens().size() > 1 && prev == current->get_childrens().at(1)) {
                post_order.push_back(current);
                stck.pop();
            }
            prev = current;
        }
    }

    T& operator*() { return post_order[index]->get_data(); }
    Node<T>* operator->() { return post_order[index]; }

    post_order_iterator& operator++() {
        index++;
        return *this;
    }

    bool operator==(const post_order_iterator& other) const { return post_order.size() - index == other.post_order.size() - other.index; }
    bool operator!=(const post_order_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class bfs_scan_iterator {
   private:
    queue<Node<T>*> q;

   public:
    bfs_scan_iterator(Node<T>* root) {
        if (root == nullptr) {
            return;
        }

        q.push(root);
    }

    T operator*() { return q.front()->get_data(); }
    Node<T>* operator->() { return q.front(); }

    bfs_scan_iterator& operator++() {
        Node<T>* node = q.front();
        q.pop();
        for (auto child : node->get_childrens()) {
            if (child != nullptr) {
                q.push(child);
            }
        }
        return *this;
    }

    bool operator==(const bfs_scan_iterator& other) const { return q.size() == other.q.size(); }
    bool operator!=(const bfs_scan_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class dfs_scan_iterator {
   private:
    stack<Node<T>*> stck;

   public:
    dfs_scan_iterator(Node<T>* root) {
        if (root == nullptr) {
            return;
        }

        stck.push(root);
    }

    T& operator*() { return stck.top()->get_data(); }
    Node<T>* operator->() { return stck.top(); }

    dfs_scan_iterator& operator++() {
        Node<T>* node = stck.top();
        stck.pop();
        for (int i = node->get_childrens().size() - 1; i >= 0; i--) {
            if (node->get_childrens().at(i) != nullptr) {
                stck.push(node->get_childrens().at(i));
            }
        }
        return *this;
    }

    bool operator==(const dfs_scan_iterator& other) const { return stck.size() == other.stck.size(); }
    bool operator!=(const dfs_scan_iterator& other) const {
        return !(*this == other);
    }
};
