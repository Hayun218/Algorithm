## Heap

``` 스스로 요약

```
#### 종류
 - 최대 힙 : 부모노드의 값이 더 큰 경우
 - 최소 힙 : 부모노드의 값이 자식노드보다 더 작을 경우

#### 특징
- 완전 이진 트리의 일종
- 여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조
- 우선순위 큐(주로 사용됨! O(logN), 힙 정렬O(NlogN)
- 중복된 값 허용
- 배열로 구현

#### 효율성
![시간복잡도](https://gmlwjd9405.github.io/images/data-structure-heap/data-structure-heap-priorityqueue.png)

#### 힙에서의 부모 노드와 자식 노드의 관계
- 배열에서 1부터 시작! => 0 부터 시작도 가능하지만 편의를 위해 => 0부터 할 경우 밑에 왼쪽 오른쪽 자식의 ㄴ인덱스에 +1씩 
- 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2
- 오른쪽 자식의 인덱스 = (부모의 인덱스) * 2 + 1
- 부모의 인덱스 = (자식의 인덱스) / 2
	
![관계](https://gmlwjd9405.github.io/images/data-structure-heap/heap-index-parent-child.png)

```
#define MAX_ELEMENT 200 // 힙 안에 저장된 요소의 개수

typedef struct{
  int key;
} element;

typedef struct{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

# 힙의 생성
HeapType heap1;
```

<https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html>


#### 삽입
- 다른 노드는 바뀌지 않고 마지막 노드에 새로운 요소를 추가 
- 최대 힙 혹은 최소 힙 의 특징에 맞추어 새로운 노드를 부모노드와 비교하여 rearrange

* 최대 힙
![힙에서 서로 교환](https://gmlwjd9405.github.io/images/data-structure-heap/maxheap-insertion.png)

```
/* 현재 요소의 개수가 heap_size인 힙 h에 item을 삽입한다. */
// 최대 힙(max heap) 삽입 함수
void insert_max_heap(HeapType *h, element item){
  int i;
  i = ++(h->heap_size); // 힙 크기를 하나 증가

  /* 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 */
  // i가 루트 노트(index: 1)이 아니고, 삽입할 item의 값이 i의 부모 노드(index: i/2)보다 크면
  while((i != 1) && (item.key > h->heap[i/2].key)){
    // i번째 노드와 부모 노드를 교환환다.
    h->heap[i] = h->heap[i/2];
    // 한 레벨 위로 올라단다.
    i /= 2;
  }
  h->heap[i] = item; // 새로운 노드를 삽입
}
```

#### 삭제
1. 최대 힙에서 최댓값이 루트노드이며 루트노드를 먼저 삭제
	- 최대 힙에서 최대값을 먼저 삭제시켜야 함 (최소 힙에서는 최소값부터)
	
2. 삭제된 루트노드에는 마지막 노드 값을 가지고 옴
3. 다시 재정비

* 최대 힙
![최대힙 삭제](https://gmlwjd9405.github.io/images/data-structure-heap/maxheap-delete.png)

```
// 최대 힙(max heap) 삭제 함수
element delete_max_heap(HeapType *h){
  int parent, child;
  element item, temp;

  item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
  temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
  parent = 1;
  child = 2;

  while(child <= h->heap_size){
    // 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
    if( (child < h->heap_size) && ((h->heap[child].key) < h->heap[child+1].key) ){
      child++;
    }
    // 더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
    if( temp.key >= h->heap[child].key ){
      break;
    }

    // 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
    h->heap[parent] = h->heap[child];
    // 한 단계 아래로 이동
    parent = child;
    child *= 2;
  }

  // 마지막 노드를 재구성한 위치에 삽입
  h->heap[parent] = temp;
  // 최댓값(루트 노드 값)을 반환
  return item;
}
```


[참고자료] <https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html>