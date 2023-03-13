#include <stdio.h>

int main(void) {
	int num1, num2; // 입력받은 두 수
	int i;	// 반복문을 위한 변수
	
	printf("2개의 숫자를 입력 ");
	scanf("%d %d", &num1, &num2);
	
	for(i = 1; i * num1 <= 100 && i * num2 <= 100; i++){
	  if(num1 * i == num2 * i){
	    break;
	  }
	  else {
	    printf("%d\n", num1 * i);
	    printf("%d\n", num2 * i);
	  }
	}
	
	return 0;
}