#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    int n;
    cin>>n;
    
    while(n!=0){
        for(int f = 1; f <= n; f++){
            if(n % f == 0)
                cout<< f << " ";
        }
        cout<<"Enter the next number";
        cin>>n;
    }
    

    return 0;
}
