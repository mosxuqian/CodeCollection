
/* Sort Utility
   by Philip J. Erdelsky
   pje@efgh.com
   http://www.alumni.caltech.edu/~pje/
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "StaticMergeSort.h"


#define MAX_LINE 255

unsigned first_column = 0;
unsigned last_column = MAX_LINE - 1;

static int compare(void *p, void *q, void *pointer)
{
  unsigned i = 0;
  unsigned char * pp =  ((unsigned char *) p);
  unsigned char * qq = ((unsigned char *) q);
  
  for (i = 0; i <= last_column; i++)  {
    if (i >= first_column)  {
      int n = *pp - *qq;
      if (n != 0)
        return n;
    }
    if (*pp == 0 && *qq == 0)
      return 0;
    if (*pp != 0)
      pp++;
    if (*qq != 0)
      qq++;
  }
  return 0;
}

static int read_record(FILE *f, void *buffer, void *pointer)
{
  int n = 0;
  int c;
  if (feof(f) || (c = getc(f)) == EOF) return 0;
  while (c != '\n' && c != EOF)  {
    if (n < MAX_LINE)
      ((char *) buffer)[n++] = c;
    else {
      fputs("SORT: Input line is too long\n", stderr);
      exit(1);
    }
    c = getc(f);
  }
  ((char *) buffer)[n++] = 0;
  return n;
}

static int write_record(FILE *f, void *buffer, void *pointer)
{
  return fputs((char *) buffer, f) != EOF && putc('\n', f) != EOF;
}

static void invalid_column_number(void)
{
  fputs("SORT: Invalid column number\n", stderr);
  exit(1);
}

static unsigned get_number(char *s)
{
  unsigned n = 0;
  while (*s != 0)  {
    if (isdigit(*s))
      n = 10 * n + *s++ - '0';
    else
      invalid_column_number();
    if (n > MAX_LINE - 1)
      invalid_column_number();
  }
  return n;
}

int main(int argc, char **argv)
{
  int n;
  if (argc > 1)
    first_column = get_number(argv[1]);
  if (argc > 2)
    last_column = get_number(argv[2]);
  if (first_column > last_column)
    invalid_column_number();
  n = stable_merge_sort(stdin, stdout, read_record, write_record,
    compare, NULL, MAX_LINE+1, 15000/(MAX_LINE+5), NULL);
  if (n != 0)  {
    static char *ERROR[] =  {
      "INSUFFICIENT MEMORY",
      "FILE CREATION ERROR",
      "FILE WRITE ERROR"
    };
    fprintf(stderr, "SORT: %s\n", ERROR[n-1]);
    return 1;
  }
  return 0;
}
