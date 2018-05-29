#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <math.h> 
#include <map>
#include <algorithm>
#include "node.h"

using namespace std;



void listNodes(vector<node> graph) {
    int len = graph.size();
    cout << len << " nodes" << endl;
    for (int i = 0; i < len; i++) {
        cout << i << ". ";
        graph.at(i).display();
        cout << endl;
    }
}

void addGroup(node current, node next, vector<node> &newGraph) {
    int nodeLoc = newGraph.size();
    for (int y = 0; y < 5; y++) {
        node aNode = node(current, y);
        switch (y) {
            case 0:
                //aNode.nextNode(nodeLoc + 1);
                break;
            case 1:
                //aNode.nextNode(nodeLoc + 2, nodeLoc + 3);
                aNode.computeP2(current,next);
                break;
            case 2:
                //aNode.nextNode(nodeLoc + 4, -1);
                aNode.computeP3(current,next);
                break;
            case 3:
                //aNode.nextNode(nodeLoc + 4, -1);
                aNode.computeP4(current,next);
                break;
            case 4:
                //aNode.nextNode(nodeLoc + 5, -1);
                aNode.computeP5(current,next);
        }
        newGraph.push_back(aNode);
    }

}

vector<node> addLevel(vector<node> graph) {
    vector<node> newGraph;
    int level = graph[0].getSig().size();
    cout << "level:" << level << endl;
    int len = graph.size();
    for (int i = 0; i < len - 1; i++) {
        addGroup(graph[i], graph[i+1],newGraph);
        if (graph[i].getSig().back() == 1) {
            node nodeAdd = graph[i];
            nodeAdd.updateSigLast(-1);
            addGroup(nodeAdd, graph.at(i), newGraph);
        }
    }
    node newEnd = graph[len - 1];
    newEnd.addLevel(0);
    newGraph.push_back(newEnd);
    return newGraph;
}

int main() {
    vector<node> graph = {};

    node first = node(0, 250, 0, 1);
    node last = node(1000, 250, 1);

    graph.push_back(first);
    graph.push_back(last);

    listNodes(graph);

    graph = addLevel(graph);
    listNodes(graph);

    graph = addLevel(graph);
    listNodes(graph);

    graph = addLevel(graph);
    listNodes(graph);
    
//    graph = addLevel(graph);
//    listNodes(graph);

//    graph = addLevel(graph);
//    listNodes(graph);
//        graph = addLevel(graph);
//    listNodes(graph);
//        graph = addLevel(graph);
//    listNodes(graph);

}

