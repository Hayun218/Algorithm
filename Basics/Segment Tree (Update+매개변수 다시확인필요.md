
##세크먼트 트리
	구간들을 보존하고 있는 트리
- 보통 완전 이진 트리의 형태 사용 => 재귀적 구조가 반복 (2^n 꼴이 아닐 경우 남는 구간을 의미없는 값으로 채워서 포화 이진 트리의 형태로 사용)
- 루트의 인덱스의 시작 = 1
- 부모 노드의 값 = 자식 노드 값들의 합
	- 인덱스를 i라고 할 때 배열의 i번째 요소의 자식 노드의 값 = **(i*2) + (i*2+1)**

###구현방법

```C++

long long init(int index, int start, int end)
{    
    if(start == end)
        tree[index] = A[start];
    else
        tree[index] = init(index*2, start, (start+end)/2) + init(index*2+1, (start+end)/2 + 1, end);

    return tree[index];
}
```
=> 기본적인 세그먼트 트리의 구현

- 여기서 탐색방법!!

1. [left, right] 범위가 [start, end]와 전혀 겹치지 않는 경우 ==> return 0;
2. [start, end] 범위가 [left, right]에 완전히 속해 있는 경우 ==> return tree[idx]
3. [left, right] 범위가 [start, end]에 완전히 속해 있는 경우
4. 그 외의 경우 (범위가 일부분 겹치는 경우 
	- 3, 4 번은 하위 노드를 탐색할 수 있도록 재귀를 부름

* [start, end]가 구하고자 하는 구간의 합
	- => 본 탐색 방법은 범위의 합 뿐만 아니라 다른 최소값 (min) 최대값 (max)등에서도 여전히 활용!!



```C++
long long sum(int idx, int start, int end, int left, int right){
	if(start > right || end < left)	return 0;
	if(start >= left && end <= right) return tree[idx]
	else{
		int mid = (start+end)/2;
		return sum(2*idx, start, mid, left, right + 2*idx+1, mid+1, end, left, right);
	}
}
```



- O(logN)의 속도 

* query: 데이터베이스나 검색엔진등에 정보를 요청하는 것

- 참고자료:
	- <https://wkdtjsgur100.github.io/segment-tree/>
