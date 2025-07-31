// Matthew Chen 
// COP4530
// 9/27/34

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void printWords(string input) 
{
    stringstream ss(input); // breaking apart words
    map<string,int> wmap; // hashtable to store word and frequency in 
    vector<pair<string,int>> order; // vector for output to maintain insertion order, store words, and update values

    string word; 
    while(ss >> word)
    {   
       string temp = "";
       bool wrd = true;
       for(char c : word) // goes through word character by character, if its a real word it stores it in a string and adds to map
       {
            char cc = tolower(c);
            if(isalpha(cc))
                temp+=cc;
            else
                wrd = false;
       }
       if(wrd)
       {
            if(wmap[temp] == 0) // if the word doesn't exist, add it to the order
            {
                order.push_back({temp,1});
            }
            else // otherwise, find it in the vector and update it's value
            {
                for(auto& i : order)
                {
                    if(i.first == temp)
                    {
                        i.second++;
                        break; // break statement to save resources
                    }
                }
            }
            wmap[temp]++;
       }
    }
    
    sort(order.begin(), order.end(), [](const pair<string, int>& a, const pair<string, int>& b) // sorts by value while maintaining insertion order
    {
        if (a.second == b.second) {
              return false;
          }
          else
            return a.second > b.second;
    });
    
    if(order.size() > 10)
    {
        cout<<"Total "<<order.size()<<" different words, 10 most used words: \n";
        auto it = order.begin();
            for(int i  = 0; i < 10; i++)
            {
                cout <<"No. "<< i << ": "<< it->first << "\t" << it->second<< "\n";
                it++;
            }
    }
    else
    {
        cout<<"Total "<< order.size() <<" different words, " << order.size() << " most used words: \n";
            int i = 0;
            for(auto it = order.begin(); it != order.end(); ++it)
            {
                cout <<"No. "<< i++ << ": "<< it->first << "\t" << it->second<< "\n";
            }
    }
}


void printNumbers(string input) 
{
    stringstream ss(input); // breaking apart words
    map<int,int> nmap; // hashtable to store number and frequency in
    vector<pair<int,int>> order; // vector for output to maintain insertion order, store words, and update values    
    
    int n;
    string temp;
    while(ss >> temp)
    {
        stringstream convert(temp);
        if(convert >> n) // if the converted stringstream is an int, store to map
        {
            if(nmap[n] == 0) // if the word doesn't exist, add it to the order
            {
                order.push_back({n,1});
            }
            else // otherwise, find it in the vector and update it's value
            {
                for(auto& i : order)
                {
                    if(i.first == n)
                    {
                        i.second++;
                        break; // break statement to save resources
                    }
                }
            }
            nmap[n]++;
        }
    }
    
    sort(order.begin(), order.end(), [](const pair<int, int>& a, const pair<int, int>& b) // sorts by value while maintaining insertion order
    {
        if (a.second == b.second) {
              return false;
          }
          else
            return a.second > b.second;
    });

    if(order.size() > 10)
    {
        cout<<"Total "<<order.size()<<" different numbers, 10 most used numbers: \n";
        auto it = order.begin();
            for(int i  = 0; i < 10; i++)
            {
                cout <<"No. "<< i << ": "<< it->first << "\t" << it->second<< "\n";
                it++;
            }
    }
    else
    {
        cout<<"Total "<< order.size() <<" different numbers, " << order.size() << " most used numbers: \n";
            int i = 0;
            for(auto it = order.begin(); it != order.end(); ++it)
            {
                cout <<"No. "<< i++ << ": "<< it->first << "\t" << it->second<< "\n";
            }
    }
}

void printCharacters(string input)
{
    stringstream ss(input); // breaking apart words
    map<char,int> cmap; // hashtable to store number and frequency in 
    vector<pair<char,int>> order; // vector for output to maintain insertion order, store words, and update values   
    
    char c;
    string temp = "";
    while(ss >> c)
    {
        if(isalpha(c))
            temp+=c; // takes all the characters of the string
    }

    for(char ch: temp) // reads through all the characters of the string to store in map and vector
    {
        if(cmap[ch] == 0) // if the word doesn't exist, add it to the order
            {
                order.push_back({ch,1});
            }
            else // otherwise, find it in the vector and update it's value
            {
                for(auto& i : order)
                {
                    if(i.first == ch)
                    {
                        i.second++;
                        break; // break statement to save resources
                    }
                }
            }
        cmap[ch]++;
    }
    
    sort(order.begin(), order.end(), [](const pair<char, int>& a, const pair<char, int>& b) // sorts by value while maintaining insertion order
    {
        if (a.second == b.second) {
              return false;
          }
        else
            return a.second > b.second;
    });

    if(order.size() > 10)
    {
        cout<<"Total "<<order.size()<<" different characters, 10 most used characters: \n";
        auto it = order.begin();
        int i = 1;
            for(int i  = 0; i < 10; i++)
            {
                cout <<"No. "<< i << ": "<< it->first << "\t" << it->second<< "\n";
                it++;
            }
    }
    else
    {
        cout<<"Total "<< order.size() <<" different characters, " << order.size() << " most used characters: \n";
            int i = 0;
            for(auto it = order.begin(); it != order.end(); ++it)
            {
                cout <<"No. "<< i++ << ": "<< it->first << "\t" << it->second<< "\n";
            }
    }
}


int main()
{
    string line = "";
    while(getline(cin,line)){       
        printCharacters(line);
        printWords(line);
        printNumbers(line);
    }

    return 0;
}

