#include<iostream>
using namespace std;
class Stack{
private:
	int arr[100];
	int top;
	
public:
	Stack(){
		top=-1;	
	}
	
	void push(int value){
		if(top>=99){
			cout<<"\n ... Stack is full value can't be add ...";
		}
		else
		top++;
		arr[top]=value;
	}
	
	void pop(){
		if(top<0){
			cout<<"\n\t Stack is empty value can't be removed";
		}
		else
		cout<<"\n --- |  "<<arr[top] <<"  | at top of stack is popped. ---\n";
		top--;
	}
	
	int head(){
		if(top<0){
			cout<<"\n\tStack is empty";
			return -1;
		}
		else
		return arr[top];
	}
	
	void display(){
		if(top<0){
			cout<<"\n\t ... Stack is empty Push value before display ...";
		}
		else
		cout<<"\n\t ===== Values of stack are ====\n\t ";
		for(int i=top ; i>=0 ; i--){
			cout<<"\n  |  "<<arr[i]<<"  | ";
			cout<<" \n  ________ \n";
		}
		    cout<<endl;
	}	
};

int main(){
	Stack s1;
	//s1.display();
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	
	s1.display();
	cout<<"\n\t Value at top of stack is |  "<<s1.head()<<"  | \n\n";
	
//	cout<<"\n.... Now we call pop function then display stack ....\n";
	s1.pop();

	cout<<"\n\t Top value update to : |  "<<s1.head()<<"  | \n";
	
	s1.pop();
	cout<<"\n\t Top value update to : |  "<<s1.head()<<"  | \n";
	
	s1.display();
	
	s1.pop();
	s1.pop();
	cout<<"\n\t Top value update to  |  "<<s1.head()<<"  | \n";
	s1.display();
	s1.pop();
	s1.display();
	
	return 0;
}
