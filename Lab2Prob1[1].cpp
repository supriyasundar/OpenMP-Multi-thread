/*
 * Author:Supriya Sundar
 * Class:ECE6122
 * Last Date Modified:10/13/2021
 * Description: Number of steps taken by ant to drop seeds from bottom of grid to top row of grid was computed.
 * Reason for Late Submission: Crash of Pace Ice on 13th and severe illness during fall break which can be verified from Stamps Health. Please consider waiving the penalty as I was unable to finish question 3 on the previous lab on time as well owing to difficulty level and my GPA would be affected. Kindly excuse me just this once. Thank you.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<random>
#include<chrono>
#include<atomic>
#include<thread>
#include<mutex>
using namespace std;
void multipleAnts(int numRunsPerThread)
{
    uint64_t totalSteps=0;
    unsigned long seed=chrono::high_resolution_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    static constexpr int north=1;
    static constexpr int south=2;
    static constexpr int west=3;
    static constexpr int east=4;
    static constexpr int numOfDirections=4;
    uniform_int_distribution<int> distribution(1,numOfDirections);
    for(int i=0;i<numRunsPerThread;i++)
    { 
        int topRow[5]={0,0,0,0,0};
        int bottomRow[5]={1,1,1,1,1};
        unsigned int x=0,y=0;
	double numberOfSteps=0;
        bool seedOccupancy=false,carrySeed=false;
	bool notFinished=true;
        while(notFinished)
        {
	    int direction=distribution(generator);//1-up,2-down,3-left,4-right
            if (seedOccupancy==true)
                carrySeed=true;
                seedOccupancy=false;
		numberOfSteps++;
	    int sum=0;
	    for(int i=0;i<5;i++)
	        sum+=topRow[i];
	    switch(direction)
	    {
	        case 1:
		{
		    if (sum==5 || y==3){
			notFinished=false;
		        break;
			}
		    else{
		        y++;
			numberOfSteps++;
		        break;
			}
		}
		case 2:
		{
		    if (sum==5 || y==-3){
			notFinished=false;
		        break;
			}
		    else{
			y--;
			numberOfSteps++;
			break;
			}
		}
		case 3:
		{
		    if (sum==5 || x==3){
			notFinished=false;
		        break;
			}
		    else{
		        x--;
			numberOfSteps++;
			break;
			}
		}
		case 4:
		{
		    if (sum==5 || x==-3){
			notFinished=false;
			break;
			}
		    else{
			x++;
			numberOfSteps++;
			break;
			}
		}
	    } 
	}
	mutex.lock();
	totalSteps+=numberOfSteps;
	mutex.unlock();
    }    
}
int main()
{
    ofstream file;
    file.open("ProblemOne.txt",ios::out|ios::trunc);
    N=10000000;
    int sumOfThreads=0;
    sumOfThreads=multipleAnts(thread::hardware_concurrency);
    sumOfThreadsnumThreadsPerRun.join();
    double average;
    average=totalSteps/N;
    file<<average;
    file.close();
}   
    

			
		        
			
		    
			
