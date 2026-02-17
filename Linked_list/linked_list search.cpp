 #include<iostream>
 using namespace std;
 class Node{
public: 	
 	int data;
 	Node*next;
 	Node(int val){
 		data = val;
 		next = NULL;
	 }
};

class Linked_list{
private:
	Node*first;
	Node*last;
	
public:	
	Linked_list(){
		first=NULL;
		last=NULL;
	}
	
	void insert(){
		static int i=1;
		int val;
		cout<<"\n\t Enter the data in node " <<i++<<" : ";
		cin>>val;
		Node*newNode= new Node(val);
		
		if(first==NULL){
			first=last=newNode;
		}
		else 
		newNode->next=first;
		first = newNode;
	}
	void display(){
		Node*temp= first;
		        while (temp != NULL) {
            cout<<" " << temp->data << " ->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
	}
	void search(int key){
    	Node*temp = first;
    	int node1;
    	bool found=  false;
        while(temp!=NULL){
        	if(found==key){
        		cout<<"\n\t Entered Value found in "<<node1<<" node..";
        		found=true;
        		break;
			}
			temp=temp->next;
			node1++;			
		}
		if(!found)
		cout<<"\n\t"<<key<<" not found in this list...!!";
	}
	
	Node* get() {
    return first;
}
	
 };
 
 int main(){
 	cout<<"\n\t ....... Linked_list of 3 nodes ......\n\t";
 	cout<<"\n\t ====== Searching in Linked_list ======= \n\n";
 	Linked_list l1;
 	l1.insert();
 	l1.insert();
 	l1.insert();
 	
 	cout<<"\n\t ==== Linked_list is given ===== \n\n ";
 	l1.display();
 	
 		int key;
    	bool found=  false;
    	while(!found){
    		cout<<"\n\t Enter value to search : ";
        	cin>>key; 
			cout<<"\n"; 	
		
		Node*temp=l1.get();
				int node1=1;
		
        while(temp!=NULL){
        	if(temp->data==key){
        		cout<<"\n\t ..... Entered Value found in node  "<<node1<<" ....\n";
        		found=true;
        		break;
			}
			temp=temp->next;
			node1++;			
		}
		if(!found)
		cout<<"\n\t...... "<<key<<" not found in this list ...!! \n";
} 	
 
 	
 	
 	return 0;
 }
