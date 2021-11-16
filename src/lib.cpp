//
// Created by student on 16.11.21.
//
#include "../include/lib.h"
#include <cmath>
using namespace std;

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b){
    double odcinek_x, odcinek_y, wynik;
    odcinek_x = a.x - b.x;
    odcinek_y = a.y - b.y;
    wynik = pow((pow(odcinek_x,2)+pow(odcinek_y,2)),0.5);
            return wynik;
}