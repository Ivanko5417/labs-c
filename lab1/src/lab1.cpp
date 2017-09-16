#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Node
{
	char name[10];	//имя узла
	Node * left;		//левая ветвь
	Node * right;		//правая ветвь
};

int max(int a,int  b) {
	return a > b ? a : b;
}

int TreeHeight(Node* node) {
	if(node == NULL)
		return 0;
	return 1 + max(TreeHeight(node->left), TreeHeight(node->right));
}
Node* enterNodeName() {
	Node* newNode = new Node;
	cout << "Enter name: ";
	cin >> newNode->name;
	return newNode;
}

void nameOfCurrentNode(Node* node) {
	cout << "[" << node->name << "] ";
}

int showMenu(Node* node) {
	cout << endl;
	nameOfCurrentNode(node);
	cout << "1.Go left." << endl;
	nameOfCurrentNode(node);
	cout << "2.Go right." << endl;
	nameOfCurrentNode(node);
	cout << "3.Go back." << endl;
	nameOfCurrentNode(node);
	cout << "4.Exit." << endl;
	int menuItem = 0;
	while (menuItem < 1 || menuItem > 4) {
		cout << "Enter menu item: ";
		cin >> menuItem;
		if (menuItem < 1 || menuItem > 4) {
			cout << "Wrong menu item. ";
		}
	}
	return menuItem;
}

void Input(Node* root) {
	Node* nodes[100];
	int current = 0;
	nodes[current] = root;

	while(true)
		switch (showMenu(nodes[current])) {
			case 1: // left
				if (!nodes[current]->left) {
					cout << "Node is not exists. " << endl;
					nodes[current]->left = enterNodeName();
				}
				current++;
				nodes[current] = nodes[current-1]->left;
				break;
			case 2: // right
				if (!nodes[current]->right) {
					cout << "Node is not exists. " << endl;
					nodes[current]->right = enterNodeName();
				}
				current++;
				nodes[current] = nodes[current-1]->right;
				break;
			case 3: // back
				if(!current)
					break;
				current--;
				break;
			case 4: // exit
				return;
				break;
		}
}

bool IsBalancedTree(Node* node) {
	if(!node) return true;
	if(TreeHeight(node->left) - TreeHeight(node->right) > 1)
		return false;
	return IsBalancedTree(node->left) && IsBalancedTree(node->right);
}

void printBool(bool a){
	a ? cout << "Yes" : cout << "No";
}

int main() {
	Node* root = new Node;
	strcpy(root->name, "root");
	Input(root);
	cout << "Max length: " << TreeHeight(root) << endl;
	cout << "Is balanced: ";
	printBool(IsBalancedTree(root));
	return 0;
}
