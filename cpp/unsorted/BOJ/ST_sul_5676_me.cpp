#include <iostream>
#include <algorithm>
using namespace std;

#define maxN 100001
#define INT 0x7fff0000s

int a[maxN], seg[maxN * 4];

void init(int node, int L, int R){
    if(L == R){
        if(a[L] > 0)  seg[node] = 1;
        else if(a[L] < 0)  seg[node]= -1;
        else if(a[L] == 0) seg[node] = 0;
        return;
    }
    int mid = (L+R) >> 1;
    init(node << 1, L, mid);
    init((node << 1) + 1, mid + 1, R);
    seg[node] = seg[node << 1] * (seg[(node << 1) + 1]);
    return;
}

void update(int pos, int val, int node, int L, int R){
    if(pos < L || pos > R) return;  
    if(L == R){
        if(val > 0) seg[node] = 1;
        else if(val < 0) seg[node] = -1;
        else if(val == 0) seg[node] =  0;
        return;
    }
    int mid = (L+R) >> 1;
    update(pos, val, node << 1, L, mid);
    update(pos, val, (node << 1)+1, mid+1, R); 
    seg[node] = seg[node << 1] * seg[(node << 2) + 1];
    return;
}

int query(int s, int e, int node, int L, int R){
    if(s > R || L > e) return 1; // [left, right] 범위가 [lo, hi]와 전혀 겹치지 않는 경우
    if(s <= L && R <= e) return seg[node]; // [start, end] 범위가 [left, right]에 완전히 속해 있는 경우
    int mid = (L+R) >> 1;
    return seg[node] = query(s, e, node << 1, L, mid) * query(s, e, (node << 1) + 1, mid+1, R); //범위가 일부분 겹치는 경우
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    while(cin >> n >> k){
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        init(1, 1, n);
        while(k--){
            char command; int u, v;
            cin >> command >> u >> v;

            if(command == 'C')
                update(u, v, 1, 1, n);

            if(command == 'P'){
                int ans = query(u, v, 1, 1, n);
                if(ans == 0)
                    cout << '0';
                else if(ans > 0)
                    cout << '+';
                else if(ans < 0)
                    cout << '-';
            }
        }
        cout << '\n';
    }
    return 0;
}