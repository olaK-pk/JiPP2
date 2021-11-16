//
// Created by student on 16.11.21.
//

#ifndef LAB6_LIB_H
#define LAB6_LIB_H
#include <iostream>

using namespace std;



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

#endif //LAB6_LIB_H