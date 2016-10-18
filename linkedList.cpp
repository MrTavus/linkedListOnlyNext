#include <iostream>
using namespace std;


//The structure of the node.
struct node{

	int data;
	node * next;
};

//Root node
node * rootNode = new node();

//The functions will be used.
void insert(int);
void showAllElement();
void find(int);
bool isEmpty();
void destroy();

//Main function
int main(){

	int data = 1;	
		
	cout << "Enter an integer value : ";
	cin >> data;

	while(data>0){
		//Insert a value at the last of the node.
		insert(data);
		cout << "Enter an integer value : ";
		cin >> data;
	}

	//Show all element in the linked list
	showAllElement();

	//Find the value sending in the parameter.
	find(4);

	//Check the node whether it is empty or not.
	if(isEmpty())
		cout << "Tree is empty.\n";
	else 
		cout << "Tree is not empty.\n";

	//Destroy the node.
	destroy();
	
}

void insert(int data){
	
	if(!rootNode){
		rootNode->data = data;		
		return;
	}
	
	node *nNode = new node();
	nNode->data = data;
	node * currentNode = rootNode;	
	
	while(1){
		if(!currentNode->next){
			currentNode->next = nNode;
			return;	
		}	
		currentNode = currentNode->next;
	}

}

void showAllElement(){
	node * traversalNode = rootNode->next;
	int count = 0;
	while(traversalNode){
		cout <<++count<<". node : "<< traversalNode->data << "\n";
		traversalNode = traversalNode->next;
	}

}

void find(int data){

	if(!rootNode){
		rootNode->data = data;		
		return;
	}
	
	node *nNode = new node();
	nNode->data = data;
	node * currentNode = rootNode;	
	int count = 0;
	while(currentNode){
		if(currentNode->data == data){
			cout <<"Data was founded in "<<count<<"th node.\n";
			return;	
		}	
		currentNode = currentNode->next;
		count++;	
	}
	
	cout <<"Data wasn't founded.\n";
}

bool isEmpty(){
	return rootNode == NULL;
}

void destroy(){
	rootNode = NULL;
}
