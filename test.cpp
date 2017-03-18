//Daniel Tymecki
#include "linked_list.h"
#include <iostream>

using namespace std;

int main()
{
	linked_list<int> list;
	linked_list<int> num;
	list.insert(69, 0);
	list.insert(82, 0);
	list.printL();
	int test = list.remove(1);
	cout <<"\nTest is: " << test << endl;
	//num.insert(help, 0);
	list.printL();
	//num.printL();	
	return 0;
}
