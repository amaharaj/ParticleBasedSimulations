#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define L 20

int main(){

   int t, tmax=100;
  
   int i,j;

   int left,right,up,down;

   int state[L][L];
   int pstate[L][L];

   float rnd;

   for(i=0;i<L;i++){
      for(j=0; j<L; j++){
         state[i][j] = 0;
      }
   }

   state[L/2][L/2]=1;
   state[L/2-1][L/2]=1;
   state[L/2-1][L/2-1]=1;
   state[L/2][L/2-1]=1;
   state[L/2+1][L/2]=2;
   state[L/2-1][L/2+1]=2;
   state[L/2-1-1][L/2-1]=2;
   state[L/2][L/2-1-1]=2;
 
   FILE *out;
   out=fopen("Assignment7.xyz","w");

   for(t=0;t<tmax;t++){

   fprintf(out, "%i \n comment \n", L*L ); 
      for(i=0;i<L;i++){
         for(j=0; j<L; j++){
            pstate[i][j]=state[i][j];
            fprintf(out,"a %i %i %i \n", i, j, pstate[i][j] );
            
         }
      }

      for(i=0;i<L;i++){
         for(j=0;j<L;j++){
  
            if (i!=0)
               left=i-1;
            else
               left=L-1;

            if (j!=0)
                down=j-1;
            else
                down=L-1;   
            if (i!=L-1)
               right=i+1;
            else 
               right=0;

            if (j!=L-1)
               up=j+1;
            else
               up=0;


// Switch ON
            if (pstate[i][j]==0){
               int neigh=0;
               int m,n;
         
               for (m=-1; m<2; m++){
                  for (n=-1; n<2; n++){
                     if (m==0 && n==0){
                     }
                     if (pstate[i+m][j+n]==1){
                        neigh++;
                     }
                     if (neigh==2){
                        state[i][j]=1;
                     }   
                  }
               }               
            }
 
// Change to Dying
            else if (pstate[i][j]==1) {
               state[i][j]=2;
            }
// Change to Off
            else if (pstate[i][j]==2){
               state[i][j]=0;
            }
         }
      }
   }
   
}
