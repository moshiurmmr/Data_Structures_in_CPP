//#include<iostream>
//#include<vector>
//#include<map>


//#include "Graph.h"
#include "Graph.cpp" // if not added this line Linker error shows 'undefined referect to Graph::Graph(int)'
    // fix it. compiling both Graph.cpp and main.cpp from command prompt by "g++ Graph.cpp main.cpp" does not throw
    // any error
//#include "bfs.cpp"
int main(){
    int graph_size = 5;
    Graph mygraph(graph_size);

    for (int i=1; i<graph_size; i++){
        mygraph.addNode(i);
    }

    mygraph.addEdge(1, 2);
    mygraph.addEdge(1, 3);
    mygraph.addEdge(2, 4);
    mygraph.printGraph();
    mygraph.containsNode(3);
    mygraph.containsNode(6);
    mygraph.neighborsList();
    //mygraph.deleteNode(4);
    //mygraph.printGraph();
    //mygraph.neighborsList();
    //mygraph.printGraph();
    //std::cout << "marked" << mygraph.marked;
    //std::cout << "print using DFS, nodeNeighbors(1) is " << std::endl;
    //mygraph.printDFS(1);

    //std::vector<int> neighbors = mygraph.nodeNeighbors(2);
    //for(std::vector<int>::iterator i=neighbors.begin(); i != neighbors.end(); i++)
       //std::cout << *i << " ";
    //std::queue<int> bfs_queue; // an empty queue to track the neighbor nodes
    //bool visited[mygraph.getGraphSize()]; // to track the nodes that have been visited
    //std::cout << "print the graph using bfs" << std:endl;
    //bfs(mygraph, 2);

    return 0;
}
