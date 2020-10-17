#include<stdio.h>

struct node{
	
	int state[2];

	node* children[6];
	bool deadend;

	node(){
		state[0] = 0;
		state[1] = 0;
		deadend = false;
	}
};


node* duplicateNode(node* currentNode, int i){
	node *temp = new node;



	temp -> state[0] = currentNode->state[0];
	temp -> state[1] = currentNode->state[1];

	return temp;
}



void one_to_two(node* currentNode){
	
	while (currentNode -> state[1] < 3)
	{
		if(currentNode -> state[0] != 0){
			currentNode -> state[0] --;
			currentNode -> state[1]++;
		}
		else
			break;	
	}
}

void two_to_one(node* currentNode){
	
	while (currentNode -> state[0] < 4)
	{
		if(currentNode -> state[1] != 0){
			currentNode -> state[1] --;
			currentNode -> state[0]++;
		}
		else
			break;
	}
}

void fill_One(node* currentNode){
	currentNode -> state[0] = 4;
}

void fill_Two(node* currentNode){
	currentNode -> state[1] = 3;
}

void empty_One(node* currentNode){
	currentNode -> state[0] = 0;
}

void empty_Tow(node* currentNode){
	currentNode -> state[1] = 0;
}


bool update(node* currentNode){

	if(currentNode -> state[0] == 0)
		if(currentNode -> state[1] == 1){
			printf("yayyyy it worked");
			return false;
		}
	
		for(int i = 0; i < 6; i++)
			 currentNode -> children[i] = duplicateNode(currentNode, i);

	fill_One(currentNode -> children[0]);
	fill_Two(currentNode -> children[1]);
	one_to_two(currentNode -> children[2]);
	two_to_one(currentNode -> children[3]);
	empty_One(currentNode -> children[4]);
	empty_Tow(currentNode -> children[5]);

	//printf((currentNode.children[3]).state[0]);
	//printf((currentNode.children[3]).state[1]);

}



void main(){
	
	node main;
		
	int jugsMaxCap[2];
	jugsMaxCap[0] = 4;
	jugsMaxCap[1] = 3;

	update(&main);

	update(&main);

	update(&main);

	update(&main);

}