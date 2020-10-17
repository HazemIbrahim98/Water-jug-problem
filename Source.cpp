#include<stdio.h>

int finishedPoints[50][2];
int index = 0;

int jugsMaxCap[2];
int wantToFind[2];

struct node {
	int state[2];

	node* children[6];
	bool deadend;

	node() {
		state[0] = 0;
		state[1] = 0;

		deadend = false;
	}
};

node* duplicateNode(node* currentNode, int i) {
	node* temp = new node;

	temp->state[0] = currentNode->state[0];
	temp->state[1] = currentNode->state[1];
	temp->deadend = false;

	return temp;
}

void fill(node* currentNode, int index) {
	currentNode->state[index] = jugsMaxCap[index];
}
void swap(node* currentNode, int index) {
	if (index == 0) {
		while (currentNode->state[1] < 3)
		{
			if (currentNode->state[0] != 0) {
				currentNode->state[0] --;
				currentNode->state[1]++;
			}
			else
				break;
		}
	}
	else {
		while (currentNode->state[0] < 4)
		{
			if (currentNode->state[1] != 0) {
				currentNode->state[1] --;
				currentNode->state[0]++;
			}
			else
				break;
		}

	}
}
void empty(node* currentNode, int index) {
		currentNode->state[index] = 0;
}

bool repeated(node* currentNode) {
	for (int i = 0; i < index; i++) {
		if (finishedPoints[i][0] == currentNode->state[0] && finishedPoints[i][1] == currentNode->state[1])
			return true;
	}
	return false;
}

bool winCondition(node* currentNode) {
	//	for each state element check if it is equal to the end
	for (int i = 0; i < 2; i++)
	{
		if (currentNode->state[i] != wantToFind[i])
			return false;
	}

	printf("YAYYY I found it :p\n");
	return true;
}

bool update(node* currentNode) {
	if (winCondition(currentNode))
		return true;

	if (currentNode->deadend == true)
		return false;

	if (repeated(currentNode)) {
		currentNode->deadend = true;
		return false;
	}
	else {
		for (int i = 0; i < 6; i++)
			currentNode->children[i] = duplicateNode(currentNode, i);

		fill(currentNode->children[0], 0);
		fill(currentNode->children[1], 1);
		swap(currentNode->children[2], 0);
		swap(currentNode->children[3], 1);
		empty(currentNode->children[4], 0);
		empty(currentNode->children[5], 1);
	}

	finishedPoints[index][0] = currentNode->state[0];
	finishedPoints[index][1] = currentNode->state[1];
	index++;

	return false;
}

bool navigate(node* currentNode) {

	if (update(currentNode) == true)
	{
		return true;
	}

	if (currentNode->deadend == false)
		for (int i = 0; i < 6; i++)
		{
			if (navigate(currentNode->children[i]) == true)
				return true;
		}

	return false;
}

int main() {

	node main;

	jugsMaxCap[0] = 4;
	jugsMaxCap[1] = 3;

	wantToFind[0] = 0;
	wantToFind[1] = 1;


	printf("Starting\n");
	navigate(&main);
	printf("Done :)\n");

	return 0;
}
