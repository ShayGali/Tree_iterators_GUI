#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../complex.hpp"
#include "../node.hpp"
#include "../tree.hpp"

using std::cout;
using std::endl;

TEST_CASE("in order") {
    Node<int> root(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);
    Node<int> n6(6);
    Node<int> n7(7);

    SUBCASE("binary tree") {
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
            CHECK(node->get_data() == expected[i]);
        }

        cout << tree;
    }
}