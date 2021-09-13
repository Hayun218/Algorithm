## Floyd-Warshall
	모든 최단 경로를 구하는 문제 (all pairs shortest path problem) 
	음의 가중치도 계산 가능 (unlike 다익스트라)

	
### 기본개념
- optical substructure : 중간 정점들이 모두 최단이 될때 이를 이은 경로도 최단이 되는 구조
- 기본적인 3중 for문 => O(V^3)
- DP 형태 => 모든 간선의 거리를 구하므로 2차원 배열 

- 테이블 두개를 활용
	- 각 정점 사이의 거리를 저장한 테이블
	- 직전 정점을 저장한 테이블 
- 처음에는 인접리스트에 대한 정보만 들어간다. 점차 연결지으면서 두 테이블을 갱신!



### STEPS
1. 전처리
	- 초기화 : 자기 자신으로 가는 dist[i][i]는 0이고, 나머지는 ∞ (자기 자신으로 이동하지 못하는 문제의 경우에는 이 또한 ∞으로 초기화)
	- 간선정보 받아서 넣기 => i-> j로 가는 간선 정보가 w 라면 dist[i][j] = w
	- 같은 거리정보가 주어질 때는 min(w, dist[i][j])로 더 작은 값 넣기
2. 두 정점 i, j에 대해, k번 정점을 사용해 우회하면 지금까지보다 최단거리가 짧아지는가? 확인
	```
	if(dist[i][j] > dist[i][k] + dist[k][j])
	```	
	
### 코드
```
 // 플로이드 알고리즘으로 최단경로 구함
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```


- 문제
	- <https://www.acmicpc.net/problem/11404>
	- <https://www.acmicpc.net/problem/9205>

- 공부한 자료 
	- <https://hsp1116.tistory.com/45> => 이해하기 어려웠음
	- <https://kks227.blog.me/220797649276?Redirect=Log&from=postView> => 좀더 간결하고 쉬움