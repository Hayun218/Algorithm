#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
using namespace std;
const int MAX_V = 20000; // 최대 정점의 개수
const int INF = 1000000000; // 절대 나올 수 없는 경로값

typedef pair<int, int> P; // 페어

int main()
{
    int V, E, K; // 정점의 개수, 간선의 개수, 시작 정점의 번호
    vector<P> adj[MAX_V]; // 페어를 백터안으로 adj로 이름짓는 array
    scanf("%d %d %d", &V, &E, &K);  // 입력받기

    for(int i = 0; i < E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); //u에서 v로 가는 가중치 w
        adj[u-1].push_back(P(v-1, w));  // adj[u-1]안에 v-1, w를 넣음
    }
    int dist[MAX_V];    // 거리값을 넣기 위한 array
    fill(dist, dist+MAX_V, INF); // dist 부터 dist+MAX_V까지 INF로 채움 memset(dist, -1, sizeof(dist)) 로 대체 가능 cstring 선언한 이후
    bool visited[MAX_V] = {0}; // 방문하였는지 확인
    priority_queue<P, vector<P>, greater<P> > PQ; // 

    dist[K] = 0;    // 시작점을 0으로
    PQ.push(P(0, K));   // 페어에 0과 k를 넣고 PQ에 push
    while(! PQ.empty()){    // PQ가 빌때까지 반복
        int curr;       //현재 
        do{
            curr = PQ.top().second; // 위에서 두번째 = curr
            PQ.pop();   // 내보내기 - 오름차순
        }while (!PQ.empty() && visited[curr]); // PQ가 비지 않고 curr을 방문할때까지 위의 경우 반복
        if(visited[curr]) break;

        visited[curr] = true;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;

            if(dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
}