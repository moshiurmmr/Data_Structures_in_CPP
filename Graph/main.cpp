//#include<iostream>
//#include<vector>
//#include<map>


//#include "Graph.h"
#include "Graph.cpp" // if not added this line Linker error shows 'undefined referect to Graph::Graph(int)'
    // fix it. compiling both Graph.cpp and main.cpp from command prompt by "g++ Graph.cpp main.cpp" does not throw
    // any error

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

    return 0;
}
