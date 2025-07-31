#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char grade;
    cout<<"Enter a grade letter";
    cin>>grade;

    if(grade == 'A'){
        cout<<"Your grade was >= 90"<<endl;
    }
    else if(grade == 'B'){
        cout<<"Your grade was between 80 and 89.99"<<endl;
    }
    else if(grade == 'C'){
        cout<<"Your grade was between 70 and 79.99"<<endl;
    }
    else if(grade == 'D'){
        cout<<"Your grade was between 60 and 69.99"<<endl;
    }
    else if(grade == 'F'){
        cout<<"Your grade was below 60"<<endl;
    }
    else{
        cout<<"Invalid grade entered"<<endl;
    }

    cout<<"Ooutput from the switch: ";
    switch(grade){
        case 'A':
        case 'a': cout<<"Your grade was >= 90"<<endl;
            break;
        case 'B':
        case 'b': cout<<"Your grade was between 80 and 89.99"<<endl;
            break;
        case 'C':
        case 'c': cout<<"Your grade was between 70 and 79.99"<<endl;
            break;
        case 'D':
        case 'd': cout<<"Your grade was between 60 and 69.99"<<endl;
            break;
        case 'F':
        case 'f': cout<<"Your grade was below 60"<<endl;
        default: cout<<"Invalid grade entered"<<endl;
    }
    
    return 0;
}