## Union-find or Disjoint-set
	많은 상호 배타적 부분 집합으로 이루어진 원소들에 대해 저장하고 조직하는 자료구조
	
	쉬운 자료구조이지만 유니온 파인드 문제인지 알 수 있는 능력이 매우 중요

- 상호 배타적이란?
	- 두 집합의 합집합은 공집합이지만 그 두 집합은 한 집합안에 포함되어 있어서 두 집합 모두 동시에 일어날 수 없다
	
 	```
	A ∩ B = 0, (A B) ⊂ C  
	```
	- 독립과는 명백한 차이점을 두고있다. => 독립적이라면 두 집합이 동시에 일어나도 상관없으므로

## 구현
- 부분집합들은 트리로 나타내며 파인드를 통해 루트 노드를 파악하고 유니온을 통해 합친다
 
#### Find
- 원소가 주어졌을 때 해당 원소가 속한 집합을 찾아낸다. => 대표 원소 즉 루트 노드를 반환함으로써 같은 집합인지 아닌지를 판단할 수 있게 해줌 
- 시간복잡도 : O(logN)

#### Union
- 두개의 다른 집합을 하나로 합하여 줌
- 시간복잡도 : O(logN)

### STEPS
1. 초기화 => 처음 모든 원소는 자기 자신을 루트노드로 지니고 있다. 
![초기화](https://t1.daumcdn.net/cfile/tistory/991CCE3359FEBEE007)
2. 트리 데이터 넣어주기 (문제에 따라 다른 정보를 입력하여 각 원소를 연결시키기) => 여러 트리가 형성
3. find 함수를 호출하여 각 노드의 루트노드를 탐색
![find](https://t1.daumcdn.net/cfile/tistory/9915A03359FEC8941A)
4. union 함수를 통해 루트노드가 다른 두개의 트리르 합치기
![union](https://t1.daumcdn.net/cfile/tistory/9910FE3359FEC89403)



#### 관련 문제
- <https://www.acmicpc.net/problem/1717>
- <https://www.acmicpc.net/problem/9938>

#### 참고자료
- <https://mygumi.tistory.com/246>
- <https://kks227.blog.me/220791837179?Redirect=Log&from=postView>