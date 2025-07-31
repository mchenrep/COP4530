#include "passserver.h"
#include <iostream>

using namespace std;
using namespace cop4530;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}

int main()
{
  cout<<"Enter preferred hash table capacity (integer): ";
  int capacity = 0;
  cin>>capacity;
  if(capacity <= 0)
  {
    cout<<"input too small, capacity set to 101";
    PassServer ps;
  }
  PassServer ps(capacity);
  Menu();
  char c;
  cin>>c;
  cout<<"choice: "<<c<<"\n";
  while(c != 'x')
  {
    switch(c)
    {
      case 'l':
      {
        string filename = "";
        cout<<"Enter password file name to load from: ";
        cin>>filename;
        if(!ps.load(filename.c_str()))
        {
          cout<<"Error: Cannot open file "<<filename<<"\n";
        }
        else
        {
          cout<<"Loaded file "<<filename<<"\n";
        }
        break;
      }
      case 'a':
      {
        string user, pass;
        cout<<"Enter username: ";
        cin>>user;
        cout<<"Enter password: ";
        cin>>pass;
        ps.addUser(make_pair(user,pass));
        break;
      }
      case 'r':
      {
        string user;
        cout<<"Enter username: ";
        cin>>user;
        if(!ps.removeUser(user))
        {
          cout<<"Error: User not found.  Could not delete user \n";
        }
        else
        {
          cout<<"User "<<user<<" deleted.\n";
        }
        break;
      }
      case 'c':
      {
        string user, pass, newpass;
        cout<<"Enter username: ";
        cin>>user;
        cout<<"Enter password: ";
        cin>>pass;
        cout<<"Enter new password: ";
        cin>>newpass;
        if(!ps.changePassword(make_pair(user,pass), newpass))
        {
          cout<<"Error: Could not change user password";
        }
        else
        {
          cout<<"Password changed for  user "<<user<<"\n";
        }
        break;
      }
      case 'f':
      {
        string user;
        cout<<"Enter username: ";
        cin>>user;
        if(!ps.find(user))
        {
          cout<<"User \'"<<user<<"\' not found.\n";
        }
        else
        {
          cout<<"User \'"<<user<<"\' found.\n";
        }
        break;
      }
      case 'd':
      {
        ps.dump();
        break;
      }
      case 's':
      {
        cout<<"Size of hashtable: "<<ps.size()<<"\n";
        break;
      }
      case 'w':
      {
        string filename;
        cout<<"Enter password file name to write to: ";
        cin>>filename;
        if(!ps.write_to_file(filename.c_str()))
        {
          cout<<"Error: Cannot open file to write.\n";
        }
        break;
      }
      default:
      {
        break;
      }
    }
    Menu();
    cin>>c;
    cout<<"choice: "<<c<<"\n";
  }


}
