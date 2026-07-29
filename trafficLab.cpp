/*
*File: trafficLab.cpp
*Author: Andrea Ruotolo
*This program caculates the chance of traffic based on time of travel.
*/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int END = 0;
const int INVALID_DATA = -1;
const double NO_TRAFFIC = 1.0;
const double SMALL_TRAFFIC = 1.25;
const double MEDIUM_TRAFFIC = 1.5;
const double LARGE_TRAFFIC = 2.0;

int getUserData(double& miles, double& avgSpeed, int& hour);
double calcTrafficIncrease(int hour);
void printOutput(double miles, double timeToDestination, double trafficIncrease);


int main() {
   
    
    double miles, avgSpeed; // avgSpeed per hour
    double timeToDestination;    // in minutes
    double trafficIncrease; // increase in time due to traffic,  
                            //  ie. MEDUIM_TRAFFIC_ADDED
    int rv;                 // return value of getUserData
    int hour;               // starting hour in 24-hour clock
 
    srand( time( 0 ) );
 
    cout.precision( 0 );
    cout.setf( ios::fixed );
 
    cout << "Welcome to Poogle Maps\n";
    rv = getUserData( miles, avgSpeed, hour );
    while ( rv != END ) {
       if ( rv != INVALID_DATA ) {
          trafficIncrease = calcTrafficIncrease( hour );
          timeToDestination = miles / avgSpeed * 60 * trafficIncrease;
          printOutput( miles, timeToDestination, trafficIncrease );
       }// end if valid data
       rv = getUserData( miles, avgSpeed, hour );
    }
    cout << "Exiting Poogle Maps\n";
}

/*getUserData
  parameters: miles, avgSpeed, hour
  post-condition: none
  returns: valid or invalid
*/

 int getUserData(double& miles, double& avgSpeed, int& hour){
   
      cout << "Enter miles on your route (0 to end): ";
      cin >> miles;

      if(miles == 0){
         return END;

      }else if(miles < 0){
         cout << "Invalid miles: " << miles << endl;
         return INVALID_DATA;
      }
      cout << "Enter average speed driven in miles per hour: ";
      cin >> avgSpeed;

      if(avgSpeed <= 0){
         cout << "Invalid speed: " << avgSpeed << endl;
         return INVALID_DATA;
      }

      cout << "Enter hour (24-hour clock) driving begins: ";
      cin >> hour;
      
      
      if(hour < 0 || hour > 23){
         cout << "Invalid hour: " << hour << endl;
         return INVALID_DATA;
      }

 return 1;
 }

 /*calcTrafficIncrease
   parameters: hour
   post-condition: amount of traffic is determined whether rush hour is present
   returns: amount of traffic
 */

 double calcTrafficIncrease(int hour){
   int randomTraffic = rand() % 100 + 1; //random number between 1 and 100

   if(hour == 7 || hour == 8 || hour == 17 || hour == 18){
      while(randomTraffic >= 1 && randomTraffic < 5){
         return NO_TRAFFIC;
      }while(randomTraffic >= 5 && randomTraffic < 15){
         return SMALL_TRAFFIC;
      }while(randomTraffic >= 15 && randomTraffic < 50){
         return MEDIUM_TRAFFIC;
      }while(randomTraffic >= 50 && randomTraffic < 100){
         return LARGE_TRAFFIC;
      }
      
   }else if(hour >= 6 && hour < 7 || hour >= 9 && hour < 10 || hour >= 15)
      while(randomTraffic >= 1 && randomTraffic < 50){
         return NO_TRAFFIC;
      }while(randomTraffic >= 50 && randomTraffic < 80){
         return SMALL_TRAFFIC;
      }while(randomTraffic >= 80 && randomTraffic < 95){   
         return MEDIUM_TRAFFIC;
      }while(randomTraffic >= 95 && randomTraffic < 100){
         return LARGE_TRAFFIC;
      }
   return 1;
 }

/*printOutput
  parameters: miles, timeToDestination, trafficIncrease
  post-condition: whether on fastest route
  returns: none
*/

 void printOutput(double miles, double timeToDestination, double trafficIncrease){
   cout << "miles: " << miles << ". ";
   cout << "minutes: " << timeToDestination << endl;

   if(trafficIncrease == 1){
      cout << "No traffic." << endl;
   }else if(trafficIncrease == 1.25){
      cout << "A slight amount of traffic." << endl;
   }else if(trafficIncrease == 1.5){
      cout << "There is a lot of traffic. You are still on the fastest route." << endl;
   }else if(trafficIncrease == 2.0){
      cout << "Major traffic. You are not on the fastest route." << endl;
   }
 }