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

int Graph::getGraphSize(){
    return graphLen;
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

std::vector<int> Graph::nodeNeighbors(int node){
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
        // std::cout << "The neighbor list of the Graph is: " << std::endl;
        std::vector<int> myNeighbors;
        for (std::map<int, std::vector<int>>::iterator i = neighbors.begin(); i != neighbors.end(); i++){
        // iterate for each index i.e., the first element of the map
            //std::cout << "Neighbors of node " << i->first << "=> ";
            if (i->first == node){
                for(std::vector<int>::iterator it = i->second.begin(); it != i->second.end(); it++){
                    myNeighbors.push_back(*it);

                }

            }

        }
        //std::cout << myNeighbors;

        return myNeighbors;

}

void Graph::deleteNode(int node){
// this function deletes the node from the Graph and also updates the affected edges
// this function deletes the node from the Graph and also updates the affected edges

    // check to see if the node exists in the Graph
    bool nodeExist = containsNode(node);
    int nodePos = 0; // node position in the Graph (graphNodes) array
    if (nodeExist){
        // delete the node
        for(std::vector<int>::const_iterator i = graphNodes.begin(); i < graphNodes.end(); i++){
        // iterate over all nodes. one point to be careful here is that std::vector::end returns an iterator to the
        // element following the last element of the container, not the last container. Hence, used i < graphNodes.end()
            if (*i == node){
                graphNodes.erase(graphNodes.begin() + nodePos);
                std::cout << "deleting node " << node << std::endl;
            }
            nodePos ++;
        }

    }

    // delete the node from the edgesA
        int posA = 0;
        for(std::vector<int>::iterator j = edgesA.begin(); j < edgesA.end(); j++){
            if(*j == node){
                edgesA.erase(edgesA.begin() + posA); // remove node from edgesA list
                edgesB.erase(edgesB.begin() + posA); // remove corresponding neighbors in edgesB list
                std::cout << "inside edgesA loop "  << std::endl;
            }
            posA += 1;
        }
        // delete the node from the edgesB
        int posB = 0;
        for(std::vector<int>::iterator k = edgesB.begin(); k < edgesB.end(); k++){
            if(*k == node){
                edgesB.erase(edgesB.begin() + posB); // remove node from edgesB list
                edgesA.erase(edgesA.begin() + posB); // remove corresponding neighbors in edgesA list
            }
            std::cout << "inside edgesB loop "  << std::endl;
            posB += 1;
        }
        // update the nodeNeighbors map
        //int x = Graph::nodeNeighbors();
        //int x = this->nodeNeighbors();

}

void Graph::printDFS(int node){
/* print all the nodes in the graph using Depth First Search (DFS) algorithm.
It is not very efficient to implent DFS as part of the map class becasue the array, marked, which tracks the
nodes that have been visited during the graph traversal, gets filled up with all 'true' boolean values. So, next
time if we want to call the DFS-based function the graph traversal just does not happen.
Hence, the DFS should be implemented outside of the map class.

*/
    std::vector<int> myNeighbors;
        myNeighbors = this->nodeNeighbors(node);
        //std::cout << "inside DFS function" << std::endl;
        std::cout << node << " ";
        marked[node] = true;
        for (std::vector<int>::iterator it = myNeighbors.begin(); it != myNeighbors.end(); it++){
            if (!marked[*it]){
                //std::cout << *it << " ";
                //marked[*it] = true;
                this->printDFS(*it);
            }
        }
}
