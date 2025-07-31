// Matthew Chen COP4530
#include <iostream>
#include "List.hpp"
#include "MyMemory.h"
#include "MyMemoryBlock.h"

using namespace std;

void print_menu() {
	cout << string(20, '=') << endl;
	cout << "d: memory dump" << endl;
	cout << "r: request memory" << endl;
	cout << "l: release memory" << endl;
	cout << "m: merge memory" << endl;
	cout << "x: quit program" << endl;
	cout << "Your choice: ";	
}

int main()
{
	int blocks = 0, size = 0;
	cout<<"Memory configuration: \n";
	cout<<"Number of memory blocks (integer): \n";
	cin>>blocks;
	cout<<"Memory block size (integer): \n";
	cin>>size;
	MyMemory mm(blocks, size);
	char c;
	do
	{
		print_menu();
		cout<<"Your choice: \n";
		cin>>c;
		cout<<"choice: "<<c<<"\n";
		switch(c)
		{
			case 'd':
				mm.dump();
				break;
			case 'r':
			{
				int sz;
				cout<<"Requested memory size (integer): \n";
				cin>>sz;
				mm.req_mem(sz);
				break;
			}
			case 'l':
			{
				int id,sz;
				cout<<"Release memory index (integer): \n";
				cin>>id;
				cout<<"Release memory length (integer):  \n";
				cin>>sz;
				if(!mm.release_mem(id,sz))
				break;
			}
			case 'm':
			{
				mm.merge_mem();
				break;
			}
			case 'x':
				break;
		}
	}
	while(c != 'x');
	
	return 0;
}
