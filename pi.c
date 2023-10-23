#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


int main() {

  int r = 10000000;
  float x;
  float y;
  float dentro, fora = 0;

  FILE *gnuplot = popen("gnuplot", "w");
  fprintf(gnuplot, "plot '-'\n");

  for (int i=0; i<r; i++) {
    x = rand() % r+1;
    y = rand() % r+1;

    if ((pow(x, 2) + pow(y, 2)) < pow(r, 2)) {
      dentro += 1;
      fprintf(gnuplot, "%g %g\n", x, y);
    }
    else {
      fora += 1;
    }
  }


  float pi = (4 * (dentro/(dentro+fora)));
  printf("%f", pi);
  fprintf(gnuplot, "e\n");
  fflush(gnuplot);
  sleep(100);
  return 0;
}
