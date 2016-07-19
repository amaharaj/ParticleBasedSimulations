#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
	int i,j,p,o,n;

   int Size = 1E4+1;
	float dt=0.005;
	int intsteps=0;
	
	int N=100, Counter=0, Atoms;
	
	float L=50;

   float *x, *y, *obsx, *obsy, *times;	
   x=malloc(Size*sizeof(float));
   y=malloc(Size*sizeof(float));
   obsx=malloc(Size*sizeof(float));
   obsy=malloc(Size*sizeof(float));
   times=malloc(Size*sizeof(float));

	float t=0,tmax=100;
	
   float F=-1;

	float m=1.0,g=9.8,kT=0;
	float k=1.0, zeta=1.0;
	
	float PI=3.14159265359;
	
	float r1=0,r2=0,rnd,xr=0,yr=0,r=0,F_int=0,F_toty=0,particles=0,MFPT,Sum=0;

   float F_x=0,F_y=0;
   float r_m = pow(2,1/6);
	
	FILE *outt,*mfpt;
	outt=fopen("ideal_traj.xyz","w");
   mfpt=fopen("mean_first_passage.prn","a");


   printf("Out");
   for(i=0;i<(float)L/2.5;i++){
      for(j=0;j<(float)L/2.5;j++){
         obsx[Counter] = 1.25 + i*2.5;
         obsy[Counter] = 1.25 + j*2.5;
         Counter += 1;
       }
   }
   printf("Out");
   Atoms = N + Counter;
   fprintf(outt,"%i\n",Atoms);
   fprintf(outt,"title\n");	
   for(p=0;p<N;p++){
      x[p]= (float)L/2;
	   y[p]= (float)L+5;
      fprintf(outt,"a%i %f %f 0 \n", p, x[p], y[p]);
   }
   i = 0;
   
   for(o=0;o<Counter;o++){
      fprintf(outt, "b%i%i %f %f 0 \n", o, n, obsx[o], obsy[o]);
   }
  
   intsteps=0;
   while(particles<N){
        
      if(intsteps%10==0){
         fprintf(outt,"%i\n",Atoms);
         fprintf(outt,"title\n");
      }
      for (i=0;i<N;i++){
         F_x = 0;
         F_y = 0;
         F = -1;
         for(j=0;j<Counter;j++){
            r = sqrt( pow(x[i]-obsx[j],2)+pow(y[i]-obsy[j],2) ) ;
            if (r < r_m) {
               F_int = (pow(r_m,12)/pow(r,13)) - 2*(pow(r_m,6)/pow(r,7));
               F_x += F_int*(x[i]-obsx[j])/r; 
               F_y += F_int*(y[i]-obsy[j])/r; 
            }
            F_toty = F + F_y;
         }
         r1=(float)rand()/RAND_MAX - 0.5;
         r2=(float)rand()/RAND_MAX - 0.5;
         xr=(float)F_x*dt/zeta + sqrt(24 * kT / zeta * dt)*r1;
         x[i] += xr;
         yr=(float)F_toty*dt/zeta + sqrt(24 * kT /zeta * dt)*r2;
         y[i] += yr;

         if (x[i] <= 0){  
            x[i] += L;
         }
         if (x[i] >= L){
            x[i] -= L;
         }

         if (y[i] < 0 && times[i] == 0){
            particles++;
            times[i] = t;             
         }
      
         if (intsteps%10==0){
            fprintf(outt,"a%i %f %f 0 \n", i, x[i], y[i]);
         }  

      }
     
      if (intsteps%10==0){
         for(o=0; o<Counter; o++){
            fprintf(outt, "b%i %f %f 0 \n", o, obsx[o], obsy[o]);
         }
      }
   
      t+=dt;
		intsteps++;
   
	}

   for(i=0;i< N;i++){
      Sum += times[i]; 
   }
   MFPT = Sum/particles;

   fprintf(mfpt, "%f %f \n", MFPT);

}

