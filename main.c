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

char *
EditDistance (char *str1, char *str2)
{
  if (strlen (str1) == 0)
    return strlen (str2);

  if (strlen (str2) == 0)
    return strlen (str1);

  if (str1[0] == str2[0])
    return EditDistance (&str1[1], &str2[1]);
  else
    return 1 + min (
		     //insertion
		     EditDistance (str1, &str2[1]),
		     //substitution
		     EditDistance (&str1[1], &str2[1]),
		     //deletion
		     EditDistance (&str1[1], str2));
}

int
main ()
{
  printf ("The min number of edits = %d", EditDistance ("dinosaur", "dinohouse"));

  return 0;
}
