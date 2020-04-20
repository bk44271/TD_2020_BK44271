//ALGO2 IS1 221B LAB10
//Krystian Bielak
//bk44271@zut.edu.pl

#include <complex>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#define USE MATH DEFINES
#include "math.h"

using namespace std;

const double pi = std::acos(-1);
const complex<double> i(0, 1);


complex<double>* fft(double f[], int N){
	complex<double> tabfft[N];
	if(N>1){
		double tp[N/2];
		double tn[N/2];
		int ctrp=0;
		int ctrn=0;
		for(int n=0; n<N; n++){
			if(n%2 == 0){
				tp[ctrp] = f[n];
				ctrp++;
			}
			else{
				tn[ctrn] = f[n];
				ctrn++;
			}
		}
		for(int k=0; k<N/2; k++){
			tabfft[k] = tp[k] + polar(1.0, -2 * pi * k / N) * tn[k];
			tabfft[k+N/2] = tp[k] - polar(1.0, -2 * pi * k / N) * tn[k];
			cout << tabfft[k] << " " << tabfft[k+N/2] << endl;
		}
	}
	return tabfft;
}

int main(){
		int N = 172;
		cout << "N: " << N << endl;
		double* f = new double[N];
		for(int n=0; n<N; n++){
			f[n] = n/(double)N;
		}
		
		clock_t t3 = clock();
		complex<double>* cfft = fft(f,N);
		clock_t t4 = clock();
		double fft_time = (t4-t3)/(double)CLOCKS_PER_SEC*1000.0;
		cout << "Czas FFT: " << fft_time << "ms" << endl;
		
		cout << "____________________________" << endl;
		delete[] f, cfft;
return 0;
}
