#include <cstdio>
#include <set>

using namespace std;

int main() {
    
int n[10];
set <int>ans;

 for (int i = 0; i < 10; i++) {
    scanf("%d", &n[i]);
    ans.insert(n[i]%42);
 }
 printf("%d", int(ans.size()));  

 return 0; 
}