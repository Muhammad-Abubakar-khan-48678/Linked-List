#include<iostream>
using namespace std;

class S_Node{
	public:
		int value;
		S_Node *next;
		S_Node(int v){
			value = v;
			next = NULL;
		}
};

class D_Node{
	public:
		int value;
		D_Node *next;
		D_Node *previous;
		D_Node(int value){
			this->value = value;
			next = NULL;
			previous = NULL;
		}
};

class Singly_Linked_List{
	private:
		S_Node *head;
		int size;
		
		S_Node *Reverse_List(S_Node *head){
			S_Node *previous = NULL;
			S_Node *next = NULL;
			S_Node *current = head;
			
			while(current != NULL){
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}
			
			return previous;
		}
	
	public:
		Singly_Linked_List(){
			head = NULL;
			size = 0;
		}
		
		void Display(){
			system("CLS");
			if(head == NULL){
				cout<<"Singly Linked List is Empty..."<<endl;
			}
			else{
				cout<<"Displaying Singly Linked List"<<endl;
				S_Node *current = head;
				while(current != NULL){
					cout<<current->value<<" ";
					current = current->next;
				}
				cout<<endl;
				system("PAUSE");
			}
		}
		
		void ADD_First(int value){
			S_Node *new_Node = new S_Node(value);
			if (head == NULL){
				head = new_Node;
			}
			else{
				new_Node->next = head;
				head = new_Node;
			}
			size++;
		}
		
		void ADD_Last(int value){
			S_Node *new_Node = new S_Node(value);
			if(head == NULL){
				head = new_Node;
			}
			else{
				S_Node *current = head;
				while(current->next != NULL){
					current = current->next;
				}
				current->next = new_Node;
			}	
			size++;
		}
		
		void Delete_First(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				S_Node* temp = head;
            	head = NULL;
            	delete temp;
            	size--;
			}
			else{
				S_Node *temp = head;
				head = head->next;
				delete temp;
				size--;
			}
		}
		
		void Delete_Last(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				S_Node* temp = head;
            	head = NULL;
            	delete temp;
            	size--;
			}
			else{
				S_Node *temp = head;
				S_Node *previous;
				while(temp->next != NULL){
					previous = temp;
					temp = temp->next;
				}
				previous->next = NULL;
				delete temp;
				size--;
			}
		}
		
		void Insert_At(int value, int position){
			if(head == NULL){
				cout<<"There is No Node So Adding Node To 1st Place"<<endl;
				ADD_Last(value);
				system("PAUSE");
			}
			else{
				if(position > 0 && position <= size){
					
					if(position == 1){
						ADD_First(value);
					}
					else{
						S_Node *new_Node = new S_Node(value);
						S_Node *current = head;
						for(int i=1; i<position-1; i++){
							current = current->next;
						}
						new_Node->next = current->next;
						current->next = new_Node;
						size++;
					}
				}
				else{
					cout<<"Invalid Position... So, Node is Added to Last Place"<<endl;
					ADD_Last(value);
					system("PAUSE");
				}	
			}		
		}
		
		int Search(int x){
			if(head == NULL){
				cout<<"There is No Node To Search..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				S_Node *current = head;
				while(current != NULL ){
					if(current->value == x){
						flag++;
					}
					current = current->next;
				}
				if(flag == 0){
					cout<<"Value Not Found..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Value Found..."<<endl;
					system("PAUSE");
				}
			}		
		}
		
		void Is_Palindrome(){
	        if (head == NULL) {
	            cout<<"There is No Node To Check Palindrome..."<<endl;
	            system("PAUSE");
	        }
	        else{
	        	S_Node* slow = head;
		        S_Node* fast = head;
		        
		        while (fast->next != NULL && fast->next->next != NULL) {
		            slow = slow->next;
		            fast = fast->next->next;
		        }
		
		        // Reverse the second half of the list
		        S_Node *Second_list = slow->next;
		        Second_list = Reverse_List(Second_list);
		
				fast = head;
				S_Node *temp = Second_list;
				int flag = 0;
		        // Compare
		        while (temp != NULL) {
		        	
		            if (temp->value != fast->value) {
		        		flag++;
		            }
		            temp = temp->next;
		            fast = fast->next;
		        }
		        
				Second_list = Reverse_List(Second_list);
		        slow->next = Second_list;
		        
		        if(flag == 0){
					cout<<"Yes, It is a Palindrome..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"No, It is Not a Palindrome..."<<endl;
					system("PAUSE");
				}
			} 
		}
		
		void Count_Node(){
			if(head == NULL){
				cout<<"There is No Node To Count..."<<endl;
				system("PAUSE");
			}
			else{
				int counter = 0;
				S_Node *current = head;
				while(current != NULL ){
					counter++;
					current = current->next;
				}
				cout<<"Total No. of Node => "<<counter<<endl;
				system("PAUSE");	
			}	
		}
		
		void Max(){
			if(head == NULL){
				cout<<"There is No Node To Find Maximum..."<<endl;
				system("PAUSE");
			}
			else{
				S_Node *current = head;
				int max = current->value;
				
				while(current != NULL){
					if(current->value > max){
						max = current->value;
					}
					current = current->next;
				}
				cout<<"Maximum Value => "<<max<<endl;
				system("PAUSE");
			}		
		}
		
		void Average(){
			if(head == NULL){
				cout<<"There is No Node To Find Average..."<<endl;
				system("PAUSE");
			}
			else{
				S_Node *current = head;
				float avg, sum;
				
				while(current != NULL){
					sum += current->value;
					current = current->next;
				}
				avg = sum/size;
				cout<<"Average => "<<avg<<endl;
				system("PAUSE");
			}
		}	
		
		void Reverse(){
			if(head == NULL){
				cout<<"There is No Node To Reverse It..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				cout<<"There is One Node So, No Need To Reverse It..."<<endl;
				system("PAUSE");
			}
			else{
				head = Reverse_List(head);
			}
		}
		
		void Detect_Loop(){
			if(head == NULL){
				cout<<"There is No Node To Detect Loop..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				S_Node *slow = head;
				S_Node *fast = head;
				
				while(fast->next != NULL && fast->next->next != NULL){
					slow = slow->next;
					fast = fast->next->next;
					
					if(slow == fast){
						flag++;
					}
				}
				if(flag == 0){
					cout<<"No, Detection of Loop..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Yes, Detection of Loop..."<<endl;
					system("PAUSE");
				}
			}
		}

};

class Singly_Circular_Linked_List{
	private:
		S_Node *head;
		int size;
	public:
		Singly_Circular_Linked_List(){
			head = NULL;
			size = 0;
		}
		
		void Display(){
			system("CLS");
			if(head == NULL ){
				cout<<"Singly Circular Linked List is Empty..."<<endl;
				system("PAUSE");
			}
			else{
				cout<<"Displaying Singly Circular Linked List"<<endl;
				S_Node *current = head;
				do{
					cout<<current->value<<" ";
					current = current->next;
				}while(current != head);
				cout<<endl;
				system("PAUSE");
			}
		}
		
		void ADD_First(int value){
			S_Node *new_Node = new S_Node(value);
			if(head == NULL){
				new_Node->next = new_Node;
				head = new_Node;
			}
			else{
				S_Node *current = head;
				
				while(current->next != head){
					current = current->next;
				}
				
				new_Node->next = head;
				current->next = new_Node;
				head = new_Node;
			}
			size++;
		}
		
		void ADD_Last(int value){
			S_Node *new_Node = new S_Node(value);
			if(head == NULL){
				new_Node->next = new_Node; 
				head = new_Node;
			}
			else{
				S_Node *current = head;
				while(current->next != head){
					current = current->next;
				}
				current->next = new_Node;
				new_Node->next = head;
			}
			size++;
		}
		
		void Delete_First(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				S_Node *temp = head;
				head = NULL;
				delete temp;
				size--;
			}
			else{
				S_Node *temp = head;
				S_Node *current = head;
				while(current->next != head){
					current = current->next;
				}
				head = head->next;
				current->next = head;
				delete temp;
				size--;
			}	
		}
		
		void Delete_Last(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				S_Node *temp = head;
				head = NULL;
				delete temp;
				size--;
			}
			else{
				S_Node *current = head;
				S_Node *previous = NULL;
				while(current->next != head){
					previous = current;
					current = current->next;
				}
				current->next = NULL;
				previous->next = head;
				delete current;
				size--;
			}
		}
		
		void Insert_At(int value, int position){
			if(head == NULL){
				cout<<"There is No Node So Adding Node To 1st Place"<<endl;
				ADD_Last(value);
				system("PAUSE");
			}
			else{
				if(position > 0 && position <= size ){
					if(position == 1){
						ADD_First(value);	
					}
					else{
						S_Node *new_Node = new S_Node(value);
						S_Node *current = head;
						for(int i=1; i<position-1; i++){
							current = current->next;
						}
						new_Node->next = current->next;
						current->next = new_Node;
						size++;
					}
				}
				else{
					cout<<"Invalid Position... So, Node is Added to Last Place"<<endl;
					ADD_Last(value);
					system("PAUSE");
				}
			}		
		}
		
		void Search(int x){
			if(head == NULL){
				cout<<"There is No Node To Search..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				S_Node *current = head;
				do{
					if(current->value == x){
						flag++;
					}
					current = current->next;
				}while(current != head);
				
				if(flag == 0){
					cout<<"Value Not Found..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Value Found..."<<endl;
					system("PAUSE");
				}
			}
		}
		
		void Count_Node(){
			if(head == NULL){
				cout<<"There is No Node To Count..."<<endl;
				system("PAUSE");
			}
			else{
				int counter = 0;
				S_Node *current = head;
				do{
					counter++;
					current = current->next;
				}while(current != head);
				
				cout<<"\nTotal No. of Node => "<<counter<<endl;
				system("PAUSE");
			}
		}
		
		void Max(){
			if(head == NULL){
				cout<<"There is No Node To Find Maximum..."<<endl;
				system("PAUSE");
			}
			else{
				S_Node *current = head;
				int max = current->value;
				
				do{
					if(current->value > max){
						max = current->value;
					}
					current = current->next;
				}while(current != head);
				
				cout<<"Maximum Value => "<<max<<endl;
				system("PAUSE");
			}
		}
		
		void Average(){
			if(head == NULL){
				cout<<"There is No Node To Find Average..."<<endl;
				system("PAUSE");
			}
			else{
				S_Node *current = head;
				float avg, sum;
				
				do{
					sum += current->value;
					current = current->next;
				}while(current != head);
				
				avg = sum/size;
				cout<<"Average => "<<avg<<endl;
				system("PAUSE");
			}
		}	
		
		void Reverse(){
			if(head == NULL){
				cout<<"There is No Node To Reverse It..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				cout<<"There is One Node So, No Need To Reverse..."<<endl;
				system("PAUSE");
			}
			else{
				S_Node *current = head;
				S_Node *previous = NULL, *next = NULL;
				do{
					next = current->next;
					current->next = previous;
					previous = current;
					current = next;
				}while(current != head);
				head->next = previous;
				head = previous;
			}
		}
};

class Dubbly_Linked_List{
	private:
		D_Node *head;
		int size;
	public:
		Dubbly_Linked_List(){
			size = 0;
			head = NULL;
		}
		
		void Display(){
			system("CLS");
			if(head == NULL){
				cout<<"Doubly Linked List is Empty..."<<endl;
				system("PAUSE");
			}
			else{
				cout<<"Displaying Doubly Linked List"<<endl;
				D_Node *current = head;
				while(current != NULL){
					cout<<current->value<<" ";
					current = current->next;
				}
				cout<<endl;
				system("PAUSE");	
			}
		}
		
		void ADD_First(int value){
			D_Node* new_Node = new D_Node(value);
			if(head == NULL){
				head = new_Node;
			}
			else{
				new_Node->next = head;
				head->previous = new_Node;
				head = new_Node;
			}
			size++;
		}
		
		void ADD_Last(int value){
			D_Node *new_Node = new D_Node(value);
			if(head == NULL){
				head = new_Node;
			}
			else{
				D_Node *current = head;
				while(current->next != NULL){
					current = current->next;
				}
				current->next = new_Node;
				new_Node->previous = current;
			}
			size++;
		}
		
		void Insert_At(int value, int position){
			if(head == NULL){
				cout<<"There is No Node So Adding Node To 1st Place"<<endl;
				ADD_Last(value);
				system("PAUSE");
			}
			else{
				if(position > 0 && position <= size){
					
					if(position == 1){
						ADD_First(value);
					}
					else{
						D_Node *new_Node = new D_Node(value);
						D_Node *current = head;
						for(int i=1 ; i<position-1; i++){
							current = current->next;
						}
						new_Node->next = current->next;
						current->next->previous = new_Node;
						current->next = new_Node;
						new_Node->previous = current;
						size++;
					}		
				}
				else{
					cout<<"Invalid Position... So, Node is Added to Last Place"<<endl;
					ADD_Last(value);
					system("PAUSE");
				}
			}		
		}

		void Delete_First(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				D_Node* temp = head;
            	head = NULL;
            	delete temp;
            	size--;
			}
			else{
				D_Node *temp = head;
				head = head->next;
				delete temp;
				size--;
			}
		}
		
		void Delete_Last(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				D_Node* temp = head;
            	head = NULL;
            	delete temp;
            	size--;
            }
			else{
				D_Node *current = head;
				D_Node *previous = NULL;
				while(current->next != NULL){
					previous = current;
					current = current->next;
				}
				previous->next = NULL;
				delete current;
				size--;
			}
		}
		
		void Is_Palindrome(){
			if (head == NULL) {
	            cout<<"There is No Node To Check Palindrome..."<<endl;
	            system("PAUSE");
	        }
			else{
				int flag = 0;
				D_Node *left = head;
				D_Node *right = head;
				while(right->next != NULL){
					right = right->next;
				}
				while(left != right){
					if(left->value != right->value){
						flag++;
					}
					left = left->next;
					right = right->previous;
				}
				
				if(flag == 0){
					cout<<"Yes, It is a Palindrome..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"No, It is Not a Palindrome..."<<endl;
					system("PAUSE");
				}
			}
		}
		
		void Reverse(){
			if(head == NULL){
				cout<<"There is No Node To Reverse It..."<<endl;
				system("PAUSE");
			}
			else if(head->next == NULL){
				cout<<"There is One Node So, No Need To Reverse It..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *next_Node = NULL;
				D_Node *current = head;
				
				while(current != NULL){
					next_Node = current->previous;
					current->previous = current->next;
					current->next = next_Node;
					current = current->previous;
				}
				if(next_Node != NULL){
					head = next_Node->previous;
				}
			}
		}

		void Search(int x){
			if(head == NULL){
				cout<<"There is No Node To Search..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				D_Node *current = head;
				while(current != NULL ){
					if(current->value == x){
						flag++;
					}
					current = current->next;
				}
				if(flag == 0){
					cout<<"Value Not Found..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Value Found..."<<endl;
					system("PAUSE");
				}
			}
		}

		void Max(){
			if(head == NULL){
				cout<<"There is No Node To Find Maximum..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *current = head;
				int max = current->value;
				
				while(current != NULL){
					if(current->value > max){
						max = current->value;
					}
					current = current->next;
				}
				cout<<"Maximum Value => "<<max<<endl;
				system("PAUSE");
			}	
		}

		void Average(){
			if(head == NULL){
				cout<<"There is No Node To Find Average..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *current = head;
				float avg, sum;
				
				while(current != NULL){
					sum += current->value;
					current = current->next;
				}
				avg = sum/size;
				cout<<"Average => "<<avg<<endl;
				system("PAUSE");
			}
		}

		bool Detect_Loop(){
			if(head == NULL){
				cout<<"There is No Node To Detect Loop..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				D_Node *slow = head;
				D_Node *fast = head;
				
				while(fast->next != NULL && fast != NULL){
					slow = slow->next;
					fast = fast->next->next;
					
					if(slow == fast){
						flag++;
					}
				}
				
				if(flag == 0){
					cout<<"No, Detection of Loop..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Yes, Detection of Loop..."<<endl;
					system("PAUSE");
				}	
			}
		}

		void Count_Node(){
			if(head == NULL){
				cout<<"There is No Node To Count..."<<endl;
				system("PAUSE");
			}
			else{
				int counter = 0;
				D_Node *current = head;
				while(current != NULL ){
					counter++;
					current = current->next;
				}
				cout<<"Total No. of Node => "<<counter<<endl;
				system("PAUSE");
			}		
		}
};

class Dubbly_Circular_Linked_List{
	private:
		D_Node *head;
		int size;
	public:
		Dubbly_Circular_Linked_List(){
			size = 0;
			head = NULL;
		}
		
		void Display(){
			system("CLS");
			if(head == NULL ){
				cout<<"Dubly Circular Linked List is Empty..."<<endl;
				system("PAUSE");
			}
			else{
				cout<<"Displaying Dubly Circular Linked List..."<<endl;
				D_Node *current = head;
				do{
					cout<<current->value<<" ";
					current = current->next;
				}while(current != head);
				cout<<endl;
				system("PAUSE");
			}
		}
		
		void ADD_Last(int value){
			D_Node *new_Node = new D_Node(value);
			if(head == NULL){
				new_Node->next = new_Node;
				new_Node->previous = new_Node;
				head = new_Node;
			}
			else{
				D_Node *current = head;
				while(current->next != head){
					current = current->next;
				}
				current->next = new_Node;
				new_Node->previous = current;
				new_Node->next = head;
				head->previous = new_Node;
			}
			size++;
		}
		
		void ADD_First(int value){
			D_Node *new_Node = new D_Node(value);
			if(head == NULL){
				new_Node->next = new_Node;
				new_Node->previous = new_Node;
				head = new_Node;
			}
			else{
				D_Node *current = head;
				
				while(current->next != head){
					current = current->next;
				}
				
				new_Node->next = head;
				head->previous = new_Node;
				current->next = new_Node;
				new_Node->previous = current;
				head = new_Node;
			}
			size++;
		}		
		
		void Insert_At(int value, int position){
			if(head == NULL){
				cout<<"There is No Node So Adding Node To 1st Place"<<endl;
				ADD_Last(value);
				system("PAUSE");
			}
			else{
				if(position > 0 && position <= size){
				
					if(position == 1){
						ADD_First(value);
					}
					else{
						D_Node *new_Node = new D_Node(value);
						D_Node *current = head;
						for(int i=1 ; i<position-1; i++){
							current = current->next;
						}
						new_Node->next = current->next;
						current->next->previous = new_Node;
						current->next = new_Node;
						new_Node->previous = current;
						size++;
					}
				}
				else{
					cout<<"Invalid Position... So, Node is Added to Last Place"<<endl;
					ADD_Last(value);
					system("PAUSE");
				}	
			}
		}
		
		void Delete_First(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				D_Node *temp = head;
				head = NULL;
				delete temp;
				size--;
			}
			else{
				D_Node *current = head;
				D_Node *temp = head;
				while(current->next != head){
					current = current->next;
				}
				head = head->next;
				current->next = head;
				head->previous = current;
				delete temp;
				size--;
			}
		}
		
		void Delete_Last(){
			if(head == NULL){
				cout<<"There is Node To Delete..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				D_Node *temp = head;
				head = NULL;
				delete temp;
				size--;
			}
			else{
				D_Node *current = head;
				D_Node *previous = NULL;
				while(current->next != head){
					previous = current;
					current = current->next;
				}
				previous->next = head;
				head->previous = previous;
				delete current;
				size--;
			}		
		}

		void Reverse(){
			if(head == NULL){
				cout<<"There is No Node To Reverse It..."<<endl;
				system("PAUSE");
			}
			else if(head->next == head){
				cout<<"There is One Node So, No Need To Reverse..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *next = NULL;
				D_Node *current = head;
				
				do{
					next = current->previous;
					current->previous = current->next;
					current->next = next;
					current = current->previous;
				}while(current != head);
				
				head = next->previous;
			}
		}
				
		void Search(int x){
			if(head == NULL){
				cout<<"There is No Node To Search..."<<endl;
				system("PAUSE");
			}
			else{
				int flag = 0;
				D_Node *current = head;
				do{
					if(current->value == x){
						flag++;
					}
					current = current->next;
				}while(current != head);
				
				if(flag == 0){
					cout<<"Value Not Found..."<<endl;
					system("PAUSE");
				}
				else{
					cout<<"Value Found..."<<endl;
					system("PAUSE");
				}
			}
		}

		void Max(){
			if(head == NULL){
				cout<<"There is No Node To Find Maximum..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *current = head;
				int max = current->value;
				
				do{
					if(current->value > max){
						max = current->value;
					}
					current = current->next;
				}while(current != head);
				
				cout<<"Maximum Value => "<<max<<endl;
				system("PAUSE");
			}	
		}
		
		void Average(){
			if(head == NULL){
				cout<<"There is No Node To Find Average..."<<endl;
				system("PAUSE");
			}
			else{
				D_Node *current = head;
				float avg, sum=0;
				
				do{
					sum += current->value;
					current = current->next;
				}while(current != head);
				
				avg = sum/size;
				cout<<"Average => "<<avg<<endl;
				system("PAUSE");
			}	
		}	

		void Count_Node(){
			if(head == NULL){
				cout<<"There is No Node To Count..."<<endl;
				system("PAUSE");
			}
			else{
				int counter = 0;
				D_Node *current = head;
				do{
					counter++;
					current = current->next;
				}while(current != head);
				
				cout<<"Total No. of Node => "<<counter<<endl;
				system("PAUSE");
			}		
		}
};

void Menu_of_Singly_Linked_List(){
	system("CLS");
	Singly_Linked_List SLL;
	int choice;
	do{
		system("CLS");
		cout<<"\t\t\t\t Singly Linked List"<<endl;
		cout<<"Press => 1. ADD FIRST"<<endl;
		cout<<"Press => 2. ADD LAST"<<endl;
		cout<<"Press => 3. DELETE FIRST"<<endl;
		cout<<"Press => 4. DELETE LAST"<<endl;
		cout<<"Press => 5. INSERT AT"<<endl;
		cout<<"Press => 6. SEARCH"<<endl;
		cout<<"Press => 7. CHECK PALINDROME"<<endl;
		cout<<"Press => 8. COUNT NODES"<<endl;
		cout<<"Press => 9. MAXIMUM"<<endl;
		cout<<"Press => 10. AVERAGE"<<endl;
		cout<<"Press => 11. REVERSE"<<endl;
		cout<<"Press => 12. DETECT LOOP"<<endl;
		cout<<"Press => 0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice => ";
		cin>>choice;
		switch (choice) {
            case 1:
            	{
            		int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	SLL.ADD_First(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					SLL.Display();
				}
                break;
            case 2:
	            {
	            	int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	SLL.ADD_Last(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					SLL.Display();
				}
                break;
            case 3:
                system("CLS");
                SLL.Delete_First();
				SLL.Display();
				break;
            case 4:
                system("CLS");
                SLL.Delete_Last();
				SLL.Display();
                break;
            case 5:
            	int value, pos;
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	cout<<"Enter Position => ";
            	cin>>pos;
            	SLL.Insert_At(value, pos);
				SLL.Display();
            	break;
            case 6:
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	SLL.Search(value);
            	break;
            case 7:
            	system("CLS");
            	SLL.Is_Palindrome();
            	break;
            case 8:
            	system("CLS");
            	SLL.Count_Node();
            	break;
            case 9:
            	system("CLS");
            	SLL.Max();
            	break;
            case 10:
            	system("CLS");
            	SLL.Average();
            	break;
            case 11:
            	system("CLS");
            	SLL.Reverse();
            	SLL.Display();
            	break;
            case 12:
            	system("CLS");
            	SLL.Detect_Loop();
            	break;
            case 0:
            	int main();
            	break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }
	}while(choice !=0);
}

void Menu_of_Singly_Circular_Linked_List(){
	system("CLS");
	Singly_Circular_Linked_List SCLL;
	int choice;
	do{
		system("CLS");
		cout<<"\t\t\t\t\t Singly Circular Linked List"<<endl;
		cout<<"Press => 1. ADD FIRST"<<endl;
		cout<<"Press => 2. ADD LAST"<<endl;
		cout<<"Press => 3. DELETE FIRST"<<endl;
		cout<<"Press => 4. DELETE LAST"<<endl;
		cout<<"Press => 5. INSERT AT"<<endl;
		cout<<"Press => 6. SEARCH"<<endl;
		cout<<"Press => 7. COUNT NODES"<<endl;
		cout<<"Press => 8. MAXIMUM"<<endl;
		cout<<"Press => 9. AVERAGE"<<endl;
		cout<<"Press => 10. REVERSE"<<endl;
		cout<<"Press => 0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice => ";
		cin>>choice;
		switch (choice) {
            case 1:
            	{
            		int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	SCLL.ADD_First(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					SCLL.Display();
				}
                break;
            case 2:
	            {
	            	int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	SCLL.ADD_Last(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					SCLL.Display();
				}
                break;
            case 3:
                system("CLS");
                SCLL.Delete_First();
				SCLL.Display();
				break;
            case 4:
                system("CLS");
                SCLL.Delete_Last();
				SCLL.Display();
                break;
            case 5:
            	int value, pos;
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	cout<<"Enter Position => ";
            	cin>>pos;
            	SCLL.Insert_At(value, pos);
				SCLL.Display();
            	break;
            case 6:
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	SCLL.Search(value);
            	break;
            case 7:
            	system("CLS");
            	SCLL.Count_Node();
            	break;
            case 8:
            	system("CLS");
            	SCLL.Max();
            	break;
            case 9:
            	system("CLS");
            	SCLL.Average();
            	break;
            case 10:
            	system("CLS");
            	SCLL.Reverse();
            	SCLL.Display();
            	break;
            case 0:
            	int main();
            	break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }
	}while(choice !=0);
}

void Menu_of_Doubly_Linked_List(){
	system("CLS");
	Dubbly_Linked_List DLL;
	int choice;
	do{
		system("CLS");
		cout<<"\t\t\t\t\t Doubly Linked List"<<endl;
		cout<<"Press => 1. ADD FIRST"<<endl;
		cout<<"Press => 2. ADD LAST"<<endl;
		cout<<"Press => 3. DELETE FIRST"<<endl;
		cout<<"Press => 4. DELETE LAST"<<endl;
		cout<<"Press => 5. INSERT AT"<<endl;
		cout<<"Press => 6. SEARCH"<<endl;
		cout<<"Press => 7. CHECK PALINDROME"<<endl;
		cout<<"Press => 8. COUNT NODES"<<endl;
		cout<<"Press => 9. MAXIMUM"<<endl;
		cout<<"Press => 10. AVERAGE"<<endl;
		cout<<"Press => 11. REVERSE"<<endl;
		cout<<"Press => 12. DETECT LOOP"<<endl;
		cout<<"Press => 0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice => ";
		cin>>choice;
		switch (choice) {
            case 1:
            	{
            		int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	DLL.ADD_First(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					DLL.Display();
				}
                break;
            case 2:
	            {
	            	int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	DLL.ADD_Last(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					DLL.Display();
				}
                break;
            case 3:
                system("CLS");
                DLL.Delete_First();
				DLL.Display();
				break;
            case 4:
                system("CLS");
                DLL.Delete_Last();
				DLL.Display();
                break;
            case 5:
            	int value, pos;
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	cout<<"Enter Position => ";
            	cin>>pos;
            	DLL.Insert_At(value, pos);
				DLL.Display();
            	break;
            case 6:
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	DLL.Search(value);
            	break;
            case 7:
            	system("CLS");
            	DLL.Is_Palindrome();
            	break;
            case 8:
            	system("CLS");
            	DLL.Count_Node();
            	break;
            case 9:
            	system("CLS");
            	DLL.Max();
            	break;
            case 10:
            	system("CLS");
            	DLL.Average();
            	break;
            case 11:
            	system("CLS");
            	DLL.Reverse();
            	DLL.Display();
            	break;
            case 12:
            	system("CLS");
            	DLL.Detect_Loop();
            	break;
            case 0:
            	int main();
            	break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }
	}while(choice !=0);
}

void Menu_of_Doubly_Circular_Linked_List(){
	system("CLS");
	Dubbly_Circular_Linked_List DCLL;
	int choice;
	do{
		system("CLS");
		cout<<"\t\t\t\t\t Dubbly Circular Linked List"<<endl;
		cout<<"Press => 1. ADD FIRST"<<endl;
		cout<<"Press => 2. ADD LAST"<<endl;
		cout<<"Press => 3. DELETE FIRST"<<endl;
		cout<<"Press => 4. DELETE LAST"<<endl;
		cout<<"Press => 5. INSERT AT"<<endl;
		cout<<"Press => 6. SEARCH"<<endl;
		cout<<"Press => 7. COUNT NODES"<<endl;
		cout<<"Press => 8. MAXIMUM"<<endl;
		cout<<"Press => 9. AVERAGE"<<endl;
		cout<<"Press => 10. REVERSE"<<endl;
		cout<<"Press => 0. RETURN"<<endl;
		cout<<"\n\nEnter Your choice => ";
		cin>>choice;
		switch (choice) {
            case 1:
            	{
            		int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	DCLL.ADD_First(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					DCLL.Display();
				}
                break;
            case 2:
	            {
	            	int value;
	            	char ch;
	                do{
	                	system("CLS");
	                	cout<<"Enter Value => ";
	                	cin>>value;
	                	DCLL.ADD_Last(value);
	                	cout<<"Enter Value Again (Y / N) => ";
	                	cin>>ch;
					}while(ch == 'Y' || ch == 'y');
					DCLL.Display();
				}
                break;
            case 3:
                system("CLS");
                DCLL.Delete_First();
				DCLL.Display();
				break;
            case 4:
                system("CLS");
                DCLL.Delete_Last();
				DCLL.Display();
                break;
            case 5:
            	int value, pos;
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	cout<<"Enter Position => ";
            	cin>>pos;
            	DCLL.Insert_At(value, pos);
				DCLL.Display();
            	break;
            case 6:
            	system("CLS");
            	cout<<"Enter Value => ";
            	cin>>value;
            	DCLL.Search(value);
            	break;
            case 7:
            	system("CLS");
            	DCLL.Count_Node();
            	break;
            case 8:
            	system("CLS");
            	DCLL.Max();
            	break;
            case 9:
            	system("CLS");
            	DCLL.Average();
            	break;
            case 10:
            	system("CLS");
            	DCLL.Reverse();
            	DCLL.Display();
            	break;
            case 0:
            	int main();
            	break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }
	}while(choice !=0);
}

int main(){
	int choice;
    do {
		system("CLS");
        cout<<"Press => 1. SINGLY LINKED LIST"<<endl;
        cout<<"Press => 2. SINGLY CIRCULAR LINKED LIST"<<endl;
        cout<<"Press => 3. DOUBLY LINKED LIST"<<endl;
        cout<<"Press => 4. DOUBLY CIRCULAR LINKED LIST"<<endl;
        cout<<"Press => 0. EXIT"<<endl;
        cout<<"\n\nEnter Your choice => ";
        cin>>choice;

        switch(choice) {
            case 1:
                Menu_of_Singly_Linked_List();
                break;
            case 2:
                Menu_of_Singly_Circular_Linked_List();
                break;
            case 3:
                Menu_of_Doubly_Linked_List();
                break;
            case 4:
                Menu_of_Doubly_Circular_Linked_List();
                break;
            case 0:
                cout<<"Program END..."<<endl;
                break;
            default:
                cout<<"Invalid choice..."<<endl<<endl;
                system("PAUSE");
                system("CLS");
        }

    } while (choice != 0);
}
