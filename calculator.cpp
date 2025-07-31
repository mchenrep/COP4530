/* Name: Matthew Chen
Date: 9/22/23
Section: 25
Assignment: hw1
Due Date: 9/27/23
About this project: calculator for BB-8 rotational speed
Assumptions: assumes correct user input

All work below was performed by Matthew Chen */

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    cout<<"Welcome to the BB-8 Speed Calculator"<<endl;
    double r, dp, dd, t; //r= radius, dp = distance to pickup, dd = distance to drop off, t = time
    const double pi = 3.142;
    cout<<"Enter the radius (feet): ";
    cin>>r;
    cout<<"Enter the distance from starting point to pickup point (miles): ";
    cin>>dp;
    cout<<"Enter the distance from pickup point to dropoff point (miles): ";
    cin>>dd;
    cout<<"Enter the time available to cover the distance (minutes): ";
    cin>>t;

    //convert total disance to feet from miles, then divide total distance by distance covered in 1 rotation, and finally divide by number of seconds available to cover the distance
    //formula for circumference C = 2pi * radius
    double c = 2 * pi * r; //distance covered in 1 rotation in feet
    double td = (dp + dd) * 5280; // total distance between pickup and dropoff points in feet

    cout<<fixed<<setprecision(3)<<"BB-8 needs to move at "<<(td/c)/(t*60)<<" rotations per second"<<endl;

    return 0;
}