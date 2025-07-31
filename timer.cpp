/* Name: Matthew Chen
Date: 10/2/23
Section: 25
Assignment: Homework 2
Due Date: 10/6/23
About this project: Uses reference letters to figure out the amount of 
time it'll take for messsenger birds to deliver messages across certain
distances
Assumptions: Assume user input is correct

All work below was performed by Matthew Chen */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //question 1: print a menu displaying the birds and corresponding reference letters
    cout<<"African Swallow - A"<<endl;
    cout<<"African Swallow + Coconut - C"<<endl;
    cout<<"European Swallow - E"<<endl;
    cout<<"European Swallow + Coconut - U"<<endl;
    cout<<"Barn Swallow - B"<<endl;
    cout<<"Barn Swallow + Coconut - W"<<endl;

    //question 2: prompt and read the bird and distance
    char b;
    double d;
    cout<<"Enter the bird: ";
    cin>>b;
    cout<<"Enter the distance (in kilometers): ";
    cin>>d;

    //bird speed is m/s so to find time taken do (d*1000)/bird speed
    switch (b){
        case 'A': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/12.98 << " seconds."<<endl;
        break;
        case 'C': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/11.91 << " seconds."<<endl;
        break;
        case 'E': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/12.04 << " seconds."<<endl;
        break;
        case 'U': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/11.86 << " seconds."<<endl;
        break;
        case 'B': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/11.31 << " seconds."<<endl;
        break;
        case 'W': cout<<fixed<<setprecision(4)<<"Time taken is "<< (d*1000)/10.46 << " seconds."<<endl;
        break;
        default: cout<<"Error: Invalid reference for bird."<<endl;
    }

}