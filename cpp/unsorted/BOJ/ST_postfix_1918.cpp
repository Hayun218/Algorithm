#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    char str[1000];
    char result[1000];
    stack<char> p;
    int Idx = 0;

    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z') result[Idx++] = str[i];
        if (str[i] == '(') p.push(str[i]); 
        if(str[i] == ')') {
            while(p.top() != '(') {
                result[Idx++] = p.top();
                p.pop();
            }
            p.pop();
        }
        if(str[i] == '*' || str[i] == '/'){
            while(!p.empty() && (p.top() == '*' || p.top() == '/')){
                result[Idx++] = p.top();
                p.pop();
            }
            p.push(str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!p.empty() && p.top() != '('){
                result[Idx++] = p.top();
                p.pop();
            }
            p.push(str[i]);
        }
    }
    while(!p.empty()){
        result[Idx++] = p.top();
        p.pop();
    }
    result[Idx] = '\0';
    printf("%s", result);
    return 0;
}
/* 피연산자: 바로 출력한다.
사칙연산자: 스택이 비어 있거나, top이 여는 괄호거나, 스택의 top 연산자보다 우선순위가 높을 경우 push  아니라면, 앞의 조건을 만족할 때까지 차례차례 pop해서 출력한다. 그리고 이번 연산자를 push한다.
여는 괄호: (를 스택에 push한다.
닫는 괄호: (가 나올 때까지 스택을 계속 pop하여 pop한 연산자를 출력하고, 마지막에 (도 pop한다.

마지막으로 스택이 빌 때까지 pop해 가며 pop한 연산자를 순서대로 출력합니다. 
=> switch 로도 구현헤 보자
*/