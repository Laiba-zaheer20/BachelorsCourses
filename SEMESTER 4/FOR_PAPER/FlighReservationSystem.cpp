#include<iostream>
#include<string>
using namespace std;

struct passenger{
	string name;
	passenger* next;
};

struct flight{
	string flightname;
    passenger *p;
	flight* next;	
};

class flights{
	flight* head;
	flight* tail;
	public:
	flights(){
		head=NULL;
		tail=NULL;
	}
	int addFlight(string data){
	    	flight* temp =new flight;
			temp->flightname=data;
			temp->p=NULL;
			temp->next=NULL;
			
			if(head==NULL){
			    head=temp;
			    tail=temp;
			}
			else{
			   tail->next=temp;
			   tail=tail->next;
			}
	}
	
	int addpassenger(string flightnam,string passengername){
		flight* temp=head;
		if(head == NULL){
			return 0;
		}
		else{
			while(temp->flightname != flightnam){
			temp=temp->next;
			}
			passenger* temp2=new passenger;
			temp2->name=passengername;
			temp2->next=NULL;
			
			if(!temp->p){
			 temp->p=temp2;
			}
			else{
			passenger* temp3=temp->p;	
				while(temp3->next != NULL){
					temp3=temp3->next;
				}
				temp3->next=temp2;
			}
		}
	}
	int print(){
		flight* f1=head;
		while(f1 != NULL){
			cout<<"FlIGHT NAME "<<f1->flightname<<endl;
			if(f1->p != NULL){
				passenger* p1=f1->p;
				while(p1 != NULL){
					cout<<p1->name<<" PASSENGER"<<endl;
					p1=p1->next;
				}
			}
		f1=f1->next;
		}
	}
	
	int cancelReservation(string flightnam,string passengername){
		flight* temp=head;
		if(head == NULL){
			return 0;
		}
		else{
		while(temp->flightname != flightnam){
			temp=temp->next;
		}
		passenger* cur=temp->p;
		passenger* prev=new passenger;
		if(cur->name == passengername){
			temp->p=cur->next;
			cout<<"f";
			return 1;
		}
		while(cur->name != passengername){
			prev=cur;
			cur=cur->next;
		}
		 prev->next=cur->next;
	}
}
};
int main(){
	flights f1;
	string data="LAIBA";
	f1.addFlight(data);
	string name="AMNA";
	string name1="AMNA1";
	string name2="AMNA2";
	f1.addpassenger(data,name);
	f1.addpassenger(data,name1);
	f1.addpassenger(data,name2);
	f1.print();
    f1.cancelReservation(data,name);
    f1.print();
    
}
