#include <stdio.h>
#define SIZE 10000
double a[SIZE][SIZE];
int i;
double  b[SIZE][SIZE];
double  c[SIZE][SIZE];
void main( int argc, char **argv )
{
  int j,k;
  for( j = 0; j < SIZE; j++ )
  {
    for( i = 0; i < SIZE; i++ )
    {
      a[i][j] = b[i][j]+c[i][j];
    }
  }
}
