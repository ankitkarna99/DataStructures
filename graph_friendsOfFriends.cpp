#include <iostream>
#include <vector>
#include <string>
#include "graph.hpp"

using namespace std;

void friendsOfFriends(Vertex *v){
    cout << "Friends of friends [" << v->name << "]: " << endl;
    vector<Vertex *> friends = v->adjacencyList;
    v->visited = true;

    for(auto myFriend : friends){
        myFriend->visited = true;
        vector<Vertex *> fofs = myFriend->adjacencyList;
        for(auto fof : fofs){
            if (!fof->visited){
                fof->visited = true;
                cout << "- " << fof->name << endl;
            }
        }
    }
}

int main(){
    Vertex *p1 = new Vertex("Paul");
    Vertex *p2 = new Vertex("David");
    Vertex *p3 = new Vertex("John");
    Vertex *p4 = new Vertex("Harry");
    Vertex *p5 = new Vertex("Zayn");
    Vertex *p6 = new Vertex("Bill");
    Vertex *p7 = new Vertex("John");
    Vertex *p8 = new Vertex("Mike");

    Graph friends({p1, p2, p3, p4, p5, p6, p7, p8});

    friends.createEdge(p1, p2);
    friends.createEdge(p1, p3);
    friends.createEdge(p2, p5);
    friends.createEdge(p2, p4);
    friends.createEdge(p3, p6);
    friends.createEdge(p3, p7);
    friends.createEdge(p5, p6);
    friends.createEdge(p5, p7);
    friends.createEdge(p4, p6);
    friends.createEdge(p7, p8);
    
    friendsOfFriends(p5);
    friends.clearVisits();

    return 0;
}