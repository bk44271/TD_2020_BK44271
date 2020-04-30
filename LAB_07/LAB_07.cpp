#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#define USE MATH DEFINES
#include "math.h"
#include <fstream>

using namespace std;

int main(){
	float cz = 0.05;
	float y = 0;
	float stan[50];
	cout << sizeof(stan)/sizeof(stan[0]) << endl;
	
	ifstream file("stan.txt");
    if(file.is_open())
    {
        for(int i = 0; i < sizeof(stan)/sizeof(stan[0]); ++i)
        {
            file >> stan[i];
            cout << stan[i];
        }
    }
	
	ofstream outfile;
	outfile.open("y.txt", ios::trunc | ios::out);
	
	for(float i=0; i<1; i+=cz){
		if(y == 0){
			outfile << (float)y << "\n";
			y = 1;
			outfile << (float)y << "\n";
		}
		else{
			outfile << (float)y << "\n";
			y = 0;
			outfile << (float)y << "\n";
		}
	}
	outfile.close();
	
	outfile.open("x.txt", ios::trunc | ios::out);
	
	for(float i=0; i<1; i+=cz){
		outfile << (float)i << "\n";
		outfile << (float)i << "\n";
	}
	
	outfile.close();
	
	//NRZI
	outfile.open("nrziy.txt", ios::trunc | ios::out);
	
	int jedenzero = 0;
	
	for(float i=0; i<1; i+=cz){
		int ktory = i/cz;
		if(stan[ktory] == 1){
			if(jedenzero == 0){
				outfile << (float)jedenzero << "\n";
				jedenzero = 1;
				outfile << (float)jedenzero << "\n";
			}
			else if(jedenzero == 1){
				outfile << (float)jedenzero << "\n";
				jedenzero = 0;
				outfile << (float)jedenzero << "\n";
			}
		}
		else{
			outfile << (float)jedenzero << "\n";
		}
	}
	outfile.close();
	
	
	outfile.open("nrzix.txt", ios::trunc | ios::out);
	
	for(float i=0; i<1; i+=cz){
		int ktory = i/cz;
		if(stan[ktory] == 1){
			outfile << (float)i << "\n";
			outfile << (float)i << "\n";
		}
		if(stan[ktory] == 0){
			outfile << (float)i << "\n";
		}
	}
	
	outfile.close();
	
	
	//Manchester
	outfile.open("many.txt", ios::trunc | ios::out);
	
	jedenzero = 0;
	
	for(float i=0; i<1; i+=cz){
		int ktory = i/cz;
		if(stan[ktory] == stan[ktory-1]){
			if(jedenzero == 0){
				jedenzero = 1;
				outfile << (float)jedenzero << "\n";
				jedenzero = 0;
				outfile << (float)jedenzero << "\n";
				jedenzero = 1;
				outfile << (float)jedenzero << "\n";
				jedenzero = 0;
				outfile << (float)jedenzero << "\n";
				if(stan[ktory] != stan[ktory+1]){
					jedenzero = 1;
					outfile << (float)jedenzero << "\n";
				}
			}
			else if(jedenzero == 1){
				jedenzero = 0;
				outfile << (float)jedenzero << "\n";
				jedenzero = 1;
				outfile << (float)jedenzero << "\n";
				jedenzero = 0;
				outfile << (float)jedenzero << "\n";
				jedenzero = 1;
				outfile << (float)jedenzero << "\n";
				if(stan[ktory] != stan[ktory+1]){
					jedenzero = 0;
					outfile << (float)jedenzero << "\n";
				}
			}
		}
		else{
			if(jedenzero == 0){
				outfile << (float)jedenzero << "\n";
				if(stan[ktory] != stan[ktory+1]){
					jedenzero = 1;
					outfile << (float)jedenzero << "\n";
				}
			}
			else if(jedenzero == 1){
				outfile << (float)jedenzero << "\n";
				if(stan[ktory] != stan[ktory+1]){
					jedenzero = 0;
					outfile << (float)jedenzero << "\n";
				}
			}
		}
	}
	outfile.close();
	
	
	outfile.open("manx.txt", ios::trunc | ios::out);
	
	for(float i=0; i<1; i+=cz){
		int ktory = i/cz;
		if(stan[ktory] == stan[ktory-1]){
			outfile << (float)i-cz << "\n";
			outfile << (float)i-cz/2 << "\n";
			outfile << (float)i-cz/2 << "\n";
			outfile << (float)i << "\n";
			if(stan[ktory] != stan[ktory+1]){
				outfile << (float)i << "\n";
			}
		}
		else{
			outfile << (float)i << "\n";
			if(stan[ktory] != stan[ktory+1]){
				outfile << (float)i << "\n";
			}
		}
		//x-1 0		x-1 1		x-0.5 1		x-0.5 0		x 0
	}
	
	outfile.close();
	
	
	
return 0;
}
