#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

int main(){
	int A = 1;
	int f = 7;
	float C = 2*M_PI;
	float j=0;
	float z=0;
	float fun=0;
	for(float t=0; t<1; t+=0.01){
		fun = A*sin(2*M_PI*f*t + C);
	}
	for(float i=0; i<1; i+=1/8){
		fun = A*sin(2*M_PI*f*i + C);
		j = i;
		z = fun;
	}
return 0;
}
