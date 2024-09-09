#include <stdio.h>

void rec_func(int r);

int main()
{
  int a = 1234;
  int b = 5678;
  
	int r = 3;
  printf("--- f›r rec_func ---\n");
  rec_func(r);
  printf("--- efter rec_func ---\n");
  
  return 0;
}

void rec_func(int r) 
{
  printf("--- inde i rec_func ---\n");

  printf("f›r - Value of   m: %d\n", r);
  printf("f›r - Address of m: %d\n", &r);

  if(r>0) 
  {
    rec_func(r-1);
  }
  
  printf("efter - Value of   m: %d\n", r);
  printf("efter - Address of m: %d\n", &r);

  printf("--- afslut rec_func ---\n");
}