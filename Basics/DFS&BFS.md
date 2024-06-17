* 그래프 탐색 : 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것 (그래프에 대한 개념 후에 하나 만들기)
- 그래프은 정점과 간선의 집합 
- **<span style="color:lightblue">그래프와 백트랙킹 정리 필요..</span>**

---



## DFS (Depth-First Search) - 깊이 우선 탐색

- 깊이 우선으로 미로 찾기에서 하나의 길로 쭉 가다가 길이 막힐 경우 다시 원래 장소로 돌아와 다른 branch로 탐색하는 것
- 모든 노드를 방문하고자 할 때 활용!
- 최단 거리를 구하지는 못함!! => 최단거리에 특화된 알고리즘도 있음 (ex) 다익스트라, etc..)

### 특징
- 자기 자신을 호출하는 **순환 알고리즘**의 특성을 지닌다.
- **노드의 방문 여부를 반드시 검사**하여야 한다
	- ex) bool visited[max] 와 같은 변수를 통해
	- OR 무한 루프에 빠질 위험이 있다


### 탐색 과정 (그림으로)
![그림으로 살펴보기](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/dfs-example.png)

1. a 노드(시작 노드)를 방문한다.
	- 방문한 노드는 방문했다고 표시한다.
2. a와 인접한 노드들을 차례로 순회한다.
	- a와 인접한 노드가 없다면 종료한다.
	- a와 이웃한 노드 b를 방문했다면, a와 인접한 또 다른 노드를 방문하기 전에 b의 이웃 노드들을 전부 방문해야 한다.
3. b를 시작 정점으로 DFS를 다시 시작하여 b의 이웃 노드들을 방문한다.
4. b의 분기를 전부 완벽하게 탐색했다면 다시 a에 인접한 정점들 중에서 아직 방문이 안 된 정점을 찾는다.
	- 즉, b의 분기를 전부 완벽하게 탐색한 뒤에야 a의 다른 이웃 노드를 방문할 수 있다는 뜻이다.
5. 아직 방문이 안 된 정점이 없으면 종료한다. 있으면 다시 그 정점을 시작 정점으로 DFS를 시작한다.



### 구현 방법
1. 순환 호출
2. 명시적 스텍 
	- 방문하였던 노드들을 스텍에 넣어두었다가 다시 꺼내어 사용하는 방법


### 시간복잡도

- DFS는 그래프(정점의 수: N, 간선의 수: E)의 모든 간선을 조회한다.
- 인접 리스트로 표현된 그래프: O(N+E)
- 인접 행렬로 표현된 그래프: O(N^2)
  - 즉, 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(Sparse Graph) 의 경우 인접 행렬보다 인접 리스트를 사용하는 것이 유리하다. .. => 희소 그래프란..?



#### 참고문헌

- [DFS 참고](https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html)

---

## BFS (Breadth First Search- 너비우선탐색

- 그래프 전체를 탐색하되, 인접한 노드들을 차례대로 방문하도록 구현
- **시작점을 루트로 때, height가 작은 노드부터 차례대로 방문하는 전체 탐색 방식**
- 큐를 이용하여 구현

### 구현방법

1. queue의 가장 앞에 있는 노드를 pop

1. 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 queue에 push
2. queue가 비어있지 않으면, ①번부터 다시 실행

```c++
while(queue가 비어있지 않은 동안)
{
① queue의 가장 앞에 있는 노드를 pop 
② 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 queue에 push
}
```

#### 참고문헌

- [참고자료](https://sarah950716.tistory.com/13)

## DFS VS BFS (비교)

### 구현방법

- DFS : 스택 또는 재귀함수로 구현
- BFS : 큐를 이용해서 구현

### 사진으로 비교

![DFSvsBFS](https://twpower.github.io/images/20180114_73/dfs-bfs-example.gif)



### 코드 *BOJ 1260

```c++
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> graph[1001];
vector <bool> visited;
queue <int> q;
int N, M, V;

void dfs(int node){
  printf("%d ", node);
  for(int i = 0; i < graph[node].size();i++){
    if(!visited[graph[node][i]]){
      visited[graph[node][i]] = true;
      dfs(graph[node][i]);
    }
  }
}

void bfs(){
  q.push(V);
  visited[V]= true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    printf("%d ", node);

    for(int i = 0; i < graph[node].size(); i++){
      if(!visited[graph[node][i]]){
        visited[graph[node][i]] = true;
        q.push(graph[node][i]);
      }
    }
  }
}

int main(){
  scanf("%d %d %d", &N, &M, &V);
  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 0; i < N; i++)
    sort(graph[i].begin(), graph[i].end());

  visited = vector<bool>(N+1, false);
  visited[V] = true;
  dfs(V);
  printf("\n");
  visited = vector<bool>(N+1, false);
  bfs();

  return 0;
}
```



#### 참고자료

- [사진참고](https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp)