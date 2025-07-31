// This is a comment

/* multi
line 
comment */


#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    /* cout<<"This will appear verbatim"<<endl << 'a' <<'\n' ;
    cout<< 3.14 << " " << 36 + 15 / 4.3-1.8 <<endl; */
    
    bool ans = true;
    cout<< "Ans: " << ans << endl;

    //unsigned char c = 70.99;
    //cout<<"c: "<< c<<endl;


    
    double value = 3.14159;
    int num = 10;

    cout<< "Hello" <<endl;
    cout<< 13 <<endl;
    cout<< 'A' <<endl;
    cout<< num <<endl;
    cout<< 3.547 <<endl;
    cout<< num - value * 4 <<endl;

    cout<<"Enter a number: ";
    cin >> num;
    cout<< "You entered "<< num <<endl;


    return 0;
}


