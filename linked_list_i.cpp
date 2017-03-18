class linked_list
{
	struct node
	{
		int item;
		node* next;
		
		node(const int item, node* next)
		{
			this->item = item;
			this->next = next;
		}
		
		~node() {}
	};
	
public:

	node* head = NULL;
	//node* sent = head;
	
	linked_list() {};
	
	~linked_list() {
        // remove all items
        while (head != NULL) {
            node* curr = head;
            head = head->next;
            delete curr;
        }
    }
    
    void insert(const int item, const int index)
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
	
	int remove(const int index) 
	{
        node* current = head;
        node* previous = NULL;
		if (head == NULL)
		{
			cerr << "EMPTY_LIST_EXCEPTION: Linked List is empty. \n";
		}
		else if (index == 0)
		{
			head = current->next;
			delete current;
		}
		else 
		{	for (int i = 0; i < index; i++)
			{
				previous = current;
				current = current->next;
			} 
			previous->next = current->next;
			int gone = current->item;
			delete current;
			return gone;
		}
    }
	
	int item_at(const int index)
	{
		if (index > size()-1)
			{
				cerr << "INDEX_OUT_OF_BOUNDS_EXCEPTION: The index inputted is longer than your list!\n";
				return 0;
			}		
		node* current = head;
		if (head == NULL)
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
	
	int size() const
	{
		node* current = head;
		int sum = 0;
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
		while (current->next != NULL)
		{ 
			cout << current->item << endl;
			current = current->next;
		}	
		cout << current->item << endl;
	}
	
	void replace(const int item, const int index)
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
	
	void tack(const int item)
	{
		node* current = head;
		while (current->next != NULL)
		{ 
			current = current->next;
		}	
		current->next = new node(item, NULL);
	}
};
