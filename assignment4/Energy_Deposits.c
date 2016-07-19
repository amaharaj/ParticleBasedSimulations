#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define N 10000

int main(){

	FILE *outt,*oute;
	outt=fopen("ideal_traj.xyz","w");
   oute=fopen("Energy_Binds.txt","w");   

   float E[N];
   float x[N];
   float y[N];
   float rhoE[1000]={0};
   float width=5.0;

   float v=0, dt=1, t=0, m=1, tmax=1000;
   float rnd;   

   float p=0.05;
   float Elost=0.2;
   float Ethresh=0.1;

   int i,Counter;

   fprintf(outt,"%i\n",N);
   fprintf(outt,"title \n");

   for(i=0;i<N;i++){
      x[i]=0;
      y[i]=i*0.1;
      E[i]=4.0+(float)rand()/RAND_MAX;
      fprintf(outt, "a%i %f %f 0\n",i, x[i],y[i]);
   }

   while(Counter<N){
      Counter = 0;
      fprintf(outt,"%i\n",N);
      fprintf(outt,"title \n");

      for(i=0;i<N;i++){
         if (E[i]>Ethresh){
            rnd = (float)rand()/RAND_MAX;
            if (rnd<p){
               rhoE[(int)(x[i]/width)]+=Elost;
               E[i]-=Elost;
            }
            else{
               v=sqrt(2*E[i]/m);
               x[i]+=v*dt;
            }  
      
         } else {
         Counter++;
        }
       fprintf(outt, "a%i %f %f 0\n",i, x[i],y[i]);
      }
      t+=dt;
   }

   for(i=0;i<1000;i++){
      fprintf(oute, "%f\n", rhoE[i]);
   }

}
