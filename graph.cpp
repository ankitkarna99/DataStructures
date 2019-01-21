#include <iostream>
#include <vector>
#include <string>
#include "graph.hpp"

using namespace std;

int main(){
    Vertex *v1 = new Vertex("1");
    Vertex *v2 = new Vertex("2");
    Vertex *v3 = new Vertex("3");
    Vertex *v4 = new Vertex("4");
    Vertex *v5 = new Vertex("5");
    Vertex *v6 = new Vertex("6");
    Vertex *v7 = new Vertex("7");
    Vertex *v8 = new Vertex("8");

    Graph graph({v1, v2, v3, v4, v5, v6, v7, v8});

    graph.createEdge(v1, v2);
    graph.createEdge(v1, v3);
    graph.createEdge(v2, v5);
    graph.createEdge(v2, v4);
    graph.createEdge(v3, v6);
    graph.createEdge(v3, v7);
    graph.createEdge(v5, v6);
    graph.createEdge(v5, v7);
    graph.createEdge(v4, v6);
    graph.createEdge(v7, v8);

    graph.breadthFirstSearch(v5);
    graph.clearVisits();
    graph.depthFirstSearch(v5);
    graph.clearVisits();

    return 0;
}