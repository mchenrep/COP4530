#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    int val = 9, sum = 0, i, j;
    for(i = val-1; val > 0; val--){
        j = i + 5;
        while(j > val){
            sum+=val;
            if(sum % 3 == 0){
                val -=2;
                --j;
            }
        }
    }
    cout<<sum<<" "<<val<<" "<<i<<" "<<j;
}
