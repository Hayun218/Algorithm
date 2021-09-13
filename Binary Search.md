## Binary Search 이분 탐색

- 탐색 기법 중에 하나로 탐색범위를 두개로 분활하여 찾는 방식 => 빠름
- left, right, mid 값으로 탐색 (이때, mid = (left+right)/2)

### 조건

1. 이미 정렬되어 있는 데이터여야 함
2. left, right, mid 값을 정해줌 (left ≤ mid ≤ right)
3. mid를 구하고자 하는 값과 비교
   - mid 값이 더 클 경우 : right = mid - 1
   - 구하고자 하는 값이 더 클 경우 : left = mid +1
4. left > right 가 될 때까지 반복하여 구하는 값을 찾기

#### 시간복잡도

- 전체를 탐색하는 경우 O(n) 이분탐색 활용하면 O(log(n))

### 사진 설명 (gif)

![이분탐색](https://t1.daumcdn.net/cfile/tistory/221D4A3F5705041A1F)



### 간략화된 코드

```c++
#include <iostream>
using namespace std;

int main(){
  int findN;

  int data[10] = {1,2,3,4,5,6,7,8,9,15};

  cin >> findN;
  int left = 0, right = 9;

  while(left <= right){
    int mid = (left+right)/2;
    if(data[mid] > findN)
      	right = mid - 1;
    else if(data[mid] < findN)
      	left = mid + 1;
    else {
      cout << mid << endl;
      break;
    }
  }
  return 0;
}
```

- 참고문헌
  - [참고자료](https://wootool.tistory.com/62)

#### lower_bound (`<algorithm>` STL)

- 일종의 이진탐색으로 정렬된 데이터에서만 가능
- (시작위치, 끝위치, 찾고자 하는 데이터)
- 찾고자 하는 데이터가 8일 경우 8 이상인 값이 처음 나오는 위치를 구한다
- Ex)
	- {1, 3, 5, 7, 9, 11}에서, 8 이상인 값이 처음 나오는 위치를 구하는 과정: 
		1. 시작 위치= 1, 끝 위치= 6으로 설정한다.
		2. 시작 위치 1과 끝 위치 6의 중간 위치인 3((1+6) / 2)번째 값을 8과 비교한다.
		3. 5는 8보다 작으므로 시작 위치를 3 다음인 4로 설정한다.
		4. 시작 위치 4와 끝 위치 6의 중간 위치인 5번째 값을 8과 비교한다.
		5. 9는 8보다 크다. 이때에는 이분 탐색과 달리, 끝 위치를 중간 위치인 5로 설정한다.
			- 왜냐하면, 8 이상인 값이 처음 나오는 위치를 구하는 것이므로, 9가 Lower Bound가 될 수도 있다. 따라서 끝 값까지 포함한다.
		6. 시작 위치=4, 끝 위치=5이므로 중간 위치인 4번째 값을 8과 비교한다.
		7. 7은 8보다 작다. 따라서 시작 위치를 중간 위치+1 = 5로 설정한다.
		8. 시작 위치 = 끝 위치 = 5이므로 5번째 값인 9가 Lower Bound가 된다.

