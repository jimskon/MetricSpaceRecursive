/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.cpp
 * Author: skonjp
 * 
 * Created on August 21, 2017, 10:33 AM
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <math.h> 
#include <map>
#include <algorithm>
#include "node.h"

node::node() {
}

node::node(int x, int y, int level, int n0, int n1) {
    this->x = x;
    this->y = y;
    this->signature.push_back(level);
    color = 0xFFF;
    next[0] = n0;
    next[1] = n1;

}

node::node(const node& orig) {
    (*this) = orig;
}

node::node(const node& orig, int i) {
    (*this) = orig;
    signature.push_back(trans2[i]);
}

node::~node() {
}

void node::displaySig() {
    cout << "(";
    int len = signature.size();
    for (int i = 0; i < len; i++) {
        cout << signature[i];
        if (i < len - 1) {
            cout << ",";
        }
    }
    cout << ")";
}

void node::display() {
    displaySig();
    cout << " (" << x << "," << y << ") ";
//    if (next[0]>-1) {
//        cout << "Next=" << next[0];
//        if (next[1]>-1) {
//            cout << ", " << next[1];
//        }
//    }
}

void node::nextNode(int n0, int n1) {
    next[0] = n0;
    next[1] = n1;
}

void node::addLevel(int newL) {
    signature.push_back(newL);
}

vector<int> node::getSig() {
    return signature;
}

void node::updateSigLast(int v) {
    signature.pop_back();
    signature.push_back(v);
}

int node::getX() {
    return x;
}

int node::getY() {
    return y;
}

void node::computeP2(node n1, node n2) {
    x = (3 * n1.x + n2.x) / 4;
    y = (3 * n1.y + n2.y) / 4;
}

void node::computeP3(node n1, node n2) {
    x = (n1.x + n2.x) / 2 + abs(n2.y - n1.y) / DIVIDEFACTOR;
    y = (n1.y + n2.y) / 2 - abs(n2.x - n1.x) / DIVIDEFACTOR;
}

void node::computeP4(node n1, node n2) {
    x = (n1.x + n2.x) / 2 - abs(n2.y - n1.y) / DIVIDEFACTOR;
    y = (n1.y + n2.y) / 2 + abs(n2.x - n1.x) / DIVIDEFACTOR;
}

void node::computeP5(node n1, node n2) {
    x = (n1.x + 3 * n2.x) / 4;
    y = (n1.y + 3 * n2.y) / 4;
}

