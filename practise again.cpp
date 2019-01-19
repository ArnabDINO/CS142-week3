#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		//default constructor
		node()
		{
			next=NULL;
			prev=NULL;
		}
};

class list
{
	public:
		node* head;
		node* tail;
		//default constructor
		list(){
			head=NULL;
			tail=NULL;
		}
		//insert function
		
		void insert(int i_data){
			//temporary placeholder
			node* temp=new node;
			temp->data=i_data;
			//head is null
			if (head==NULL){
				head=temp;
			}
			//head is not null
			else{
				tail->next=temp;
				temp->prev=tail;
			}
			tail=temp;
		}
		//insertAt function
		
		void insertAt(int i_data,int pos){
			node* current=head;
			int i=0;
			while(current!=NULL){
				i++;
				current=current->next;
			}
			//cout<<"number of nodes is "<<i<<" ."<<endl;
			if(pos>i){
				cout<<"there's no element in such position.\n";
			}
			else{
			
				//the data is entered 
				node* temp=new node;
				temp->data=i_data;
				if(pos!=1){
					int i=1;
					while(i<pos-1){
						i++;
						current=current->next;
					}
					//data entry
					temp->next=current->next;
					temp->prev=current;
					current->next=temp;
					temp->next->prev=temp;
				}
				else{
					temp->next=current;
					current->prev=temp;
					head=temp;
				}
			}
		}
		
		//delete function
		void delet(){
			node* current=head;
			//int i=1;
			if(current->next==NULL){
				head=NULL;
				tail=NULL;
			}
			else{
			
				while(current->next!=tail){
					current=current->next;
				}
				tail=current;
				current->next=NULL;
			}
		}
		
		//deleteAt function
		void deleteAt(int pos){
			
			node* current=head;
			
			int i=0;
			while(current!=NULL){
				i++;
				current=current->next;
			}
			//cout<<"number of nodes is "<<i<<" ."<<endl;
			if(pos>i){
				cout<<"there's no element in such position.\n";
			}
			else{
			
				if(pos==1){
					head=current->next;
					current=NULL;
				}
				else{
					int i=1;
					while(i<pos-1){
						i++;
						current=current->next;
					}
					node* temp=new node;
					temp=current->next;
					//cutting connections
					temp->next->prev=current;
					current->next=temp->next;
					//deleting
					delete temp;
				}
			}
		}
		void count(){
			node* current=head;
			int i=0;
			while(current!=NULL){
				i++;
				current=current->next;
			}
			cout<<"number of nodes is "<<i<<" ."<<endl;
		}
			
		//display function
		void display(){
			 if(head!=NULL){
			 	node* current=head;
			 	while (current!=NULL){
			 		cout<<current->data<<"->";
			 		current=current->next;
			 	}
			 	cout<<"NULL \n";
			}
			else cout<<"NULL \n";
		}
};

int main(){
	list l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.count();
	l1.deleteAt(5);
	l1.display();
	l1.count();
	l1.delet();
	l1.display();
	l1.delet();
	l1.display();
	l1.count();
	return 0;
}  
