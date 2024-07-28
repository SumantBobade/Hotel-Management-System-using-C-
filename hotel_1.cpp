#include<iostream>
using namespace std;

class Hotel
{
	private:
		struct Node{
			int id,date;
			string name,roomtype;
			Node * next;
		};
		
	public:
		Node *head =NULL;
		void insert();
		void menu();
		void update();
		void search();
		void del();
		void sort();
		void show();
		
};

void Hotel::menu()
{
	int choice;
	cout<<"\n";
	cout<<"\tWelcome To Hotel Management System Applicatio\n"<<endl;
	cout<<"\n\t_______________Hotel Management System_________________";
	cout<<"\n\nS.no           Functions                         Discription"<<endl;
	cout<<"\n1\tAllocate Room\t\t\tInsert New Room";
	cout<<"\n2\tSearch Room\t\t\tSearch Room with RoomID";
	cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";
	cout<<"\n4\tDelete Room\t\t\tDelete Room with RoomID";
	cout<<"\n5\tShow Room Records\t\t\tShow Room Record that we added";
	cout<<"\n6\tExit"<<endl;
	
	cout<<"Enter Your Choice"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert();
			menu();
		
		case 2:
			search();
			menu();
		
		case 3:
			update();
			menu();
	
		case 4:
			del();
			menu();
	
	
		case 5:
			//sort();
			show();
			menu();
			
		case 6:
            cout<<"Exiting the program. Goodbye!"<<endl;
            break;
	
			default:
				cout<<"Invalid";
	}
}

void Hotel::insert()
{
	cout<<"\n\t_______________Hotel Management System_________________";
	Node *new_Node = new Node;
	cout<<"\nEnter Room ID"<<endl;
	cin>>new_Node->id;
	cout<<"\nEnter Customer Name"<<endl;
	cin>>new_Node->name;
	cout<<"\nEnter Allocated date"<<endl;
	cin>>new_Node->date;
	cout<<"\nEnter Room Type(single/double/twin)"<<endl;
	cin>>new_Node->roomtype;
	
	if(head==NULL)
		head=new_Node;
	else
	{
		Node* ptr=head;
		while(ptr->next !=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next = new_Node;
	}
	cout<<"\n\n\t\t New Room Inserted";
}

void Hotel::search()
{
	cout<<"\n\t_______________Hotel Management System_________________";
	int t_id;
	
	if(head==NULL)
		cout<<"\n\tLinked list is empty";
	else
	{
		cout<<"\n\tEnter ID";
		cin>>t_id;
		Node* ptr=head;
		while(ptr!=NULL){
			if(t_id == ptr->id)
			{
				cout<<"\n\tRoom ID"<<ptr->id;
				cout<<"\n\tCustomer Name"<<ptr->name;
				cout<<"\n\tRoom Alloted Date"<<ptr->date;
				cout<<"\n\tRoom Type"<<ptr->roomtype;
				break;
			}
		}
	ptr=ptr->next;	
	}
}

void Hotel::update()
{
	cout<<"\n\t_______________Hotel Management System_________________";
	int t_id;
	
	if(head==NULL)
		cout<<"\n\tLinked list is empty";
	else
	{
		cout<<"\n\tRoom ID";
		cin>>t_id;
		Node *ptr =head;
		while(ptr!=NULL)
		{
			if(t_id==ptr->id)
			{
				cout<<"\n\tRoom ID";
				cin>>ptr->id;
				
				cout<<"\n\tCustomer Name";
				cin>>ptr->name;
				
				cout<<"\n\tAllocation Date";
				cin>>ptr->date;
				
				cout<<"\n\tRoom Type";
				cin>>ptr->roomtype;
				
				cout<<"\n\t\t Updated Record Successfully";
				break;
			}
			ptr=ptr->next;
		}
	
	}
}

void Hotel::del()
{
	cout<<"\n\t_______________Hotel Management System_________________";
	int t_id;
	
	if(head==NULL)
		cout<<"\n\tLinked list is empty";
	else
	{
		cout<<"\n\tRoom ID";
		cin>>t_id;
		if(t_id = head->id)
		{
			Node* ptr= head;
			head=head->next;
			delete ptr;
			cout<<"Delete Room Record Successfully\n";
		}
		else
		{
			Node * pre = head;
			Node* ptr = head;
			while(ptr!=NULL)
			{
				if(t_id == ptr->id)
				{
					pre->next=ptr->next;
					delete ptr;
				cout<<"Delete Room Record Successfully\n";
				break;
				}
				pre=ptr;
				ptr=ptr->next;
			}
		}
	}
}

void Hotel::show()
{
    Node *ptr;
    ptr = head;

    if(ptr == NULL)
    {
        cout << "\n\tNo Room Records Available";
        return;
    }

    cout << "\n\t_______________Hotel Management System_________________";
    cout << "\n\tRoom Records:" << endl;
    cout << "\n\tRoom ID\tCustomer Name\tRoom Alloted Date\tRoom Type" << endl;

    while(ptr != NULL)
    {
        cout << "\n\t" << ptr->id << "\t" << ptr->name << "\t" << ptr->date << "\t" << ptr->roomtype << endl;
        ptr = ptr->next;
    }
}

void Hotel::sort()
{
	if(head==NULL){
		cout<<"\n\nLinked list is Empty";
		menu();
	}
	int cout=0, t_date,t_id;
	string t_name, t_roomtype;
	Node* ptr =head;
	int count;
	while(ptr!=NULL)
	{
		count++;
		ptr =ptr->next;
	}
	for(int i=1;i<-count;i++)
	{
		Node*ptr = head;
		for(int j=1;j<count; j++)
		{
			if(ptr->id > ptr->next->id)
			{
				t_id+ptr->id;
				t_name+ptr->name;
				t_date+ptr->date;
				t_roomtype+ptr->roomtype;
				//Save to next node
				ptr->id=ptr->next->id;
				ptr->name=ptr->next->name;
				ptr->date=ptr->next->date;
				ptr->roomtype=ptr->next->roomtype;
				// save to previous node
				ptr->next->id = t_id;
				ptr->next->name = t_name;
				ptr->next->date = t_date;
				ptr->next->roomtype = t_roomtype;
			}
			ptr=ptr->next;
		}
	}
}

int main()
{
	Hotel h;
	h.menu();
}
