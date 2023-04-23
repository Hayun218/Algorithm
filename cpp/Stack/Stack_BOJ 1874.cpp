#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int N;
    int idx = 0;
    stack<int> st;
    vector<char> ans;

    scanf("%d", &N);

    int num[N];

    for(int i = 0; i < N; i++)

        scanf("%d", num+i);

    for(int i = 1; i < N+1; i++){
        st.push(i);
        ans.push_back('+');
       
        while(!st.empty() && st.top() == num[idx]){
            idx++;
            ans.push_back('-');
            st.pop();
        }  
    }

    if(!st.empty()) printf("NO\n");
    else for (auto a : ans) printf("%c\n", a);
    
    return 0;
}