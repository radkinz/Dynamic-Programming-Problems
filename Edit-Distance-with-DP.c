/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int
min (int a, int b, int c)
{

  int result;
  if (a < b)
    if (a < c)
      result = a;
    else
      result = c;
  else if (b < c)
    result = b;
  else
    result = c;


  return result;
}

int
EditDistance (char *str1, char *str2)
{
  //initalize table
  int magictable[strlen (str1) + 1][strlen (str2) + 1];

  //base case
  for (int i = 0; i <= strlen (str1); i++)
    {
      magictable[i][0] = i;
    }

  for (int j = 0; j <= strlen (str2); j++)
    {
      magictable[0][j] = j;
    }

  //fill in rest of table
  for (int i = 1; i <= strlen (str1); i++)
    {
      for (int j = 1; j <= strlen (str2); j++)
	{

	  if (str1[i - 1] == str2[j - 1])
	    {
	      magictable[i][j] = magictable[i - 1][j - 1];
	    }
	  else
	    {
	      magictable[i][j] = 1 +
		min (magictable[i][j - 1], magictable[i - 1][j],
		     magictable[i - 1][j - 1]);
	    }
	}
    }

  return magictable[strlen (str1)][strlen (str2)];
}

int
main ()
{
  printf ("The min number of edits = %d", EditDistance ("at", "casdft"));

  return 0;
}
