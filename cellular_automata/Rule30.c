#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define L 100

int main(){

   int t, tmax=100;
  
   int i;

   int left,right;

   int state[L];
   int pstate[L];

   float rnd;

   for(i=0;i<L;i++){
      rnd=(float)rand()/RAND_MAX;
      if(rnd<0.5)
         state[i]=0;
      else
         state[i]=1;
   }
   state[L/2]=1;

   FILE *out;
   out=fopen("inclass_rule30.prn","w");

   for(t=0;t<tmax;t++){
      for(i=0;i<L;i++){
         pstate[i]=state[i];
         fprintf(out,"%i ", state[i]);
      }
      fprintf(out,"\n");
      for(i=0;i<L;i++){

         if (i!=0)
            left=i-1;
         else
            left=L-1;

         if (i!=L-1)
            right=i+1;
         else 
            right=0;
         // XOR needs to be programed since c does not have operator
         if (pstate[i]==0){
            if (pstate[left] && pstate[right])
               state[i]=0;
            if (pstate[left] && !pstate[right])
               state[i]=0;
            if (!pstate[left] && pstate[right])
               state[i]=1;
            if (!pstate[left] && !pstate[right])
               state[i]=1;
         }else {
            if (pstate[left] && pstate[right])
               state[i]=0;
            if (pstate[left] && !pstate[right])
               state[i]=1;
            if (!pstate[left] && pstate[right])
               state[i]=1;
            if (!pstate[left] && !pstate[right])
               state[i]=0;            
         }
      }
   }
}
