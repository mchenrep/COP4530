#include <iostream>
using namespace std;

int main()
{
    int s;
    cin>>s;
    for(int r = 0; r < s; r++)
    {
        if(r == 0 || r == s-1){
            cout<<"*";
            for(int c = 0; c < s; c++){
                cout<" ";
            }
            cout<<"*";
        }
        else{
            cout<<"*";
            for(int sp = 0; sp < r-1; sp++){
                cout<<" ";
            }
            cout<<"*";
            for(int sp = 0; sp < s - r - 2; sp++){
                cout<<" ";
            }
            cout<<"*";
            for(int sp = 0; sp < s - r -3; sp++){
                cout<<" ";
            }
            cout<"*";
        }
        cout<<endl;
    }
        
    return 0;
}