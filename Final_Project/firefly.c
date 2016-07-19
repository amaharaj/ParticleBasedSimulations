#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){

   // Initial Firefly Population
   int N=40,tmax=40;
   int t=0;
   float *x,*y,*I;
   x=malloc(N*sizeof(float));
   y=malloc(N*sizeof(float));
   I=malloc(N*sizeof(float));
//   z=malloc(N*sizeof(float));
   double z[N][2];
   float PI=3.14159265359;

   // parameter values
   float gamma=1.0;
   float beta0=1.0;
   float alpha=0.2;

   // Attraction Parameter
   float attract=0;

   int i=0,j=0,m=10;

   float rnd_posx=0, rnd_posy=0, epsilon=0, delta=0.97;

   float arg1x=0, arg1y=0, arg2x=0, arg2y=0;
   float arg11x=0, arg11y=0, arg22x=0, arg22y=0;
   float x_func1=0,y_func1=0,x_func2=0,y_func2=0,r=0;

   int max=0;
   float maxI=0;

   FILE *outsol, *outt, *outi, *outx, *outy;
   outt=fopen("Minimization_Distribution.prn","w");
   outi=fopen("Initial_Distribution.prn", "w");
   outx=fopen("xvals.prn", "w");
   outy=fopen("yvals.prn", "w");
   outsol=fopen("Intensities.prn","w");

   for (i=0;i<N;i++){
      rnd_posx = ((float)rand()/(RAND_MAX)*4);
      x[i] = rnd_posx;
      rnd_posy = ((float)rand()/(RAND_MAX)*4);
      y[i] = rnd_posy;
      z[i] = x[i], y[i];
      fprintf(outi,"%f %f %f\n",x[i],y[i], z[i]);
   }

   while (t<=tmax){

      for (i=0;i<N;i++){
         
         for (j=0;j<=i;j++){
            r = sqrt(pow(((float)x[i] - (float)x[j]),2) + pow(((float)y[i] - (float)y[j]),2));
            // Light Intensity
            arg1x = x[i];
            arg1y = y[i];
            arg2x = x[j];
            arg2y = y[j];

            arg11x = i*(pow((x[i]),2))/acos(-1);
            arg11y = i*(pow((y[i]),2))/acos(-1);
            arg22x = j*(pow((x[j]),2))/acos(-1);
            arg22y = j*(pow((y[j]),2))/acos(-1);

            x_func1 = -sin(arg1x)*pow(sin(arg11x),2*m);
            y_func1 = -sin(arg1y)*pow(sin(arg11y),2*m);
            x_func2 = -sin(arg2x)*pow(sin(arg22x),2*m);
            y_func2 = -sin(arg2y)*pow(sin(arg22y),2*m);

            I[i] = x_func1 + y_func1;
            I[j] = x_func2 + y_func2;

         //   fprintf(outsol,"%f %f\n", I[i], I[j]);

            alpha = alpha*delta;
            epsilon = ((float)rand()/(RAND_MAX) - 0.5); 
         
            if (I[j]>I[i]){   
               attract=beta0*exp(-gamma*pow(r,2));
               x[i] = x[i] + attract*(x[j]-x[i]) + alpha*epsilon;
               y[i] = y[i] + attract*(y[j]-y[i]) + alpha*epsilon;
               I[i] = I[j];
            }
            //if (t==(tmax)){
              // fprintf(outt,"%f \t",x[i]);
            //}
           // if (t==(tmax) && i==(N-1)){
             //  fprintf(outt,"%f \n",y[i]);
            //}
         }
         if (t==(tmax)){
            fprintf(outt,"%f %f\n",x[i],y[i]);
         }
      }

      // Rank order
      for (max=0; max<tmax; max++){
         if (I[max] < maxI){
            maxI = I[max];
            printf("%f\n", maxI);
        //    printf("%d\n", x);
         }
      }
   t = t + 1;
   
   }
}
