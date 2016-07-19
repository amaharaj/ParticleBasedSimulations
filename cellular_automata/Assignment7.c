#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define L 60

int main(){

   int t, tmax=100;
  
   int i,j;

   int left,right,up,down;

   int state[L][L];
   int pstate[L][L];

   float rnd;

   for(i=0;i<L;i++){
      for(j=0; j<L; j++){
         if (i < (L/2-5)){
         rnd = (float)rand()/RAND_MAX;
         if (rnd < 0.2){
            state[i][j] = 1;
         }
         else if (rnd > 0.2 && rnd < 0.6) { 
            state[i][j] = 2;
         }
         else {
            state[i][j] = 0;
         }
         }
         else {
            state[i][j] = 0;
         }
         
      }
   }

  // for(i=0;i<L;i++){
     // for(j=0;j<L;j++){
        // if (i < L/2){
           // state[i][i] = 1;
           // state[i-1][i-1] = 1;
         //   state[i+1][i+1] = 2;
       //     state[i+2][i+2] = 2;
     //    }
         
   //   }
 //  }

// Oscillator
   //state[L/2][L/2]=2;
   //state[L/2-1][L/2]=2;
   //state[L/2-1][L/2-1]=2;
   //state[L/2][L/2-1]=2;
   //state[L/2+1][L/2]=1;
   //state[L/2-1][L/2+1]=1;
   //state[L/2-1-1][L/2-1]=1;
   //state[L/2][L/2-1-1]=1;

// Beacon
   //int r;
//   for (r=0; r< 5; r++){
  //    state[L/2-2 - r*2][L/2]=1;
    //  state[L/2-2 - r*2][L/2+1]=2;
      //state[L/2-1 - r*2][L/2+1]=1;
   //}

  // state[L/2][L/2-1]=1;
   //state[L/2+1][L/2]=2;
   //state[L/2+1][L/2-1]=1;

//   int r;
  // for (r=0; r<7; r++){
    //  state[r][r+1]=2;
     // state[r][r+2]=2;
     // state[r][r-1]=1;
      //state[r][r-2]=2;
      //state[r][r]=1;

   //}
   //state[L/2+3][L/2+3]=2;
   //state[L/2-1+3][L/2+3]=1;
   //state[L/2-2+3][L/2+3]=2;
   //state[L/2+3][L/2+1+3]=1;
   //state[L/2-1+3][L/2+2+3]=2;

 
   FILE *out;
   out=fopen("Assignment7.xyz","w");

   for(t=0;t<tmax;t++){
      
//   for (i=0; i<L; i++) {
  //    for (j=0; j<L; j++) {
//         printf("%i ",state[i][j]);
// }
//printf("\n");
//}

//printf("\n");




fprintf(out, "%i \n comment \n", L*L ); 
      for(i=0;i<L;i++){
         for(j=0; j<L; j++){
            pstate[i][j]=state[i][j];
            fprintf(out,"a %i %i %i \n", i, j, pstate[i][j] );
            
         }
     // fprintf(out, "\n");
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
                        //if (neigh==2){
                          // state[i][j]=1;
                        //}
                     }
                  }
               }
            if (neigh==2 && neigh ){
               state[i][j]=1;
            }

            }
 
// Change to Dying
            if (pstate[i][j]==1) {
               state[i][j]=2;
            }
// Change to Off
            if (pstate[i][j]==2){
               state[i][j]=0;
            }
         }
      }
   }
   
}
