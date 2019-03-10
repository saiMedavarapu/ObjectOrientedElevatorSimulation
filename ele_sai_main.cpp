//Sai Medavarapu
//Current Trends in Programming
//HW2 - Elevator Simulation.
#include<iostream>
#include <cstdlib>
#include <ctime> 
#include <math.h>
#include <algorithm>
#include <ele_cal.h>


using namespace std;

ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}


int main()
{
    int noOfFloors , elevatorSize = 10,  initialLoc= 5, noOfReq[100000], toFloor[100000], numbOfReq, elevator[100000], elevators;
    int *cnt, *floors,i;
 
 
   ele_cal c;
    float timeToMove;
   

   cout<<"The total number of floors.\n";
   cin>>noOfFloors;
   floors = new int[noOfFloors];
     cout<<"Number of Elevators?\n";
    cin>> elevators;
  cout<<"Elevator Size?\n";
    cin>> elevatorSize;
cout<<"How many number of requests"<<endl;
cin>>numbOfReq;
     cnt = new int[numbOfReq];
     cout<<"What is The time it takes to move between two floors?(in seconds)\n";
     cin>> timeToMove;
cout<<"What is the initial location of the elevator?\n";
    cin>>initialLoc;

cout<<"------------Generated Floor requests are---------------\n";
     
    //Random number generator for elevator request.
cout<<"From   "<<"To"<<endl;
 srand((unsigned)time(0)); 
    for(int i=0;i<numbOfReq;i++)
    {
   elevator[i] = (rand()%elevators);
    noOfReq[i] = (rand()%noOfFloors)+1; 
    toFloor[i] = (rand()%noOfFloors)+1; 
    //Just in case if the reqfloor and from floor are same, It generates different random number
    while(toFloor[i]==noOfReq[i])
    {
      toFloor[i] = (rand()%noOfFloors)+1; 
    }
    cout << noOfReq[i]<<"----->"<< toFloor[i]<<"\t Elevator ["<<elevator[i]+1<<"]\n";
    }

int sel=0;
   // Algo selection for each elevator
for(i=0;i<elevators;i++)
{
	q:	 cout<<endl<<"Select Algorithm for Elevator-["<<i+1<<"]?\n 1. FCFS - Queuebased\n 2. Check the floor with high number of requests \n 3. Find the smallest distance with respect to travel by sorting\n";
	 cin>>sel;
if(sel==1)
c.a1(i, numbOfReq, elevator, noOfReq, toFloor, timeToMove);
else if(sel==2)
c.a2(i,numbOfReq, elevator,noOfReq, toFloor, timeToMove,floors);
else if(sel==3)
c.a3(i,numbOfReq, elevator,noOfReq, toFloor, timeToMove,floors);
else
{
cout<<"Wrong Input... Try again";
goto q;
}
}
return 0;
}

