#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
	int i, imax=1000000;
	
	float x, y, z, vx, vy, vz, ax, ay, az, vhx, vhy, vhz; 
	float t;
	float dt=0.01;
	
	float zeta=1.0;
	float m=1.0;
	float kT=3.0;
	
	float rndx,rndy,rndz;
	
	FILE *out, *out2, *out3;
	out=fopen("ld1part_x.prn","w");
   out2=fopen("ld1part_y.prn","w");
   out3=fopen("ld1part_z.prn","w");
	
	x=0;
   y=0;
   z=0;
	vx=1.0;
   vy=1.0;
   vz=1.0;
	ax=1.0;
   ay=1.0;
   az=1.0;

	
	for(i=0;i<imax;i++){
	
		vhx=vx+0.5*ax*dt;
      vhy=vy+0.5*ay*dt;
      vhz=vz+0.5*az*dt;
		
		x=x+vhx*dt;
      y=y+vhy*dt;
      z=z+vhz*dt;
		
		rndx=(float)rand()/RAND_MAX-0.5;
      rndy=(float)rand()/RAND_MAX-0.5;
      rndz=(float)rand()/RAND_MAX-0.5;
		
		ax=-zeta/m*vhx+sqrt(24*kT*zeta/(m*m*dt))*rndx;
      ay=-zeta/m*vhy+sqrt(24*kT*zeta/(m*m*dt))*rndy;
      az=-zeta/m*vhz+sqrt(24*kT*zeta/(m*m*dt))*rndz;
		
		vx=vhx+0.5*ax*dt;
      vy=vhy+0.5*ay*dt;
      vz=vhz+0.5*az*dt;
		
		fprintf(out,"%f\n",x);
      fprintf(out2,"%f\n",y);
      fprintf(out3,"%f\n",z);
		
		printf("%i\n",i);
	}
	
}
