/*
 * Author:Supriya Sundar
 * Class:ECE6122
 * Last Modified Date:10/12/2021
 * Description:Implementation of numerical integration using midpoint rule and parallel programming.
 */
#include<stdio.h>
#include<omp.h>
#include<iostream>
#include <fstream>
#include<cmath>
#include<math.h>
#include<iomanip>
using namespace std;
int main(int argc, char* argv[])
{
    ofstream file;
    file.open("Lab2Prob2.txt",ios::out|ios::trunc);
    double delta,x;
    int n;
    n=atoi(argv[1]); //number of segments into which function is divided
    double upperLimit=log(2)/7; // upperlimit
    double lowerLimit=0; //lowerlimit
    delta=(upperLimit-lowerLimit)/n; //size of subsection
    double integral=0;
    #pragma omp parallel for
    for(unsigned long i=0;i<n;i++) // looping over entire length of function divided into n segments
    {
        double value=i+(delta/2)+(i+1/n); //computing sum of midpoint
	integral+=delta*(1/value); // computing product of function midpoint interval and size of subsection and summing it with result variable
    }
    file<<fixed;
    file<<setprecision(6); // rounding output decimal to 6 places
    file<<integral;
    file.close();
    return 0;
}
