#include<iostream>
using namespace std;
//node
class node{
	public:
		int data;
		node* next;
		
		node(){
			next=NULL;
		}
};
//list
class list{
	public:
		node* head;
		//default constructor
		list(){
			head=NULL;
		}
		
		//counting
		void count(){
			node* current=head;
			int i;
			if(head==NULL) i=0;
			else{
				 i=1;
				while(current->next!=head){
					i++;
					current=current->next;
				}
			}
			cout<<i<<endl;
		}
		
		//insertion
		void insert(int i_data){
				node* current=head;
				node* temp= new node;
				//insertion
				temp->data=i_data;
				if(head==NULL){
					head= temp;
					temp->next=head;
				}
				else{
					while(current->next!=head ){
						current=current->next;
					}
					current->next=temp;
					temp->next=head;
				}
				
		}
		
		//insertAt
		void insertAt(int i_data,int pos){
			node* temp=new node;
			temp->data=i_data;
			//pos==1
			if (pos==1){
				temp->next=head;
				node* current=head;
				while(current->next!=head){
					current=current->next;
				}
				current->next=temp;
				head=temp;
			}
			//pos=/=1
			else{
				node* current= head;
				int i=1;
					while(i<pos-1){
						i++;
						current=current->next;
					}
					//data entry
					temp->next=current->next;
					current->next=temp;
			}
		}
		//delete
		void delet(){
			//store the tail in temp
			node * temp = tail;
			// before tail has to point to null
			node * current=head;
			while(current->next !=tail){
				current =current->next;		
			}
			current->next=head;
			//update tail
			tail=current;
			delete temp;
		}
		
		//display function
		void display(){
			node* current=head;
			//null party
			if (current==NULL){
				cout <<"NULL\n";
			}
			else{
				while (current!=NULL){
					cout << current->data<<"->";
					current=current->next;
					if(current->next==head->next){
						break;
					}
				}
				cout<<"NULL\n";
			}
		}
};

//main function
int main(){
	list l1;
	l1.display();
	l1.count();
	l1.insert(5);
	l1.insert(52);
	l1.insert(23);
	l1.display();
	l1.count();
	l1.insertAt(1,1);
	l1.display();
	l1.count();
	return 0;
}
