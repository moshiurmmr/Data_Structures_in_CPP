/*
This is the header file for the graph class.
*/
class Graph{
    private:
        int graphLen; // number of nodes in the graph
        //array marked[] = {false * graphLen}; // an array to keep  track of nodes visited in DFS
        //bool marked [graphLen] = {0} ;
        std::vector<int> graphNodes; // a vector containing all the nodes of the graph
        std::vector<int> edgesA; // a vector containing one side (A) of the edges among nodes
        std::vector<int> edgesB; // a vector containing the other side (B) of the edges among nodes

    public:
        //Graph(int size); // constructor of the class
        //bool marked = {false * graphLen};
        //bool marked [graphLen] = {false} ;
        //bool marked [] ;
        void addNode(int node);
        void addEdge(int nodeA, int nodeB);
        bool containsNode(int node); // check if the node is in the graph
        bool containsEdge(int nodeA, int nodeB); // check if an edge exists between nodeA and nodeB
        void deleteNode(int node);
        void deleteEdge(int nodA, int nodeB);
        void printGraph();
        void printDFS(int node);
        void neighborsList(); // calcualtes neighbors for all nodes in the Graph
        std::vector<int> nodeNeighbors(int node); // returs list of neighbors of a node
        int getGraphSize(); // returns total number of nodes in the graph
        Graph(int len); // constructor of the class

};
