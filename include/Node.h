//
// Created by student on 16.11.21.
//

#ifndef LAB6_NODE_H
#define LAB6_NODE_H

class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node a, Node b);
};

double pointsDistance(Node a, Node b);



#endif //LAB6_NODE_H
