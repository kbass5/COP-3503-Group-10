// Group 10 Project
// Leader: Daniel Tymecki
// Members: (insert your name here lol)
// mp3.h
// This is where we'll write all our methods and classes.


#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
 
#include <stdexcept>
#include <iostream>
#include <fstream>
#endif

using namespace std;

typedef std::size_t size_t;
 
template <typename T>
class linked_list {
    
struct node 
{   
	T item;
	 
	node* next;
	 
	node(const T& item, node* next): 
		item(item), 
		next(next) {}
	 
	~node() {}
	
};

public:

	class linked_list_iterator 
    {
		node* here;
		node* previous;
	
		public:
	
		linked_list_iterator(node* start = NULL): 
		here(start) { }
	
		~linked_list_iterator() { }
		
		bool has_next() 
		{
			return (here->next != NULL);
		}
		
		T next() 
		{
			here = here->next;
			return here->item;
		}
		
		T get() 
		{
			return here->item;
		}
		
	};
	
	node* head = NULL;
	
    linked_list() {}
     
    ~linked_list() {
        // remove all items
        while (head != NULL) {
            node* curr = head;
            head = head->next;
            delete curr;
        }
    }
    
    linked_list_iterator begin() 
    {
		return linked_list_iterator(head);
	}
     
    void insert(const T& item, const size_t& index) 
    {
		node* current = head;
		if (head == NULL)
		{
			head = new node(item, NULL);
		}
		else if (index == 0)
		{
			head = new node(item, current);
		}
		else 
		{	
			for (int i = 0; i < index-1; i++)
			{
				if (current->next != NULL)
					{current = current->next;}
			} 
			current->next = new node(item, current->next);
		}
    }
     
    T remove(const size_t& index) 
    {
		node* current = head;
        node* previous = NULL;
		if (head == NULL)
		{
			cerr << "EMPTY_LIST_EXCEPTION: Linked List is empty. \n";
		}
		else if (index == 0)
		{
			T gone = current->item;
			head = current->next;
			delete current;
			return gone;
		}
		else 
		{	for (int i = 0; i < index; i++)
			{
				previous = current;
				current = current->next;
			} 
			previous->next = current->next;
			T gone = current->item;
			delete current;
			return gone;
		}
    }
     
    T item_at(const size_t& index) const 
    {
		node* current = head;
		if (index > size()-1)
			{
				cerr << "INDEX_OUT_OF_BOUNDS_EXCEPTION: The index inputted is longer than your list!\n";
			}		
		else if (head == NULL)
		{
			cerr << "EMPTY_LIST_EXCEPTION: Linked List is empty. \n";
		}
		else
		{	for (int i = 0; i < index-1; i++)
			{
				if (current->next != NULL)
					{
						current = current->next;
					}
			} 
			if (current->next != NULL)
					{ return (current->next)->item;}
			else
			{ return current->item;}	
		}  
    }
     
    size_t size() const 
    {
		node* current = head;
		size_t sum = 0;
		if (head == NULL)
		{
			return sum;
		}
		else 
		{
			while (current->next != NULL)
			{
				sum++;
				current = current->next;
			}	
			return sum+1;	
		}
    }
    
    void printL()
	{
		node* current = head;
		int track = 0;
		cout << endl;
		while (current->next != NULL)
		{ 
			cout << current->item << "\t";
			track++;
			if (track % 8 == 0)
			{
				cout << endl;
			}
			current = current->next;
		}	
		cout << current->item.print();
	}
	
	void tack(const T& item)
	{
		node* current = head;
		if (current->next == NULL)
		{
			insert(item, 0);
		}
		else
		{
			while (current->next != NULL)
			{ 
				current = current->next;
			}	
			current->next = new node(item, NULL);
		}
	}
	
	void replace(const T& item, const size_t& index)
    {
		node* current = head;
		if (head == NULL)
		{
			head = new node(item, NULL);
		}
		else if (index == 0)
		{
			head = new node(item, current->next);
		}
		else 
		{	
			for (int i = 0; i < index-1; i++)
			{
				if (current->next != NULL)
					{current = current->next;}
			} 
			node* future = current->next;
			current->next = new node(item, future->next);
		}
	}

	T pop() 
    {
		node* current = head;
        node* previous = NULL;
		if (head == NULL)
		{
			cerr << "EMPTY_LIST_EXCEPTION: Linked List is empty. \n";
		}
		else if (current->next == NULL)
		{
			T gone = current->item;
			head = NULL;
			delete current;
			return gone;
		}
		else
		{
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			previous->next = NULL;
			T gone = current->item;
			delete current;
			return gone;
		}
	}
     
};

class Music_Player
{
	linked_list<Song> playlist;
	linked_list<Song> played;
	Song current_track;
	
public:

	Music_Player() {}
	
	~Music_Player() {}

	void Play()
	{
		
	}
	
	void Pause()
	{
		
	}
	
	void Sort_ABC()
	{
		
	}
	
	bool Import()
	{
		
	}
	
	bool Delete(string filename)
	{
		
	}
	
	void Skip()
	{
		
	}
	
	void Previous()
	{
		
	}
	
	void Rate(int rating)
	{
		
	}
	
	bool Find(string song_name)
	{
		
	}
	
	void Sort_Genre()
	{
		
	}
	
	void Shuffle()
	{
		
	}
};

struct Song
{
	//const File mp3
	const string song_name;
	const string artist;
	const int duration; // in seconds
	const string album
	const string genre
	int rating;
	
	Song() {}
	
	~Song() {}
	
	void set_rating(int rating)
	{
		this->rating = rating;
	}
};
