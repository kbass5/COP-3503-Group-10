#include <iostream>
#include "linked_list.h"

using namespace std;

int main(void) 
{
	linked_list<int> l;
	
	l.insert(0, 0);
	l.insert(1, 1);
	l.insert(2, 2);
	l.insert(3, 3);
	
	//This doesn't update apparently as you add to list l 
	//FIX: reinitialize using begin!
	linked_list<int>::linked_list_iterator iter = l.begin();
	
	cout << iter.get() << endl;
	
	while (iter.has_next()) 
	{
		cout << iter.next() << endl;
	}
	
	l.insert(4,4);
	
	iter = l.begin();
	iter.next();
	cout << iter.get() << endl;
	while (iter.has_next()) 
	{
		cout << iter.next() << endl;
	}
	
	l.remove(2);
	
	iter = l.begin();
	cout << iter.get() << endl;
	while (iter.has_next()) 
	{
		cout << iter.next() << endl;
	}
	
	cout << "Item at 2: " << l.item_at(2) << endl;
	return 0;
}
