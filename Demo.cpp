/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>

#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main() {
    // print true/false not 1/0
    cout << boolalpha;

    Node<double> root_node = Node(1.1);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    {
        Tree<double> tree;  // Binary tree that contains doubles.
        tree.add_root(root_node);

        tree.add_sub_node(root_node, n1);
        tree.add_sub_node(root_node, n2);
        tree.add_sub_node(n1, n3);
        tree.add_sub_node(n1, n4);
        tree.add_sub_node(n2, n5);

        // The tree should look like:
        /**
         *       1.1
         *     /       \
         *    1.2      1.3
         *   /  \      /
         *  1.4  1.5  1.6
         */

        cout << "In order scan:\n";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
        cout << endl;

        cout << "Pre order scan:\n";
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
        cout << endl;

        cout << "Post order scan:\n";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
        cout << endl;

        cout << "BFS scan:\n";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            // cout << node->get_data() << ", ";
            cout << *node << ", ";
        }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
        cout << endl;

        cout << "DFS scan:\n";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
        cout << endl;

        for (auto node : tree) {
            cout << node << ", ";
        }  // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        /*
        cout << tree;  // Should print the graph using GUI.
        */
    }

    {
        Tree<double, 3> three_ary_tree;  // 3-ary tree.
        three_ary_tree.add_root(root_node);
        three_ary_tree.add_sub_node(root_node, n1);
        three_ary_tree.add_sub_node(root_node, n2);
        three_ary_tree.add_sub_node(root_node, n3);
        three_ary_tree.add_sub_node(n1, n4);
        three_ary_tree.add_sub_node(n2, n5);

        // The tree should look like:
        /**
         *       root = 1.1
         *     /      |     \
         *    1.2    1.3    1.4
         *   /        |
         *  1.5      1.6
         */

        cout << "DFS scan:\n";
        for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
        cout << endl;

        cout << "BFS scan:\n";
        for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node) {
            cout << node->get_data() << ", ";
        }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
        cout << endl;
    }
}