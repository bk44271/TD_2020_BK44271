#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#define USE MATH DEFINES
#include "math.h"

using namespace std;

float syginf (int A, int f){
	float m = 0;
	
	ofstream outfile;
	outfile.open("syginf.txt", ios::trunc | ios::out);
	
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		outfile << (float)m << "\n";
	}
	outfile.close();
}

float zad1a (int A, int f){
	float m = 0;
	float ka = 1.5;
	float kp = 1;
	float za = 0;
	float zp = 0;
	
	ofstream outfile;
	outfile.open("za1.txt", ios::trunc | ios::out);
	
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		za = (ka*m+1) * cos(2*M_PI*f*t);
		outfile << (float)za << "\n";
	}
	outfile.close();

	ofstream outfile2;
	outfile2.open("zp1.txt", ios::trunc | ios::out);
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		zp = cos(2*M_PI*f*t + kp*m);
		outfile2 << (float)zp << "\n";
	}
	outfile2.close();
}

float zad1b (int A, int f){
	float m = 0;
	float ka = 11;
	float kp = 2.5;
	float za = 0;
	float zp = 0;
	
	ofstream outfile;
	outfile.open("za2.txt", ios::trunc | ios::out);
	
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		za = (ka*m+1) * cos(2*M_PI*f*t);
		outfile << (float)za << "\n";
	}
	outfile.close();

	ofstream outfile2;
	outfile2.open("zp2.txt", ios::trunc | ios::out);
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		zp = cos(2*M_PI*f*t + kp*m);
		outfile2 << (float)zp << "\n";
	}
	outfile2.close();
}

float zad1c (int A, int f){
	float m = 0;
	float ka = 72;
	float kp = 18;
	float za = 0;
	float zp = 0;
	
	ofstream outfile;
	outfile.open("za3.txt", ios::trunc | ios::out);
	
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		za = (ka*m+1) * cos(2*M_PI*f*t);
		outfile << (float)za << "\n";
	}
	outfile.close();

	ofstream outfile2;
	outfile2.open("zp3.txt", ios::trunc | ios::out);
	for(float t=0; t<1; t+=0.01){
		m = A*sin(2*M_PI*f*t);
		zp = cos(2*M_PI*f*t + kp*m);
		outfile2 << (float)zp << "\n";
	}
	outfile2.close();
}

int main(){
	int A = 1;
	int f = 7;
	
	syginf(A, f);
	zad1a(A, f);
	zad1b(A, f);
	zad1c(A, f);
return 0;
}
