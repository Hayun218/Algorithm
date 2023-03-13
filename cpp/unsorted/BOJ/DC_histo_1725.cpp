#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N = 500; 
const int INF = 1000000000;
typedef pair<int, int> PA;
int T, N, M; // test case #, #of places, #of roads
int U, V, P; // U에서 V까지의 거리 P
int S, D, dist[INF]; // 시작점, 도착점

void Diikstra()
{
    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int, int> > PQ;
    PQ.push{(0, S)};
    
}
int main()
{

    scanf("%d", &T);
    while(T--){
        vector<PA> adj[MAX_N];
        scanf("%d %d", &N, &M);

        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &U, &V, &P);
            adj[U-1].push_back(PA(V-1, P));
        }



        


        dist[S] = 0;




    }
}
