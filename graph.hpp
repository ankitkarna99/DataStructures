#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vertex {
    public:
        string name;
        bool visited;
        vector <Vertex *> adjacencyList;

        Vertex(string _name){
            visited = false;
            name = _name;
        }
};

class Graph {
    public:
        vector <Vertex *> vertices;

        Graph(vector<Vertex *> _vertices){
            vertices = _vertices;
        }

        void createDirectionalEdge(Vertex *v1, Vertex *v2){
            v1->adjacencyList.push_back(v2);
        }

        void createEdge(Vertex *v1, Vertex *v2){
            v1->adjacencyList.push_back(v2);
            v2->adjacencyList.push_back(v1);
        }

        void clearVisits(){
            for (auto vertex : vertices){
                vertex->visited = false;
            }
        }

        void breadthFirstSearch(Vertex *v){
            cout << "BFS: " << endl;

            vector<Vertex*> queue;
            v->visited = true;
            queue.push_back(v);

            while(!queue.empty()){
                Vertex *current = queue.front();
                queue.erase(queue.begin());
                cout << current->name << endl;

                for (auto neighbor : current->adjacencyList){
                    if (!neighbor->visited){
                        neighbor->visited = true;
                        queue.push_back(neighbor);
                    }
                }
            }
        }

        void depthFirstSearch(Vertex *v){
            cout << "DFS: " << endl;

            vector <Vertex*> stack;
            v->visited = true;
            
            stack.push_back(v);

            while(!stack.empty()){
                Vertex *current = stack.back();
                stack.pop_back();

                cout << current->name << endl;

                for(auto neighbor : current->adjacencyList){
                    if (!neighbor->visited){
                        neighbor->visited = true;
                        stack.push_back(neighbor);
                    }
                }
            }
        }
};