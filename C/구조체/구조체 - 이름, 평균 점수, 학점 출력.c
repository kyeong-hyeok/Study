#include <stdio.h>

struct student {
  char name[20];
  int grade[3];
};

int main(void) {
  int i, n;
  double avg;
  struct student s[20];
  scanf("%d", &n);
  for(i=0; i<n; i++) 
    scanf("%s %d %d %d", s[i].name, &s[i].grade[0], &s[i].grade[1], &s[i].grade[2]);
  for(i=0; i<n; i++) {
    avg = (s[i].grade[0] + s[i].grade[1] + s[i].grade[2])/3.0;
    printf("%s %.1f ", s[i].name, avg);
    if (avg>=90) printf("A");
    else if (avg>=80) printf("B");
    else if (avg>=70) printf("C");
    else printf("F");
    printf("\n");
    }
  return 0;
}
