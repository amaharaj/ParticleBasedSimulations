#include "stdio.h"
#include "stdlib.h"
#include <math.h>

int main(){

   int i, j, N=10000, Niter=10000;
   float r;
   float avg; 
   float x;

   FILE *out;
   out = fopen("CLT_numbers.prn","w");

   for(i=0;i<Niter;i++){
      avg=0;
      for(j=0;j<N;j++){
         x=((float)rand()/(RAND_MAX));

         r = sqrt(-2*log(1-x));
         r = r - 1.253;
         // use inverse transform sampling
         r = r/sqrt(0.429);
         avg+=r;
      }
      avg=avg*sqrt(1/(float)N);
      fprintf(out, "%f\n", avg);
   }


}
