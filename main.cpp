#include <algorithm>
#include <iostream>
#include <string>

#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Node<int> nodes[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    Tree<int, 2> tree;

    tree.add_root(&nodes[0]);

    for (int i = 1; i < 15; i++) {
        tree.add_sub_node(&nodes[(i - 1) / 2], &nodes[i]);
    }

    cout << "BFS scan:\n";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << it->get_data() << " ";
    }
    cout << endl;

    cout << "in-order scan:\n";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << it->get_data() << " ";
    }
    cout << endl;

    cout << tree;

    {
        Node<string> root("Shay");
        Node<string> r1_1("Shalom");
        Node<string> r1_2("Gali");
        Node<string> r2_1_1("HOIIII");
        Node<string> r2_1_2("MICHAELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL");

        Tree<string> s_tree;
        s_tree.add_root(&root);
        s_tree.add_sub_node(&root, &r1_1);
        s_tree.add_sub_node(&root, &r1_2);
        s_tree.add_sub_node(&r1_1, &r2_1_1);
        s_tree.add_sub_node(&r1_1, &r2_1_2);

        cout << s_tree;
    }

    {
        // complex tree
        Node<Complex> root(Complex(0, 1.1));
        Node<Complex> n1(Complex(-1.2, -1.2));
        Node<Complex> n2(Complex(0.3, -1.3));
        Node<Complex> n3(Complex(1.4, 1.4));
        Node<Complex> n4(Complex(-3.5, 1.5));
        Node<Complex> n5(Complex(1.6, 0));
        Node<Complex> n6(Complex(1.7, 1));
        Node<Complex> n7(Complex(1.8, 1.8));

        Tree<Complex, 4> complex_tree;
        complex_tree.add_root(&root);
        complex_tree.add_sub_node(&root, &n1);
        complex_tree.add_sub_node(&root, &n2);
        complex_tree.add_sub_node(&root, &n3);
        complex_tree.add_sub_node(&n1, &n4);
        complex_tree.add_sub_node(&n1, &n5);
        complex_tree.add_sub_node(&n2, &n6);
        complex_tree.add_sub_node(&n2, &n7);

        cout << "DFS scan:\n";
        for (auto it = complex_tree.begin_dfs_scan(); it != complex_tree.end_dfs_scan(); ++it) {
            cout << *it << "\n";
        }
        cout << endl;

        complex_tree.draw(300, 50);  // Starting position of the root
    }
    /*
     */

    return 0;
}