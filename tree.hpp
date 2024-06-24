// @author shay.gali@msmail.ariel.ac.il

#pragma once

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>

#include "CustomEllipseItem.hpp"
#include "node.hpp"
#include "tree_iterators.hpp"

template <typename T, int K = 2>
class Tree {
   private:
    Node<T>* root;

   public:
    Tree() : root(nullptr) {
    }

    /**
     * @brief Add a root to the tree. If a root already exists, it will be replaced.
     */
    void add_root(Node<T>* root) {
        this->root = root;
    }

    /**
     * @brief Get a node in the tree, and anthor node, and put the second node as a child of the first node.
     *
     * If the parent node already has a left child, the new node will be added as the right child (and can override the existing right child).
     * Else, the new node will be added as the left child.
     */

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_childrens().size() >= K) {
            throw std::runtime_error("Parent already has " + std::to_string(K) + " children, can't add more.");
        }
        parent->add_child(child);
    }

    ~Tree() {
        bfs_scan_iterator<T> it = begin_bfs_scan();
        bfs_scan_iterator<T> prev = it;
        bfs_scan_iterator<T> end = end_bfs_scan();
        while (it != end) {
            prev = it;
            ++it;
            prev->remove_children();
        }
        root = nullptr;
    }

    bfs_scan_iterator<T> begin() {
        return begin_bfs_scan();
    }

    bfs_scan_iterator<T> end() {
        return end_bfs_scan();
    }

    dfs_scan_iterator<T> begin_in_order() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_in_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_pre_order() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_pre_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_post_order() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_post_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

    bfs_scan_iterator<T> begin_bfs_scan() {
        return bfs_scan_iterator<T>(root);
    }

    bfs_scan_iterator<T> end_bfs_scan() {
        return bfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_dfs_scan() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_dfs_scan() {
        return dfs_scan_iterator<T>(nullptr);
    }

    // override the << operator
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
        tree.draw(300, 50);
        return os;
    }

    void draw(int x, int y, int circleSize = 75, int horizontalSpacing = 350, int verticalSpacing = 150) const {
        int argc = 0;
        char** argv = {nullptr};
        QApplication app(argc, argv);
        QGraphicsScene scene;
        QGraphicsView view(&scene);
        view.setBackgroundBrush(Qt::white);
        draw(&scene, root, x, y, circleSize, horizontalSpacing, verticalSpacing);

        view.show();

        app.exec();
    }

   private:
    void draw(QGraphicsScene* scene, Node<T>* node, int x, int y, int circleSize, int horizontalSpacing, int verticalSpacing, int depth = 0) const {
        if (!node) return;

        // Create and add the custom ellipse item to the scene
        CustomEllipseItem* ellipse = new CustomEllipseItem(x, y, circleSize, circleSize, QString::fromStdString(node->to_str()));
        scene->addItem(ellipse);

        QGraphicsTextItem* text = scene->addText(QString::fromStdString(node->to_short_string()));
        text->setPos(x + circleSize / 2 - text->boundingRect().width() / 2, y + circleSize / 2 - text->boundingRect().height() / 2);

        // More aggressive adjustment for horizontal spacing based on depth
        int depthFactor = std::pow(2, depth);                                                   // Exponential growth factor
        int adjustedHorizontalSpacing = std::max(horizontalSpacing / depthFactor, circleSize);  // Ensure spacing doesn't become too small

        int childX = x - (node->get_childrens().size() - 1) * adjustedHorizontalSpacing / 2;
        for (Node<T>* child : node->get_childrens()) {
            if (child == nullptr) {
                childX += adjustedHorizontalSpacing;
                continue;
            }
            // Draw the line between the parent and the child
            scene->addLine(x + circleSize / 2, y + circleSize, childX + circleSize / 2, y + verticalSpacing, QPen(Qt::black));
            // Recursively draw child nodes with more aggressively adjusted spacing
            draw(scene, child, childX, y + verticalSpacing, circleSize, horizontalSpacing, verticalSpacing, depth + 1);
            childX += adjustedHorizontalSpacing;
        }
    }
};

// specializations for K = 2
template <typename T>
class Tree<T, 2> {
   private:
    Node<T>* root;

   public:
    Tree() : root(nullptr) {
    }

    void add_root(Node<T>* root) {
        this->root = root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_childrens().size() >= 2) {
            throw std::runtime_error("Parent already has 2 children, can't add more.");
        }
        parent->add_child(child);
    }

    ~Tree() {
        bfs_scan_iterator<T> it = begin_bfs_scan();
        bfs_scan_iterator<T> prev = it;
        bfs_scan_iterator<T> end = end_bfs_scan();
        while (it != end) {
            prev = it;
            ++it;
            prev->remove_children();
        }
        root = nullptr;
    }

    bfs_scan_iterator<T> begin() {
        return begin_bfs_scan();
    }

    bfs_scan_iterator<T> end() {
        return end_bfs_scan();
    }

    in_order_iterator<T> begin_in_order() {
        return in_order_iterator<T>(root);
    }

    in_order_iterator<T> end_in_order() {
        return in_order_iterator<T>(nullptr);
    }

    pre_order_iterator<T> begin_pre_order() {
        return pre_order_iterator<T>(root);
    }

    pre_order_iterator<T> end_pre_order() {
        return pre_order_iterator<T>(nullptr);
    }

    post_order_iterator<T> begin_post_order() {
        return post_order_iterator<T>(root);
    }

    post_order_iterator<T> end_post_order() {
        return post_order_iterator<T>(nullptr);
    }

    bfs_scan_iterator<T> begin_bfs_scan() {
        return bfs_scan_iterator<T>(root);
    }

    bfs_scan_iterator<T> end_bfs_scan() {
        return bfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_dfs_scan() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_dfs_scan() {
        return dfs_scan_iterator<T>(nullptr);
    }

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
        tree.draw(300, 50);
        return os;
    }

    void draw(int x, int y, int circleSize = 75, int horizontalSpacing = 350, int verticalSpacing = 150) const {
        int argc = 0;
        char** argv = {nullptr};
        QApplication app(argc, argv);
        QGraphicsScene scene;
        QGraphicsView view(&scene);
        view.setBackgroundBrush(Qt::white);
        draw(&scene, root, x, y, circleSize, horizontalSpacing, verticalSpacing);

        view.show();

        app.exec();
    }

   private:
    void draw(QGraphicsScene* scene, Node<T>* node, int x, int y, int circleSize, int horizontalSpacing, int verticalSpacing, int depth = 0) const {
        if (!node) return;

        // Create and add the custom ellipse item to the scene
        CustomEllipseItem* ellipse = new CustomEllipseItem(x, y, circleSize, circleSize, QString::fromStdString(node->to_str()));
        scene->addItem(ellipse);

        QGraphicsTextItem* text = scene->addText(QString::fromStdString(node->to_short_string()));
        text->setPos(x + circleSize / 2 - text->boundingRect().width() / 2, y + circleSize / 2 - text->boundingRect().height() / 2);

        // More aggressive adjustment for horizontal spacing based on depth
        int depthFactor = std::pow(2, depth);                                                   // Exponential growth factor
        int adjustedHorizontalSpacing = std::max(horizontalSpacing / depthFactor, circleSize);  // Ensure spacing doesn't become too small

        int childX = x - (node->get_childrens().size() - 1) * adjustedHorizontalSpacing / 2;
        for (Node<T>* child : node->get_childrens()) {
            if (child == nullptr) {
                childX += adjustedHorizontalSpacing;
                continue;
            }
            // Draw the line between the parent and the child
            scene->addLine(x + circleSize / 2, y + circleSize, childX + circleSize / 2, y + verticalSpacing, QPen(Qt::black));
            // Recursively draw child nodes with more aggressively adjusted spacing
            draw(scene, child, childX, y + verticalSpacing, circleSize, horizontalSpacing, verticalSpacing, depth + 1);
            childX += adjustedHorizontalSpacing;
        }
    }
};