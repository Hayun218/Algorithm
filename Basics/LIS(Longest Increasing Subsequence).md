## LIS(Longest Increasing Subsequence) 알고리즘 & 추적
```
최장증가부분수열

```

### 개념
![일반수열](https://t1.daumcdn.net/cfile/tistory/257C96385888A49106)

이러한 수열이 있을 때 여기서 LIS를 찾는다면!

![LIS](https://t1.daumcdn.net/cfile/tistory/217AA83B5888A4B936)

여기서 빨간 색으로 된 부분을 의미한다

##### 앞에서부터 뒤로 숫자를 선택하며 부분 수열을 만들 때 증가하는 숫자들을 순서대로 고르고, 고른 부분 수열의 길이가 최대 길이가 되도록 숫자를 선택하는 것을 의미한다

### 구현방식

#### DP O(N^2)
- dp[x] = x번째 수를 마지막 원소로 가지는 LIS의 길이
- dp[x]가 이미 채워져 있다면 x보다 큰수의 y의 수열값 arr[y]도 arr[x]보다 크다면 dp[y]는 dp[x]+1이 될 수 있음
- 2중 포문으로 코드 구현

```c++
for(int i = 0; i < N; i++){
	if(dp[i] == 0) dp[i] = 1;
	for(int j = 0; j < i; j++){
		if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
		}
	}
}
```

#### Segment Tree O(NlogN)
- arr[x]의 위치에 x를 마지막 원소로 가지는 LIS의 길이를 업데이트 시켜줌
- 매번 자신보다 작은 구간에서 최댓값을 찾는 쿼리를 돌리고 최댓값+1을 업데이트 하는 방식

#### 이분탐색 O(NlogN)
- 수열을 처음부터 탐색 (O(N))
- LIS를 유지하기 위한 최적의 위치에 수를 삽입하는 방식
- 이 때 자리를 찾기 위해서 lower_bound() O(logN) 

- 최적의 위치 구하기
1. 벡터를 생성하고 -INF(나올 수 없는 작은 값)을 삽입
2. 벡터의 마지막 원소와 수열의 값을 비교하여 수열의 값이 클 경우는 push_back한 뒤 LIS의 크기 1 증가/ 작은 경우는 lower_bound()를 통해 최적의 장소를 찾은 후 그 자리 값을 해당 수열의 원소로 대체

##### 그림으로 설명
* 처음 값은 그대로 벡터 안으로 삽입

![1](https://t1.daumcdn.net/cfile/tistory/232409345888AEC125)

* 20이 10보다 크므로 그대로 삽입하고 LIS 증가

![2](https://t1.daumcdn.net/cfile/tistory/2266F5485888AF3518)

* 40도 동일하게 그대로 삽입

![3](https://t1.daumcdn.net/cfile/tistory/2266F5485888AF3518)

* 25는 40보다 작으므로 lower_bound를 통해 40이 25로 대체됨

![4](https://t1.daumcdn.net/cfile/tistory/2139C4395888AFEA21)

* 위와 같은 작업을 반복적으로 하면서 최종적으로는 ...

![최종](https://t1.daumcdn.net/cfile/tistory/2708BF3D5888B32729)

==> LIS 는 6

* 소스코드

```c++
int ans = 0;
vt.push_back(-INF);
for(int i = 0; i < N; i++){
	scanf("%d" &x)
	if(x > vt.back()){
		vt.push_back(x);
		ans++;
	}
	else {
		auto it = lower_bound(vt.begin(), vt.end(), x);
		*it = x;
	}
}
```


####주의할점 : lower_bound 를 통해 뒤에 들어온 값이 이전 값들 보다 전에 위치할 수 있으므로 최종적으로 벡터 내에 있는 값들이 LIS를 이루는 요소와 무관 할 수 있다!!! ==> 그럼 해당 배열은 어떻게 찾을 수 있나?? 알아보기!! => 추적을 통해 알 수 있다!!
	
[참고자료]<https://jason9319.tistory.com/113>
[참고할수있는자료]<https://www.crocus.co.kr/583>

## LIS 추적!
- lis 함수를 구현해도 실제 LIS 배열을 알 수 없지만 알 수 있는 방법이 있다!!
1. ans 이라는 pair 배열을 만든다
	- first : pLis 및 pos-1 을 담고 있음 (실제 값이 들어갈 수 있는 위치)
	- second : arr[pArr]을 담고 있다 (실제 값)

#### Example
- 1 6 2 5 7 3 5 6인 경우

- ans배열에는 다음과 같이 들어간다.

	- first ::  0 1 1 2 3 2 3 4 (인덱스 바뀐 경우도 있어서 겹치는 인덱스 존재)

	- second :: 1 6 2 5 7 3 5 6

- 이 값을 first를 기준으로 **뒤에서 부터 조사**해오면

	- first가 4일때 (6) - > first가 3일때 (5) -> first가 2일때 (3) 
		-> first가 1일때 (2) -> first가 0일때(1)이다.


- 스택에 담아 역출력하면 1,2,3,5,6이라는 실제 배열을 구할 수 있다.



[참고자료]<https://www.crocus.co.kr/681>