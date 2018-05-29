/* 
 * File:   node.h
 * Author: skonjp
 *
 * Created on August 21, 2017, 10:33 AM
 */

#ifndef NODE_H
#define NODE_H

using namespace std;
static int trans1[] = {0, 1, -1, 2, -2, 3};
static int trans2[] = {0, 1, 2, -2, 3};

static int DIVIDEFACTOR = 4;

class node {
public:
    node();
    node(int x, int y, int level, int n0 = -1, int n1 = -1);
    node(const node& orig);
    node(const node& orig, int i);
    virtual ~node();

    // add level just before last level;
    void addLevel(int l);

    vector<int> getSig();

    void displaySig();
    void display();
    void nextNode(int n0 = -1, int n1 = -1);
    void updateSigLast(int v);
    
    int getX();
    int getY();
    void computeP2(node n1, node n2);
    void computeP3(node n1, node n2);
    void computeP4(node n1, node n2);
    void computeP5(node n1, node n2);



private:

    vector<int> signature;
    int index;
    int x, y;
    int color;
    int next[2];

};

#endif /* NODE_H */

