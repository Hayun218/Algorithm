// 다시해보기 거의 copy paste 했다.. ㅠㅠ 
#include <cstdio>
#include <stack>
using namespace std;

const int maxN = 2e5 + 3;

int n, q;
int gph[maxN], pnt[maxN], q1[maxN * 2], q2[maxN * 2];
stack<bool> ans;

inline int find(int u) {
	if (u == pnt[u]) return u;
	return pnt[u] = find(pnt[u]);
}

inline void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u > v) swap(u, v);
	if (u == v) return;
	pnt[u] = v;
}

int main() {
	int i, a;
	scanf("%d %d", &n, &q);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		gph[i] = a;
		pnt[i] = i;
	} gph[1] = 1;
	for (i = 1; i <= n + q - 1; i++) {
		scanf("%d", &a);
		if (a) scanf("%d %d", &q1[i], &q2[i]);
		else scanf("%d", &q1[i]);
	}
	for (i = n + q - 1; i; i--) {
		if (q2[i]) {
			if (find(q1[i]) == find(q2[i])) ans.push(1);
			else ans.push(0);
		}
		else {
			merge(q1[i], gph[q1[i]]);
		}
	}
	while (!ans.empty()) {
		ans.top() ? puts("YES") : puts("NO"); ans.pop();
	}

	return 0;
}
