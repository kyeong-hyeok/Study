#include <stdio.h>

struct student {
  char name[10];
  int grade;
};

int main(void) {
  int i, sum=0, j;
  double avg;
  struct student s[5];
  for(i=0; i<5; i++) {
    scanf("%s %d", s[i].name, &s[i].grade);
    sum += s[i].grade;
    }
  avg = sum / 5.0;
  for(j=0; j<5; j++) {
    if(s[j].grade<=avg) 
      printf("%s\n", s[j].name);
    }
  return 0;
}
