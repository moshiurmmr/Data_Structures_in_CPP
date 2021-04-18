/*
This is an implementation of Breadth First Search (BFS) algorithm for graph traversal. The main idea behind BFS is
- visit the starting node of the graph, then
- explore it's neighbors (/childrens)
- repeat the above two steps for each neighbor until the whole graph is visited

BFS algorithm:
 i. visit starting node
 ii. put all of its neighbors in a queue
 iii. pop an element from the queue and repeat steps i and ii above
 iv. repeat step iii unit the queue is empty

 Author: Moshiur Rahman
*/
//#include <iostream>
#include <queue>
//#include "Graph.h"
#include "Graph.cpp"

//std::queue<int> bfs_queue; // an empty queue to track the neighbor nodes
//bool visited[]; // to track the nodes that have been visited



//#include "Graph.cpp" // if not added this line Linker error shows 'undefined referect to Graph::Graph(int)'
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
    //mygraph.containsNode(3);
    //mygraph.containsNode(6);
    mygraph.neighborsList();
    //mygraph.deleteNode(4);
    //mygraph.printGraph();
    //mygraph.neighborsList();
    //mygraph.printGraph();
    //std::cout << "marked" << myvisitedgraph.marked;
    //std::cout << "print using DFS, nodeNeighbors(1) is " << std::endl;
    //mygraph.printDFS(1);

    //std::vector<int> neighbors = mygraph.nodeNeighbors(2);
    //for(std::vector<int>::iterator i=neighbors.begin(); i != neighbors.end(); i++)
       //std::cout << *i << " ";

    std::queue<int> bfs_queue; // an empty queue to track the neighbor nodes
    std::cout << "graph size is " << mygraph.getGraphSize() << std::endl;
    bool visited[mygraph.getGraphSize()]; // to track the nodes that have been visited
    void bfs(Graph graph, int node, bool visited[], std::queue<int> bfs_queue); // declare bfs function

    std::cout << "print the graph using bfs starting from node 3" << std::endl;
    bfs(mygraph, 3, visited, bfs_queue);

    // reset teh bfs_queue
    //bfs_queue = {false};
    //std::cout << "print the graph using bfs starting from node 3" << std::endl;
    //bfs(mygraph, 3, visited, bfs_queue);

    return 0;
}

void bfs(Graph graph, int node, bool visited[], std::queue<int> bfs_queue){
    std::cout << node << " ";
    visited[node] = true;
    //std::cout << "visited is now " << visited << std::endl;
    std::vector<int> neighborList = graph.nodeNeighbors(node); // neighbors of the node
    //std::cout << "neighborlist of the node is " << graph.nodeNeighbors(node) << std::endl;
    for(std::vector<int>::iterator i = neighborList.begin(); i != neighborList.end(); i++){
        if(!visited[*i]){
            //std::cout << "push " << *i << std::endl;
            bfs_queue.push(*i);
        }
        else{
            bfs_queue.pop();
        }
    }
    int next_node = bfs_queue.front();
    //bfs_queue.pop();

    if(!bfs_queue.empty())
         //bfs(graph, bfs_queue.pop(), visited, bfs_queue);
         bfs(graph, next_node, visited, bfs_queue);

}
