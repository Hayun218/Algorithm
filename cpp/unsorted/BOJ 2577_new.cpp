#include<stdio.h>

int a,b,c;
int res[10],i;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	a*=b*c;

	while(a){
		res[a%10]++;
		a /= 10;
	}

	for(i = 0; i < 10; i++)
        printf("%d\n", res[i]);

    return 0;
}