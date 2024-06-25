# Tree iterators & GUI

In this assignment, we implemented a a tree iterator and a GUI for a tree data structure.

we use QT5 for the GUI. To compile with make file we use `qmake` to generate the make file.

## class hierarchy

we have 3 main classes:
1. Node: a class that represents a node in the tree. The class is templated to allow the user to store any type of data in the node, and it has a list of children nodes.
2. Tree: a class that represents a tree data structure. The class is templated to allow the user to store any type of data in the tree, and it has a root node.
3. Tree Iterators: a family of classes that allow the user to iterate over the nodes of the tree in different ways. The family includes:
    - in_order_iterator: an iterator that iterates over a binary tree in in-order traversal.
    - pre_order_iterator: an iterator that iterates over a binary tree in pre-order traversal.
    - post_order_iterator: an iterator that iterates over a binary tree in post-order traversal.
    - make_heap_iterator: an iterator that iterates over a binary tree in the order that the nodes are returned by the `make_heap` algorithm.
    - bfs_scan_iterator: an iterator that iterates over a tree in breadth-first search order.
    - dfs_scan_iterator: an iterator that iterates over a tree in depth-first search order.

So the tree class has a methods for `begin()` and `end()` to return the iterators.

For representing a binary tree we use template specialization of the tree class.

Using the tree class:
```cpp
Tree<int> tree; // create a binary tree of integers
Tree<int, 2> tree; // create a binary tree of integers
Tree<Complex, 3> tree; // create a ternary tree of complex numbers
```

We add a `Complex` class to represent complex numbers. the class have basic function like getters, `==` operator, `<` operator, `to_string` function, and `<<` operator.

> Although we dont define a total order for complex numbers, we define this an order based on the norm of the complex number. (This is the assignment requirement)

The CustomEllipseItem class help me display an ellipse with text inside when I hover on other items.

## Images:
The Tree GUI:
![alt text](/assets/tree.png)

The hover effect for long text:
![alt text](/assets/hover.png)

## usage
### run the program
```bash
qmake project.pro
make tree
```

### run the tests
```bash
cd tests
qmake tests.pro
make run
```