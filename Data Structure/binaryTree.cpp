/*
	这个文件主要是二叉树基本算法的实现。包括：
	1. 根据输入/前序遍历数组构建二叉树
	2. 二叉树前序遍历、中序遍历、后序遍历的递归与非递归实现
	3. 二叉树层次遍历的实现
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* createTreeWithInput() {
	TreeNode* node = new TreeNode;
	int data;
	cin >> data;

	if (data == -1) {
		node = NULL;
	}
	else {
		node->val = data;
		node->left = createTreeWithInput();
		node->right = createTreeWithInput();
	}

	return node;
}

TreeNode* createTreeWithPreOrderVector(vector<int> treeNodes, int* loc) {
	TreeNode* node = new TreeNode;
	int data = treeNodes[*loc];
	*loc += 1;

	if (data == -1) {
		node = NULL;
	}
	else {
		node->val = data;
		node->left = createTreeWithPreOrderVector(treeNodes, loc);
		node->right = createTreeWithPreOrderVector(treeNodes, loc);
	}

	return node;
}

void preOrder(TreeNode* root) {
	if (root != NULL) {
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void myPreOrder(TreeNode* root) {
	stack<TreeNode*> s;
	if (root != NULL) {
		s.push(root);
	}

	while (!s.empty()) {
		TreeNode* temp = s.top();
		cout << temp->val << " ";
		s.pop();

		if (temp->right != NULL) {
			s.push(temp->right);
		}
		if (temp->left != NULL) {
			s.push(temp->left);
		}
	}
}

void inOrder(TreeNode* root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->val << " ";
		inOrder(root->right);
	}
}

void myInOrder(TreeNode* root) {
	stack<pair<TreeNode*, bool>> s;
	if (root != NULL) {
		s.push(pair<TreeNode*, bool>(root, false));
	}


	while (!s.empty()) {
		pair<TreeNode*, bool> temp = s.top();
		TreeNode* node = temp.first;
		bool visited = temp.second;

		if (node->left != NULL && visited == false) {
			temp.second = true;
			s.pop();
			s.push(temp);
			s.push(pair<TreeNode*, bool>(node->left, false));
		}
		else {
			cout << node->val << " ";
			s.pop();
			if (node->right != NULL) {
				s.push(pair<TreeNode*, bool>(node->right, false));
			}
		}
	}
}

void postOrder(TreeNode* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << " ";
	}
}

void myPostOrder(TreeNode* root) {
	stack<pair<TreeNode*, bool>> s;
	if (root != NULL) {
		s.push(pair<TreeNode*, bool>(root, false));
	}

	while (!s.empty()) {
		pair<TreeNode*, bool> temp = s.top();
		TreeNode* node = temp.first;
		bool visited = temp.second;

		if (visited == false && (node->left != NULL || node->right != NULL)) {
			temp.second = true;
			s.pop();
			s.push(temp);
			if (node->right != NULL) {
				s.push(pair<TreeNode*, bool>(node->right, false));
			}
			if (node->left != NULL) {
				s.push(pair<TreeNode*, bool>(node->left, false));
			}
		}
		else {
			cout << node->val << " ";
			s.pop();
		}
	}
}

void levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	if (root != NULL) {
		q.push(root);
	}

	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		cout << temp->val << " ";

		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

int main() {

	// vector<int> treeNodes = { -1 };
	// vector<int> treeNodes = { 1,2,4,-1,-1,5,6,-1,-1,7,-1,-1,3,-1,-1 };
	vector<int> treeNodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,7,-1,-1,8,-1,-1 };
	// vector<int> treeNodes = { 1, 2, 3, -1, -1, -1, -1 };

	int loc = 0;
	TreeNode* root = createTreeWithPreOrderVector(treeNodes, &loc);

	cout << "show the results: ";

	cout << endl << "traverse the tree recursively in preorder: ";
	preOrder(root);

	cout << endl << "my preoder: ";
	myPreOrder(root);

	cout << endl << "traverse the tree recursively in inorder: ";
	inOrder(root);

	cout << endl << "my inoder: ";
	myInOrder(root);

	cout << endl << "traverse the tree recursively in postorder: ";
	postOrder(root);

	cout << endl << "my postorder: ";
	myPostOrder(root);

	cout << endl << "traveser the tree in levelorder: ";
	levelOrder(root);

	return 0;
}


