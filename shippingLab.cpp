/*
*File: shippingLab.cpp
*Author: Andrea Ruotolo
*This program calculates shipping cost based on weight (in kg) and distance (in miles)
*/

#include <iostream>
using namespace std;

double getShippingCost(double weight, double miles);
const double shippingRate1 = 1.10;
const double shippingRate2 = 2.20;
const double shippingRate3 = 3.70;
const double shippingRate4 = 4.80;


int main(){

    double weight, miles, rate, average, count = 0, total, sum = 0; //weight in kg

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Welcome to Shippers R Us!" << endl;

    do{ 
        cout << "-------------------------" << endl; 
        cout << "Package weight (in KG, 0 to end): ";
        cin >> weight;

    
        while(weight > 0 && weight <= 20){
            cout << "Distance (in miles): ";
            cin >> miles;

            

            while(miles < 10 ||miles > 3000){
                cout << "Distance must be between 10 and 3,000 miles."<<endl;
                cout << "Distance (in miles): ";
                cin >> miles;
                }

            if(weight > 0 && weight <= 2){
                rate = shippingRate1;
                total =  getShippingCost(miles, rate);
                cout << "Shipping cost: $" << total << endl;
                sum = sum + total; //running total of shipping cost
                count = count + 1; //running total of how many packages shipped
                break;
            }

            if(weight > 2 && weight <= 6){
                rate = shippingRate2;
                total =  getShippingCost(miles, rate);
                cout << "Shipping cost: $" << total << endl;
                sum = sum + total; //running total of shipping cost
                count = count + 1; //running total of how many packages shipped
                break;
            }

           if(weight > 6 && weight <= 10){
                rate = shippingRate3;
                total =  getShippingCost(miles, rate);
                cout << "Shipping cost: $" << total << endl;
                sum = sum + total; //running total of shipping cost
                count = count + 1; //running total of how many packages shipped
                break;    
            }

            if(weight > 10 && weight <= 20){
                rate = shippingRate4;
                total =  getShippingCost(miles, rate);
                cout << "Shipping cost: $" << total << endl;
                sum = sum + total; //running total of shipping cost
                count = count + 1; //running total of how many packages shipped
                break;    
            }
            
            

        }if(weight < 0){ //invalid event statements
            cout << "Weight must be greater than zero." << endl;
        }if(weight > 20){
            cout << "We do not ship items weighing more than 20 kilograms." << endl;
        }
        
        

    }while(weight != 0);{ //ends program
        average = sum / count; //calculates average per package
        cout <<"Total shipping cost: $" << sum << endl;
        cout <<"Average shipping cost: $" << average << endl;
        cout << "Thank you for using Shippers R Us for your shipping needs."<< endl;
    }

    return(0);
}

/*shippingCost
  parameters: calculates shipping rate based on miles
  returns: rate total
*/

double getShippingCost(double miles,double rate){
    double rateTotal;
    if(miles > 0 && miles <= 500){
         rateTotal = rate * 1;
    }else if(miles > 500 && miles <= 1000){
        rateTotal = rate * 2;
    }else if(miles > 1000 && miles <= 1500){
        rateTotal = rate * 3;
    }else if(miles > 1500 && miles <= 2000){
        rateTotal = rate * 4;
    }else if(miles > 2000 && miles <= 2500){
        rateTotal = rate * 5;
    }else if(miles > 2500 && miles <= 3000){
        rateTotal = rate * 6;
    }
    return(rateTotal);
}