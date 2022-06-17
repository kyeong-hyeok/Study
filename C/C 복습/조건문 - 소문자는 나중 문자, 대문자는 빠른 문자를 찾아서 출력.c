#include <stdio.h>

int main(void) {
    int i;
    char s, p;
    s = getchar();
    if (s >= 'a' && s <= 'z') {
        while (1) {
            p = getchar();
            if (p == '0') break;
            if (p > s)
                s = p;
        }
    }
    else if (s >= 'A' && s <= 'Z') {
        while (1) {
            p = getchar();
            if (p == '0') break;
            if (p < s)
                s = p;
        }
    }
    printf("%c", s);
    return 0;
}
