#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int NUM = 5005;
int visited[NUM];
struct Edge{
    int to, next;
} edge[NUM];
int head[NUM];
int cnt;
void init(){
    for(int i = 0; i < NUM; ++i) {
        edge[i].next = -1;
        head[i] = -1;
    }
    cnt = 1;
}
void addedge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs1(int node){

}
void dfs2(int node){

}

int main(){
    init();
    memset(visited, 0, sizeof(visited));
    int n = 0, m = 0, v = 0, u = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }    
    visited[1] = 1;
    dfs1(1);
    return 0;
}