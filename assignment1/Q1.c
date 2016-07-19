#include "stdio.h"
#include "stdlib.h"
#include <math.h>

int main(){

   int i, N=100000;
   float r;
   float x; 
   

   FILE *out;
   out = fopen("random_numbers.prn","w");

   for(i=0;i<N;i++){

      x=(float)rand()/RAND_MAX;
      r=acos(1-2*x);
      fprintf(out, "%f %f\n", r, x);
   }


}
