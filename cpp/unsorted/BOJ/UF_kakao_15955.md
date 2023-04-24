- 내가 이해한 문제내용
	- 2차원 좌표평면 위에서 체크포인트를 오가며 제한된 HP를 가지고 특정 목표지점에 도달할 수 있는지 없는지를 확인하는 프로그램 
	- "비용이 c 이하인 간선만 걸쳐서 정점 a에서 정점 b까지 이동 할 수 있는가?"

- 접근방식
	- 유니온 파인드
	- 1. 쿼리안에 {가중치, {a,b}}를 넣고 가중치에 맞추어 오름차순 정렬
	- 2. 가중치가 적은 곳 부터 순차적으로 유니온 파인드로 합치기
	-  => 모든 간선을 고려하지 않고 x를 기준으로 (N-1)만큼 오름차순 정렬후 인접한 간선을 연결! + y를 기준으로 동일하게 ==> 불필요한 간선연결을 줄임

- 어려웠던 점
	- 문제자체가 너무 어려웠다..
	- x와 y를 기준으로 각각 정렬한다는 생각과 처음에 HP를 가중치라고 생각하지 못해서 막 복잡하게 생각해 버림
	- 코드를 짜는 걸 위주로 공부하기 보다는 여기서 사용된 접근방식과 사고방식을 이해하고자 노력 
	- 유니온 파인드 복습으로 merge 한다는 개념은 이해 했으나 pair로 묶는 변수도 길어지고 코드도 길어지니까 헷갈렸다.. 하나씩 따로 보니 괜찮았지만 생소한 부분들도 있었다 (sort할때의 코드)

- 복잡도
	- 시간복잡도: O(NlogN + QlogQ)  

- 참고자료
	- https://m.blog.naver.com/PostView.nhn?blogId=pasdfq&logNo=221332735719&proxyReferer=https%3A%2F%2Fjaimemin.tistory.com%2Fm%2F797