#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 10005;

typedef struct Vertex{
    int id;
    vector<int> connectors;

    Vertex() : id(-1) {}
    Vertex(int nid) : id(nid) {}
}Vertex;

typedef struct Graph{
    vector<Vertex> vertexs;
    int nVertexs;
    bool isDAG;

    Graph(int n, bool _isDAG) : nVertexs(n), isDAG(_isDAG) { vertexs.resize(n); }

    bool addEdge(int id1, int id2) {
        if(max(vertexs[id1].id, vertexs[id2].id) >= vertexs.size()) return false;

        if(isDAG) {
            vertexs[id1].connectors.push_back(id2);
        }
        else {
            vertexs[id1].connectors.push_back(id2);
            vertexs[id2].connectors.push_back(id1);
        }
        return true;
    }

}Graph;

int main(){
    
}

