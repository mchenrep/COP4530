#include <iostream>
using namespace std;
int main()
{
    bool yn = true;
    while(yn) // loops while yn is true for the continue prompt
    {
        int s = 0;
        char l;
        cout<<"Enter the size"<<endl;
        cin>>s;
        while(s%2 == 0 || s < 7){ // if user inputs invalid number it will repeat until they get a valid input
           cout<<"Invalid size. Enter the size again: ";
            cin>>s;
        }
        cout<<"Enter the letter"<<endl;
        cin>>l;
        while(l != 'P' && l != 'T' && l != 'R' && l !='Y'){ // if user inputs invalid letter it will repeat until they get a valid input
            cout<<"Invalid letter: Enter the letter agian: ";
            cin>>l;
        }

        switch(l){
            case 'P': 
                for(int r = 0; r < s; r++){
                    if(r == 0 || r == s/2){ //Top part of the P
                        for(int c  = 0; c < s; c++){
                            cout<<"*";
                        }
                    }
                    else if(r < s/2){ // To have a '*' on both ends
                        cout<<"*";
                        for(int c  = 1; c < s - 1; c++){
                            cout<<" ";
                        }
                        cout<<"*";
                    }
                    else{ //'Stem' of the P
                        cout<<"*";
                    }
                    cout<<endl;
                }

            case 'T':
                for(int r = 0; r < s; r++){
                    if(r == 0){ //Top part of the T
                        for(int c  = 0; c < s; c++){
                            cout<<"*";
                        }
                    }
                    else{ //Stem of the T
                        for(int c  = 0; c < s; c++){
                            if(c == s/2){
                                cout<<"*";
                            }
                            cout<<" ";
                        }
                    }
                    cout<<endl;
                    }
            
            case 'R':
                for(int r = 0; r < s; r++){
                    if(r == 0 || r == s/2){ //Top part of the R
                        for(int c  = 0; c < s; c++){
                            cout<<"*";
                        }
                    }
                    else if(r < s/2){ // To have a '*' on both ends
                        cout<<"*";
                        for(int c  = 1; c < s - 1; c++){
                            cout<<" ";
                        }
                        cout<<"*";
                    }
                    else{ //Bottom part of the R
                        cout<<"*";
                        for(int c = 0; c < s; c++){
                            if(c == 2*r -s){ //distance between the two '*'s is 2r - s
                                cout<<"*";
                            }
                            cout<<" ";
                        }
                        
                    }
                    cout<<endl;
                }

            case 'Y':
                for(int r = 0; r < s; r++){
                    if(r < s/2){
                        for(int d = 0; d < r; d++){
                            cout<<" ";
                        }
                        cout<<"*";
                        for(int e = 0; e < s - 2*(r+1); e++){
                            cout<<" ";
                        }
                        cout<<"*";
                    }
                    else{
                        for(int c = 0; c < s; c++){
                            if(c == s/2){
                                cout<<"*";
                            }
                            cout<<" ";
                        }
                    }
                    cout<<endl;
                }

        }
    
    char cont;
    cout<<"Would you like to continue (Y or N): ";
    if(cont == 'N'){
        yn = false;
    }

    }
    return 0;
}