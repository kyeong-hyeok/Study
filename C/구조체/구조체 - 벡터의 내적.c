#include <stdio.h>

struct V {
  int x;
  int y;
  int z;
};

int main(void) {
  struct V vec[3];
  scanf("%d %d %d", &vec[0].x, &vec[0].y, &vec[0].z);
  scanf("%d %d %d", &vec[1].x, &vec[1].y, &vec[1].z);
  vec[2].x = vec[0].x * vec[1].x;
  vec[2].y = vec[0].y * vec[1].y;
  vec[2].z = vec[0].z * vec[1].z;
  printf("%d %d %d\n", vec[2].x, vec[2].y, vec[2].z);
  printf("%d", vec[2].x + vec[2].y + vec[2].z);
  return 0;
}
