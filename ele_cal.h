class ele_cal
{

public:
int a1(int e, int Req1, int ele[], int noOfReq1[], int toFloor1[], int timeToMove1)
 {
   std::cout<<"\n\n--------------Algorithm 1 - FCFS - Queuebased -------------\n";
 //Algorithm 1

    float time_travel[100000], totalTime = 0;
 std::cout<<"For Elevator "<<e+1<<std::endl;

  for(int i=0;i<Req1;i++)
  {
  	if(ele[i]==e) //
  	{
  time_travel[i] = fabs(noOfReq1[i]-toFloor1[i]) * timeToMove1;
  totalTime=totalTime+time_travel[i];
  std::cout<<"Time to travel from floor No:"<<noOfReq1[i]<<" to floor:"<<toFloor1[i] <<" is = "<<totalTime<<" Seconds"<<std::endl;
  //totalTime=totalTime+time_travel[i];
}
  }
  std::cout<<"---------------------------\n";
std::cout<<"Total Time to travel in seconds using Algorithm 1 is : "<<totalTime<<" Seconds"<<std::endl;
}


int a2(int e, int Req1, int ele[], int noOfReq1[], int toFloor1[],  int timeToMove1, int *floors)
{

std::cout<<"\n\n--------------------------Algorithm 2 - Check the floor with high number of requests -------------\n";
  //Algorithm2

// variable declaration
   float time_travel2[100000], totalTime2 = 0;
   int *priorityFloorIndex, *priorityFloorIndex3, *servingFloorAlg2, *servingFloorAlg3;
   int i,r;
   for(i=0;i<Req1;i++)
   {
 //  if(ele[i]==e)
//r++
}
 std::cout<<"For Elevator "<<e+1<<std::endl;

//This array stores requests from each floor.
for (int i=0;i<Req1;i++) {
        floors[i] = 0;
       for (int j=0;j<Req1;j++) {

      if(noOfReq1[j]==i && ele[i]==e)  // also check for elevator
      {
        floors[i]++;
      }
       }
}
//Finding the most number of req from which floor?
   int k=0;
   for(int i = 0; i < Req1; i++)
  {
  std::cout<< "At floor "<<k++<<" There are "<<floors[i]<<" requests \n";
  }


//----Finding the index of the highest repetetive element - Which lets you find busiest floor.*********
    int priorityFloor = max_element(floors, floors + Req1) - floors;
    std::cout<<std::endl;
      std::cout << "Floor which has more number of people is : "
          << priorityFloor << std::endl;

// ****************Implementing search to find the index of priority floor *******************

      priorityFloorIndex = new int[Req1];//Array to hold index values of repetitive element.

      int v= 0; //index variable for priorityFloorIndex
      for(int i=0;i<Req1;i++)
        {
          if(noOfReq1[i] == priorityFloor)
          {
            priorityFloorIndex[v] = i;
            v++;
          }
        }
//**************Printing out the indexes of the repetetive values*************************

servingFloorAlg2 = new int[Req1];

    for(int i=0;i<v;i++)
    {
      std::cout<<"Index values are : "<< priorityFloorIndex[i]<<"  "<<"and the requested floor is: ";
      for(int j=0; j<Req1;j++)
      {
        if(priorityFloorIndex[i]== j)
        {
          servingFloorAlg2[i] = toFloor1[j];
          std::cout<<servingFloorAlg2[i]<<std::endl;
        }
      }
    }

//*************Now that we have index values, lets serve the requests for that floor *************
    for(int i=0; i<Req1; i++)
    {
      for(int j=0; j<v;j++)
      {
        if(i==priorityFloorIndex[j])
        {
          time_travel2[j] = fabs(priorityFloor-servingFloorAlg2[j]) * timeToMove1;
          totalTime2=totalTime2+time_travel2[j];
          std::cout<<"Floor : "<<servingFloorAlg2[j]<< " is served with time : "<< totalTime2<<" Seconds"<<std::endl;

        }
      }
    }
//For rest of the requests.
std::cout<<"*******************"<<std::endl;
    for(int i=0; i<Req1; i++)
    {
if(ele[i]==e)
{
        if(i==servingFloorAlg2[0]|| i==servingFloorAlg2[1]|| i==servingFloorAlg2[2]|| i==servingFloorAlg2[3] || i==servingFloorAlg2[4])
        {
          continue;
        }
        else
        {
          //std::cout<<"i value is "<<i <<std::endl;
          time_travel2[i] = fabs(noOfReq1[i]-toFloor1[i]) * timeToMove1;
          totalTime2=totalTime2+time_travel2[i];
          std::cout<<"Time to travel from floor No:"<<noOfReq1[i]<<" to floor:"<<toFloor1[i] <<" is = "<<totalTime2<<" Seconds"<<std::endl;
          //totalTime2=totalTime2+time_travel2[i];
        }
}
    }
    std::cout<<"Total time taken to serve the entire requests by using Algorithm 2 is : "<< totalTime2<<std::endl;


}
// Algorithm3

int a3(int e, int Req1, int ele[], int noOfReq1[], int toFloor1[], int timeToMove1, int *floors)
{

int *servingFloorAlg3,*priorityFloorIndex3,  *servingFloorAlg2;
 float time_travel3[100000], totalTime3 = 0;
      int v= 0; //index variable for priorityFloorIndex

std::cout<<"\n\n--------------------------Algorithm 3 - Find the smallest distance with respect to travel by sorting and  -------------\n";
std::cout<<"For Elevator "<<e+1<<std::endl;

//This array stores requests from each floor.
for (int i=0;i<Req1;i++) {
        floors[i] = 0;
       for (int j=0;j<Req1;j++) {

      if(noOfReq1[j]==i && ele[i]==e)
      {
        floors[i]++;
      }
       }
}

//----Finding the index of the highest repetetive element - Which lets you find busiest floor.*********
    int priorityFloor = max_element(floors, floors + Req1) - floors;
    std::cout<<std::endl;
      std::cout << "Floor which has more number of people is : "<< priorityFloor << std::endl;

// ****************Implementing search to find the index of priority floor *******************

      priorityFloorIndex3 = new int[Req1];//Array to hold index values of repetitive element.
      v= 0;
      for(int i=0;i<Req1;i++)
        {
          if(noOfReq1[i] == priorityFloor && ele[i]==e)
          {
            priorityFloorIndex3[v] = i;
            v++;
          }
        }
//**************Printing out the indexes of the repetetive values*************************

servingFloorAlg3 = new int[Req1];

    for(int i=0;i<v;i++)
    {
      std::cout<<"Index values are : "<< priorityFloorIndex3[i]<<"  "<<"and the requested floor is: ";
      for(int j=0; j<Req1;j++)
      {
        if(priorityFloorIndex3[i]== j)
        {
          servingFloorAlg3[i] = toFloor1[j];
          std::cout<<servingFloorAlg3[i]<<std::endl;
        }
      }
    }

//***************** Sorting it************************************************
std::cout<<"----------------Sorting the elements---------------------------"<<std::endl;

for (int i = 0; i < v; ++i)
        {

            for (int j = i + 1; j < v; ++j)
            {

                if (servingFloorAlg3[i] > servingFloorAlg3[j])
                {
                    int temp;
                    temp =  servingFloorAlg3[i];
                    servingFloorAlg3[i] = servingFloorAlg3[j];
                    servingFloorAlg3[j] = temp;

                }

            }

        }

//********Printing out the sorted values*********************

for(int i=0;i<v; i++)
      {
        std::cout<<"Sorted value for i =  "<< i<< "is :"<<servingFloorAlg3[i]<<std::endl;
      }

//*************Now that we have index values, lets serve the requests for that floor *************
    for(int i=0; i<Req1; i++)
    {
      for(int j=0; j<v;j++)
      {
        if(i==priorityFloorIndex3[j])
        {
          time_travel3[j] = fabs(priorityFloor-servingFloorAlg3[j]) * timeToMove1;
          totalTime3=totalTime3+time_travel3[j];
          std::cout<<"Floor : "<<servingFloorAlg3[j]<< " is served with time : "<< totalTime3<<" Seconds"<<std::endl;

        }
      }
    }

  //For rest of the requests.
std::cout<<"*******************"<<std::endl;
    for(int i=0; i<Req1; i++)
    {
    	if(ele[i]==e)
{
        if(i==servingFloorAlg3[0]|| i==servingFloorAlg3[1]|| i==servingFloorAlg3[2]|| i==servingFloorAlg3[3] || i==servingFloorAlg3[4])
        {
          continue;
        }
        else
        {
          //std::cout<<"i value is "<<i <<std::endl;
          time_travel3[i] = fabs(noOfReq1[i]-toFloor1[i]) * timeToMove1;
          totalTime3=totalTime3+time_travel3[i];
          std::cout<<"Time to travel from floor No:"<<noOfReq1[i]<<" to floor:"<<toFloor1[i] <<" is = "<<totalTime3<<" Seconds"<<std::endl;
          //totalTime2=totalTime2+time_travel2[i];
        }
}
    }
    std::cout<<"Total time taken to serve the entire requests by using Algorithm 3 is : "<< totalTime3<<"Seconds"<<std::endl;


}

};
