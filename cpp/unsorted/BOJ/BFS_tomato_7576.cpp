#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define rotten 1
#define unrotten 0
#define noTomato -1

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
 
int N, M, tomato[1001][1001], visited[1001][1001];
int cnt, day;
queue <pair <int, int> > Q;

int bfs(){
    int day = 1;
    while(!Q.empty()){
        int qSize = Q.size();
        for(int i = 0; i < qSize; i++){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            if(visited[x][y])
                continue;
            else
                visited[x][y] = 1;
    
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                else if(tomato[nx][ny] == noTomato)
                    continue;
            
                else if(tomato[nx][ny] == unrotten){
                    tomato[nx][ny] = rotten;
                    Q.push(make_pair(nx, ny));
                    cnt--;
                }
                if(cnt == 0)
                    return day;
            }
        }
        day++;
    }
    return -1;
}

int main(){
    cin >> M >> N;
    cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == rotten)
                Q.push(make_pair(i, j));
            else if(tomato[i][j] == unrotten)
                cnt++;
        }
    }
    cout << bfs() << endl;
    return 0;
}