/* Name: Matthew Chen
Date: 10/4/23
Section: 25
Assignment: Homework 3
Due Date: 10/13/23
About this project:
Assumptions: 

All work below was performed by Matthew Chen */

#include <iostream>
using namespace std;

int main()
{
    
    // question 1: accept denominator from user
    int d;
    cout<<"Enter the denominator"<<endl;
    cin>>d;
    
    if(d >= 3){ // make sure denominator is at least 3
        cout<<"The possible numbers are: "<<endl;
        for(int i = 1; i < d; i++) // for loop to iterate from 1 to number user entered
        {
            bool cf = false; // boolean to indicate whether common factors exist or not
            int s = d+i;
            for(int j = 2; j < d; j++){ // second loop to check for common factors beside 1
                if(s%j == 0 && d%j == 0){
                    cf = true; // boolean turns true if is a common factor
                }
            }

            if(cf) // if there is a common factor loop through and list all of them
            {
                cout<<s<<" - ";
                for(int n = 2; n < d; n++)
                {
                    if(s%n == 0 && d%n == 0)
                    {
                        cout<<n<<", ";
                    } 
                }
                cout<<"common"<<endl;
            }
            else // else logically it must be a superpatient fraction which will be printed
            {
                cout<<s<<" - "<<s<<"/"<<d<<endl;
            }
        }
    }
    else{
        cout<<"Eror: Denominator too small"<<endl;
    }
    return 0;
}