#include <iostream>
#include <string>

#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Node<int> root(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);
    Node<int> n6(6);
    Node<int> n7(7);
    
    Tree<int, 2> tree;
    tree.add_root(&root);

    tree.add_sub_node(&root, &n2);
    tree.add_sub_node(&root, &n3);
    tree.add_sub_node(&n2, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n3, &n6);
    tree.add_sub_node(&n6, nullptr);
    tree.add_sub_node(&n6, &n7);
    /*
    tree shuld look like this:
            1
           /  \
          2    3
         / \    \
        4   5    6
                 / \
                n   7
    */

    int expected[] = {4, 2, 5, 1, 6, 7, 3};
    int i = 0;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node, ++i) {
        cout << (node->get_data() == expected[i]) << endl;
    }

    // Node<double> root = Node(1.1);
    // Node<double> n1 = Node(1.2);
    // Node<double> n2 = Node(1.3);
    // Node<double> n3 = Node(1.4);
    // Node<double> n4 = Node(1.5);
    // Node<double> n5 = Node(1.6);

    // {
    //     Tree<double, 2> tree;
    //     tree.add_root(&root);

    //     tree.add_sub_node(&root, &n1);
    //     tree.add_sub_node(&root, &n2);
    //     tree.add_sub_node(&n1, &n3);
    //     tree.add_sub_node(&n1, &n4);

    //     // &cout << "For each scan:\n";
    //     // for (auto node : tree) {
    //     //     cout << node << ", ";
    //     // }  // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    //     // cout << "In order scan:\n";
    //     // for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
    //     //     cout << node->get_data() << ", ";
    //     // }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    //     // cout << endl;

    //     // // cout << "DFS scan:\n";
    //     // // for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
    //     // //     cout << node->get_data() << ", ";
    //     // // }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    //     // cout << endl;
    //     // tree.draw(300, 50);  // Starting position of the root
    // }

    // {
    //     Tree<double, 3> three_ary_tree;  // 3-ary tree.
    //     three_ary_tree.add_root(&root);
    //     three_ary_tree.add_sub_node(&root, &n1);
    //     three_ary_tree.add_sub_node(&root, &n2);
    //     three_ary_tree.add_sub_node(&root, &n3);
    //     three_ary_tree.add_sub_node(&n1, &n4);
    //     three_ary_tree.add_sub_node(&n2, &n5);

    //     cout << three_ary_tree;
    // }

    // {
    //     Node<string> root("Shay");
    //     Node<string> r1_1("Shalom");
    //     Node<string> r1_2("Gali");
    //     Node<string> r2_1_1("HOIIII");
    //     Node<string> r2_1_2("MICHAELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL");

    //     Tree<string> s_tree;
    //     s_tree.add_root(&root);
    //     s_tree.add_sub_node(&root,& r1_1);
    //     s_tree.add_sub_node(&root,& r1_2);
    //     s_tree.add_sub_node(&r1_1,& r2_1_1);
    //     s_tree.add_sub_node(&r1_1,& r2_1_2);

    //     cout << s_tree;
    // }

    // {
    //     // complex tree
    //     Node<Complex> root(Complex(1.1, 1.1));
    //     Node<Complex> n1(Complex(1.2, 1.2));
    //     Node<Complex> n2(Complex(1.3, 1.3));
    //     Node<Complex> n3(Complex(1.4, 1.4));
    //     Node<Complex> n4(Complex(1.5, 1.5));
    //     Node<Complex> n5(Complex(1.6, 1.6));
    //     Node<Complex> n6(Complex(1.7, 1.7));
    //     Node<Complex> n7(Complex(1.8, 1.8));

    //     Tree<Complex, 4> complex_tree;
    //     complex_tree.add_root(&root);
    //     complex_tree.add_sub_node(&root, &n1);
    //     complex_tree.add_sub_node(&root, &n2);
    //     complex_tree.add_sub_node(&root, &n3);
    //     complex_tree.add_sub_node(&n1, &n4);
    //     complex_tree.add_sub_node(&n1, &n5);
    //     complex_tree.add_sub_node(&n2, &n6);
    //     complex_tree.add_sub_node(&n2, &n7);
    //     complex_tree.draw(300, 50);  // Starting position of the root
    // }

    return 0;
}