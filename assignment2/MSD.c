#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){

  int N=1E6+1;
  int i=0, imax;
  int nwindows;

  float r;
  float avg_dx,avg_dy,avg_dz;
  float avg_dx2,avg_dy2,avg_dz2;
  float avg_dr, avg_dr2;
  float readx, ready, readz;
  float slopex, slopey, slopez;
  float *x, *y, *z;
  x=malloc(N*sizeof(float));
  y=malloc(N*sizeof(float));
  z=malloc(N*sizeof(float));
  int dt;
  int pos1, pos2;

  FILE *in, *in2, *in3, *out, *out2;
  in=fopen("ld1part_x.prn","r");
  in2=fopen("ld1part_y.prn","r");
  in3=fopen("ld1part_z.prn","r");
  out=fopen("msd.prn","w");


  while(!feof(in)){
    fscanf(in,"%f",&readx);
    if(!feof(in)){
      x[i]=readx;
      i++;  
    }
}
i=0;
  while(!feof(in2)){
    fscanf(in2,"%f",&ready);
    if(!feof(in2)){
      y[i]=ready;
      i++; 
    }
}
i=0;
  while(!feof(in3)){
    fscanf(in3,"%f",&readz);
    if(!feof(in3)){
      z[i]=readz;
      i++; 
    }
}
  imax=i;
  for(dt=0;dt<imax/100;dt++){
    if (dt%100 == 0) 
      printf("%i\n", dt);
    pos1 = 0;
    pos2=pos1+dt;

    avg_dx=0;
    avg_dy=0;
    avg_dz=0;
    avg_dx2=0;
    avg_dy2=0;
    avg_dz2=0;
    nwindows=0;
    while(pos2<imax){
      avg_dx+= x[pos2]-x[pos1];
      avg_dy+= y[pos2]-y[pos1];
      avg_dz+= z[pos2]-z[pos1];
      avg_dx2+= pow(x[pos2]-x[pos1],2.0);
      avg_dy2+= pow(y[pos2]-y[pos1],2.0);
      avg_dz2+= pow(z[pos2]-z[pos1],2.0);
      nwindows++;
      pos1 += fmax(dt,250);
      pos2=pos1+dt;
    }
    avg_dx=avg_dx/(float)nwindows;
    avg_dx2=avg_dx2/(float)nwindows;
    avg_dy=avg_dy/(float)nwindows;
    avg_dy2=avg_dy2/(float)nwindows;
    avg_dz=avg_dz/(float)nwindows;
    avg_dz2=avg_dz2/(float)nwindows;

    avg_dr = sqrt(pow(avg_dx,2) + pow(avg_dy,2) + pow(avg_dz,2));
    avg_dr2 = avg_dx2 + avg_dy2 + avg_dz2;
    r = avg_dr2 - pow(avg_dr,2);
    fprintf(out,"%i %f\n", dt, r);
}
}
  

