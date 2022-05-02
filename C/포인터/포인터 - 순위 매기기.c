#include <stdio.h>


int main(void) {
  int arr[5], *p, *k, tmp, i=0, j=0;
  char rank[5]={1,1,1,1,1};
  for(p=arr; p<arr+5; p++)
    scanf("%d", p);
  for(p=arr; p<arr+5; p++) {
    for(k=arr; k<arr+5; k++) {
      if(*p<*k) {  // 자신보다 큰 수가 있을 때 순위 하나씩 밀려남
        ++*(rank+i);
      }
    }
    i++;
  }
  for(p=arr; p<arr+5; p++) {  // 주소를 이용하여 반복문 구현
    printf("%d=r%d ", *p, *(rank+j));
    j++;
    }
  return 0;
}
