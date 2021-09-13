## Fenwick Tree

``` in my words
세그먼트 트리에서 오른쪽 자식 노드들을 전부 지운 모양을 가지고 있으며 메모리를 더 절약할 수 있다.
비트를 사용하여 구현하므로 인덱스 1로 시작한다.

sum 함수의 경우 부분합을 구하는 함수로 i -= (i & (-i))
update 함수의 경우 i 인덱스의 값을 바꾸었을 때 부모 노드도 바꾸기 위한 함수i += (i & (-i))
```


- 세그먼트 트리의 변형! => 메모리를 더 절약하기 위한 방법

![펙윅트리의 모양](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory&fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F257FDE4858C9211F04CFB4)

- 펜윅트리는 비트연산자를 쓰므로 인덱스를 1부터 시작!
![펙윅](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory&fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F2333064C58C9236F0EF241)

### 5-15 구간합을 비트로 바라보았을 때
![비트](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory&fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F2606F64958C92AFC248ECF)

- 8 + 12 + 14 + 15를 할 때 1000 + 1100 + 1110 + 1111이라는 비트로 바뀌는데
- 밑에서부터 1111 -> 1110 -> 1100 -> 1000으로 바뀐다 
	- 즉! 1이 있는 **가장 오른쪽(최하위 비트)가 0으로 바뀌는 모습**을 볼 수 있다.
	- 1이 나타나느 최하위 비트란 101 일때는 맨 마지막 1. 1100 일땐 세번째 자릿수에 있는 1을 의미 


- 함수 구현을 알기 전에!! 비트 연산자를 살펴보자~
	- i & -i의 의미는 어떤 값에서 1이 나타나는 최하위 비트를 알려주는 역할을 하게 된다.

### 5를 업데이트 할 때
![업데이트](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory&fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F2525F04758C931A8357DD0)

- 101 -> 1100 -> 1000 -> 10000 
	

#### Sum 함수


```
long long sum(vector<ll> &tree, int i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= (i & -i); // 최하위 비트 지우기 
    }
 
    return ans;
}
```

- i -= (i & -i)이라 함은 i에서 1이 나타나는 최하위 비트를 빼준다는 것을 의미하게 되고 부분 합에서 다음 더해야 할 부분으로 향하는 것을 알 수 있다.

#### update 함수

```
void update(vector<ll> &tree, int i, ll diff)
{
    while (i < tree.size())
    {
        tree[i] += diff;
        i += (i & -i);
    }
}
```

- i += (i & -i)는 위와 반대로 i에서 1이 나타나는 최하위 비트에 1을 더해준다는 의미

[참고자료]<https://www.crocus.co.kr/666>
