#include <stdio.h>

int main()
{
  int n, i, j;
  char c;
  printf("No. of lines: ");
  scanf(" %d", &n);
  char code[20][100];
  j = 0;
  scanf("%c", &c);
 
  i = 0;
  while(i < n)
    {
      scanf("%c", &c);
      if(c == '\n')
	{
	  code[i][j] = 0;
	  i++;
	  j = 0;
	  continue;
	}
      code[i][j] = c;
      j++;
    }
  
  printf("Three Address code for the given input:\n\nt1 = ");
  i = 7;
  while(code[0][i] != ')')
    {
      printf("%c", code[0][i]);
      i++;
    }
  printf("\n");
  
  for(i = 2; i < n-2; i++)
    {
      printf("if(t1 == %c) goto A%c\n", code[i][6], code[i][6]);
    } 

  i = 10;
  while(code[n-2][i] != 0)
    {
      printf("%c", code[n-2][i]);
      i++;
    }
  printf("\ngoto last\n");

  for(i = 2; i < n-2; i++)
    {
      printf("A%c: ", code[i][6]);
      j = 9;
      while(code[i][j] != 0)
	{
	  printf("%c", code[i][j]);
	  j++;
	}
      printf("\ngoto last\n");
    }
  printf("last:\n");
  return 0;
}
