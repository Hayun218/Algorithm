#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
/*
DFS를 활용하여 푼문제
방식:
1. 무거운구슬을 노드로 그리고 그 안의 값은 가벼운구슬로 벡터안에서 양방향 연결 vice versa
2. DFS를 두번 돌린다
 1) 첫번째는 해당 노드보다 재귀함수를 활용하여 가벼운 값을 찾아서 그 갯수를 구한다
 2) 두번째는 해당 노드보다 무거운 값
3. 두개의 return값 중 하나라도 (N+1)/2 즉 절반보다 많을 경우 cnt++을 한ㄷ
4. cnt를 프린트

어려웠던점&배운점:
- 재귀함수를 사용하여 계산!
- 노드와 그 안의 값에 대한 생각 즉, heavy[node][i]값들의 연결 => 처음으로 확실히 vector var[100] 구조에 대해 파악하게 됨
- 처음에 문제풀이를 참고하였을 때 send 변수의 역할은 알겠으나 잘 파악하지 못하였는데 재귀함수! 그리고 visited 변수들안에 배열자체를 넣었다는걸로 파악
=> 이와 같은 방식은 이전에도 사용하였으나 익숙하지 않은가보다.. 계속 떠오르지 않아서 잘 사용하지 못한다 ㅠㅠ
- 조금더 이해에 도움을 주기 위해 각 값들을 프린트하여 확인

깨달은점
- 앞으로는 문제를 풀때 조금더 기초부터 생각해봐야 할 듯
- 그런의미에서 DFS와 BFS부분 기초부터 공부시작 => 이틀에 그래프 한문제씩 풀어보기!!!!!

md 내용복붙
*/

vector <int> heavy[100], light[100];
bool result[100];
bool hvisited[100], lvisited[100];

int DFSH(int node){
  int send = 1;
  for(int i = 0; i < heavy[node].size(); i++){
    if(!hvisited[heavy[node][i]]){
      //cout << node <<" > "<<heavy[node][i] << endl;  //check
      hvisited[heavy[node][i]]=true;
      send += DFSH(heavy[node][i]);
    }
  }
  return send;
}

int DFSL(int node){
  int send = 1;
  for(int i = 0; i < light[node].size(); i++){
    if(!lvisited[light[node][i]]){ //방문여부 확인
      //cout << node <<" < "<<light[node][i] << endl; //check
      lvisited[light[node][i]]=true;
      send += DFSL(light[node][i]);
    }
  }
  return send;
}

int main(){
  int N, M;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int heavier, lighter;
    cin >> heavier >> lighter;
    heavy[heavier].push_back(lighter); // 큰 값을 노드로 지닐때 해당 노드보다 작은값을 가지고 있음
    light[lighter].push_back(heavier); // vice versa
  }

  for(int i = 1; i <= N; i++){
    memset(hvisited, false, sizeof(hvisited));
    memset(lvisited, false, sizeof(lvisited));
    hvisited[i]=true; lvisited[i]=true;

    if(DFSH(i) > ((N+1)/2))
      result[i]=true;
    if(DFSL(i) > ((N+1)/2))
      result[i]=true;
  }

  int cnt = 0;
  for(int i = 1; i <= N; i++){
    if(result[i])
      cnt++;
  }

  cout << cnt << endl;
  return 0;
}
