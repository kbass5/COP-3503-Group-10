//Daniel Tymecki

#include<iostream>
#include<stdexcept>
#include "linked_list.h"

using namespace std;

int main(void)
{
	
	linked_list<int> l;
	l.remove(0);
	l.insert(69,0);
	l.insert(21,1);
	l.insert(1,2);
	l.insert(31,3);
	l.insert(14,2);
	l.printL();
	cout << "--------------------------Removing index 4------------------------------\n";
	l.remove(4);
	l.printL();
	cout << "--------------------------Removing index 0------------------------------\n";
	l.remove(0);
	l.printL();	
	cout << "--------------------------Replacing index 0------------------------------\n";
	l.replace(100, 0);
	l.printL();	
	cout << "--------------------------Insert index 0------------------------------\n";
	l.insert(9001,0);
	l.printL();	
	cout << "--------------------------Insert index 3------------------------------\n";
	l.insert(1009,3);
	l.printL();
	cout << "--------------------------Tacking on #78, #29, #86------------------------------\n";
	l.tack(78);
	l.tack(29);
	l.tack(86);
	l.printL();
	cout << "Ending size is:  " << l.size() << endl;
	return 0;
}
