#include <iostream>
#include <queue>
using std::cout;
using std::queue;


class Node {
public:
	Node* left;
	Node* right;
	int data;
	Node(int);
	Node(int, Node*, Node*);
};

 Node::Node(int input) {
	 this->left = nullptr;
	 this->right = nullptr;
	 this->data = input;
}

 Node::Node(int input, Node* left, Node* right) {
	 this->left = left;
	 this->right = right;
	 this->data = input;
 }

 void bfs(Node*);
 void dfs(Node*);
 void recursionTraverse(Node*);

 int main() {
	 Node* root = new Node(1,
		 new Node(2,
			 new Node(4), new Node(5))
		 , new Node(3,
			 new Node(6), new Node(7,
				 new Node(8), nullptr)));

	 //bfs(root);
	 //dfs(root);
	 recursionTraverse(root);
 }

 void bfs(Node* root) {  //bad idea calling it root
	 queue <Node*> q;
	 q.push(root);

	 while (!q.empty()) {
		 root = q.front();

		 cout << root->data << " ";
		 q.pop();
		 if (root->left != nullptr) {
			 q.push(root->left);
		 }
		 if (root->right != nullptr) {
			 q.push(root->right);
		 }
	 }
 }

 void dfs(Node* node) {
	 if (node == nullptr) {
		 return;
	 }
	 cout << node->data << " ";
	 dfs(node->left);
	 dfs(node->right);

 }

 void recursionTraverse(Node* node) {
	 if (node == nullptr) {
		 return;
	 }
	 
	 recursionTraverse(node->left);
	 recursionTraverse(node->right);
	 cout << node->data;
 }