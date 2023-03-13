#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, t;      // 교차로, 도로, 목적지 후보의 갯수
int s, g, h;    // 시작점, g와 h 사이가 가능한 
int a, b, d;    // a와 b 사이의 길이가 d인 양방향 도로
int xd[2020], yd[2020], f[2020];

vector<vector<pair<int, int >>> vt;

void dijkstra(int start, int *dist){
    priority_queue<pair<int, int >> pq;
    pq.push({0, start });
    while(pq.size()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] != -1) continue;
        dist[here] = cost;
        for(auto next: vt[here]){
            if(dist[next.first] != -1) continue;
            pq.push({-cost - next.second, next.first });
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(t--){
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        vt.clear();
        vt.resize(n+1);
        memset(f, 0, sizeof(f));
        memset(xd, -1, sizeof(xd));
        memset(yd, -1, sizeof(yd));

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &d);
            vt[a].push_back({ b,d });
            vt[b].push_back({ a,d });
        }
        for(int i = 0; i < t; i++){
            scanf("%d", &a);
            f[a] = 1;
        }
        dijkstra(s, xd);
        int bridge = xd[g] < xd[h] ? h : g;
        dijkstra(bridge, yd);
        for(int i = 1; i <= n; i++){
            if (!f[i]) continue;
            if (xd[i] == -1 || yd[i] == -1) continue;
            if (xd[i] == xd[bridge] + yd[i])
                printf("%d ", i);
        }
        puts("");
    }
    return 0;
}