#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1 << 20;
const int NUM = 10005;
struct edge{
    int from, to, w;
    edge(int a, int b, int c) {from = a; to = b; w = c;}
};
vector<edge> e[NUM];
struct s_node{
    int id, n_dis;
    s_node(int b, int c) {id = b; n_dis = c;}
    bool operator < (const s_node & a) const {
        return n_dis > a.n_dis;
    }
};
int n,m;
int pre[NUM], p[NUM];
int dijkstra(){
    int s = 1, cost = 0;
    int dis[NUM];
    bool done[NUM];
    for(int i = 1; i <= n; ++i) {dis[i] = INF; done[i] = false; p[NUM] = INF;}
    dis[s] = 0;
    priority_queue<s_node> Q;
    Q.push(s_node(s, dis[s]));
    while(!Q.empty()){
        s_node u = Q.top();
        Q.pop();
        if(done[u.id]) continue;
        done[u.id] = true;
        for(int i = 0; i < e[u.id].size(); ++i){
            edge y = e[u.id][i];
            if(done[y.to]) continue;
            if(dis[y.to] > y.w + u.n_dis){
                dis[y.to] = y.w + u.n_dis;
                Q.push(s_node(y.to, dis[y.to]));
                pre[y.to] = u.id;
                p[y.to] = y.w;
            }
            else if(dis[y.to] == y.w + u.n_dis){
                p[y.to] = min(p[y.to], y.w);
            }
        }
    }
    return cost;
}

int main(){
    int a = 0, b = 0, c = 0, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        e[i].clear();
    }
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back(edge(a, b, c));
        e[b].push_back(edge(b, a, c));
    }
    dijkstra();
    for(int i = 1; i <= n; ++i) ans += p[i];
    printf("%d", ans);
    return 0;
}