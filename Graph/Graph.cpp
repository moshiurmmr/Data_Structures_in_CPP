#include <iostream>
#include <vector>
#include <map>

// incude header file for Graph class
#include "Graph.h"

// constructor
Graph::Graph(int len){
    graphLen = len;
}

void Graph::addNode(int node){
    std::cout << "adding node " << node << std::endl;
    graphNodes.push_back(node);
}

void Graph::addEdge(int nodeA, int nodeB){
// To do: check if the node(s) exist
    std::cout <<"adding an edge between " << nodeA << " and " << nodeB << std::endl;
    edgesA.push_back(nodeA);
    edgesB.push_back(nodeB);
}

bool Graph::containsNode(int node){
// check if node is within the graph
// To do: implement using BFS or DFS
/*
    for (int i = 0; i < graphNodes.size(); i++){
        if (graphNodes[i] == node){
            std::cout << "the graph contains node " << node << std::endl;
            return true;
        }

    }

    std::cout << "the graph does not contain node " << node << std::endl;
    return false;
*/

    for(std::vector<int>::const_iterator i = graphNodes.begin(); i != (graphNodes.end()); i++){
        if (*i == node){
            std::cout << "the graph contains node " << node << std::endl;
            return true;
        }

    }

    std::cout << "the graph does not contain node " << node << std::endl;
    return false;


}

void Graph::printGraph(){
// print all the nodes
// To do: implement using BFS/DFS
    std::cout << "Nodes of the graph are: " ;
    for(std::vector<int>::const_iterator i = graphNodes.begin(); i != graphNodes.end(); i++){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void Graph::neighborsList(){
    std::map<int, std::vector<int>> neighbors; // a map data structure keeps track of all the neighbors of a node
        // here, the first element of the map is the index of the node and the corresponding vector in the second
        // element keeps all the neighbors of that node
        int count1 = 0;
        for(std::vector<int>::iterator i = edgesA.begin(); i != edgesA.end(); i++){
            neighbors[edgesA[count1]].push_back(edgesB[count1]);
            count1 += 1;
        }

        int count2 = 0;
        for(std::vector<int>::iterator i = edgesB.begin(); i != edgesB.end(); i++){
            neighbors[edgesB[count2]].push_back(edgesA[count2]);
            count2 += 1;
        }

        // print the neighbor list of the Graph
        std::cout << "The neighbor list of the Graph is: " << std::endl;
        for (std::map<int, std::vector<int>>::iterator i = neighbors.begin(); i != neighbors.end(); i++){
        // iterate for each index i.e., the first element of the map
            std::cout << "Neighbors of node " << i->first << "=> ";
            for(std::vector<int>::iterator it = i->second.begin(); it != i->second.end(); it++)
            // iterate through all the neighbors corresponding to the index in the previous loop
                std::cout <<*it << " ";
            std::cout << std::endl;
        }
}
