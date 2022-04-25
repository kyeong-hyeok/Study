int main(void) {
  int a,b,c,d,e,f;
  scanf("%d/%d/%d", &a, &b, &c);
  scanf("%d/%d/%d", &d, &e, &f);  
  if (a>d)
    printf("%d/%02d/%02d", d,e,f);
  else if (a<d)
    printf("%d/%02d/%02d", a,b,c);
  else {
    if (b>e)
      printf("%d/%02d/%02d", d,e,f);
    else if (b<e)
      printf("%d/%02d/%02d", a,b,c);
    else {
      if (f>c)
        printf("%d/%02d/%02d", d,e,f);
      else
        printf("%d/%02d/%02d*", a,b,c);
      }
  }
  return 0;
}  
