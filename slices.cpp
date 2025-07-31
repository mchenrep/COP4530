/* Name: Matthew Chen
Date: 10/2/23
Section: 25
Assignment: Homework 2
Due Date: 10/6/23
About this project: Ranks pizza based on area per slice
Assumptions: Assume user input is correct

All work below was performed by Matthew Chen */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    //question 1: prompt and read for 3 pizza radii
    double r,r1,r2;
    cout<<"Enter the 3 radii values: "<<endl;
    cin>>r;
    cin>>r1;
    cin>>r2;

    //question 1: prompt and read for number of pizza slices
    int s,s1,s2;
    cout<<"Enter the number of slices for each: "<<endl;
    cin>>s;
    cin>>s1;
    cin>>s2;

    //area of pizza is pi * r * r and divide by slices to get area per slice
    const double pi = 3.14;
    double a = (pi * r * r) / s;
    double a1 = (pi * r1 * r1) / s1;
    double a2 = (pi * r2 * r2) / s2; 

    if(a == a1 && a == a2 && a1 == a2){
        cout<<"Error. You entered the same area per slice 3 times."<<endl;
    }

    //question 4: use if..else statements to print in ascending order
    
    //if pizza 1 is least
    if(a < a1 && a1 < a2){
        cout<<fixed<<setprecision(3)<<"Pizza 1: "<<a<<", Pizza 2: "<<a1<<", Pizza 3: "<<a2<<endl;
    }
    else if(a < a2 && a2 < a1){
        cout<<fixed<<setprecision(3)<<"Pizza 1: "<<a<<", Pizza 3: "<<a2<<", Pizza 2: "<<a1<<endl;
    }

    //if pizza 2 is least
    if(a1 < a2 && a2 < a){
        cout<<fixed<<setprecision(3)<<"Pizza 2: "<<a1<<", Pizza 3: "<<a2<<", Pizza 1: "<<a<<endl;        
    }
    else if(a1 < a && a < a2){
        cout<<fixed<<setprecision(3)<<"Pizza 2: "<<a1<<", Pizza 1: "<<a<<", Pizza 3: "<<a2<<endl;
    }
    
    //if pizza 3 is least
    if(a2 < a1 && a1 < a){
        cout<<fixed<<setprecision(3)<<"Pizza 3: "<<a2<<", Pizza 2: "<<a1<<", Pizza 1: "<<a<<endl;
    }
    else if(a2 < a && a < a1){
        cout<<fixed<<setprecision(3)<<"Pizza 3: "<<a2<<", Pizza 1: "<<a<<", Pizza 2: "<<a1<<endl;
    }


    /*
    Explanation here is that for example if a < a1
    and a1 < a2 then you know the order logically.
    Repeat for each possible combination. This is not
    the most efficient way but will do for now.
    */
    

}