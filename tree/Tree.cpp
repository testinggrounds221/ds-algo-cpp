#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
	Node* lchild;
	int val;
	Node* rchild;
	Node() {};
	Node(int val);
};

Node::Node(int val) {
	lchild = nullptr;
	this->val = val;
	rchild = nullptr;
}

class Tree {
private:
	Node* root;

public:
	Tree();

	void implement();

	void Preorder() { Preorder(root); }
	void Preorder(Node* ptr);

	void Inorder() { Inorder(root); }
	void Inorder(Node* ptr);

	void Postorder() { Postorder(root); }
	void Postorder(Node* ptr);



	int height() { return height(root); }
	int height(Node* ptr);

	void iterativePreorder() { iterativePreorder(root); }
	void iterativePreorder(Node* ptr);
	void iterativeInorder(Node* p);
	void iterativeInorder() { iterativeInorder(root); }
	void iterativePostorder(Node* p);
	void iterativePostorder() { iterativePostorder(root); }
	void iterativeLevelorder(Node* p);
	void iterativeLevelorder() { iterativeLevelorder(root); }
	Node* generateFromTraversal(int* inorder, int* preorder, int inStart, int inEnd);

	int countLeafNodes(Node* ptr);
	int countLeafNodes() { return countLeafNodes(root); }

	int countDeg2Nodes(Node* ptr);
	int countDeg2Nodes() { return countDeg2Nodes(root); }

	int countDeg1Nodes(Node* ptr);
	int countDeg1Nodes() { return countDeg1Nodes(root); }
};

Tree::Tree() {
	root = nullptr;
}

void Tree::Preorder(Node* ptr) {
	if (ptr) {
		cout << ptr->val << "->";
		Preorder(ptr->lchild);
		Preorder(ptr->rchild);
	}
}

void Tree::Inorder(Node* ptr) {
	if (ptr) {
		Inorder(ptr->lchild);
		cout << ptr->val << "->";
		Inorder(ptr->rchild);
	}
}

void Tree::iterativePreorder(Node* ptr) {
	stack<Node*> stk;

	while (ptr || !stk.empty()) {
		if (ptr) {
			cout << ptr->val << ",";
			stk.emplace(ptr);
			ptr = ptr->lchild;
		}
		else {
			ptr = stk.top();
			stk.pop();
			ptr = ptr->rchild;
		}
	}

}

void Tree::iterativeInorder(Node* ptr) {
	cout << "here";
	stack<Node*> stk;
	while (ptr || !stk.empty()) {
		if (ptr) {
			stk.emplace(ptr);
			ptr = ptr->lchild;
		}
		else {
			ptr = stk.top();
			stk.pop();
			cout << ptr->val << ",";
			ptr = ptr->rchild;
		}
	}
}

void Tree::iterativePostorder(Node* ptr) {
	stack<long int> stk;
	long int temp;
	while (ptr || !stk.empty()) {
		if (ptr) {
			stk.emplace((long int)ptr);
			ptr = ptr->lchild;
		}
		else {
			temp = stk.top();
			stk.pop();
			if (temp > 0) {
				stk.emplace(-temp);
				ptr = ((Node*)temp)->rchild;
			}
			else {
				cout << ((Node*)(-1 * temp))->val << ",";
				ptr = nullptr;
			}

		}
	}

}

void Tree::iterativeLevelorder(Node* ptr) {
	queue<Node*> q;
	cout << ptr->val << ",";
	q.emplace(ptr);
	while (!q.empty()) {
		ptr = q.front();
		q.pop();
		if (ptr->lchild) {
			cout << ptr->lchild->val << ",";
			q.emplace(ptr->lchild);
		}
		if (ptr->rchild) {
			cout << ptr->rchild->val << ",";
			q.emplace(ptr->rchild);
		}
	}
}

void Tree::Postorder(Node* ptr) {
	if (ptr) {
		Postorder(ptr->lchild);
		Postorder(ptr->rchild);
		cout << ptr->val << "->";
	}
}

int Tree::height(Node* ptr) {
	if (!ptr) return 0;
	int l = height(ptr->lchild);
	int r = height(ptr->rchild);
	if (l > r) return l + 1;
	else return r + 1;

}

void Tree::implement() {

	queue<Node*> q;
	int x;

	Node* ptr;
	Node* t;
	root = new Node;

	cout << "Enter Root Data : ";
	cin >> root->val;
	root->lchild = nullptr;
	root->rchild = nullptr;
	q.emplace(root);

	while (!q.empty()) {
		ptr = q.front();
		q.pop();

		cout << "\nEnter Left Data of Node " << ptr->val << " : ";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->val = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			ptr->lchild = t;
			q.emplace(t);
		}

		cout << "\nEnter Right Data of Node " << ptr->val << " : ";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->lchild = nullptr;
			t->rchild = nullptr;
			t->val = x;
			ptr->rchild = t;
			q.emplace(t);
		}
	}
}

int searchInorder(int inArray[], int inStart, int inEnd, int data) {
	for (int i = inStart; i <= inEnd; i++) {
		if (inArray[i] == data) {
			return i;
		}
	}
	return -1;
}

Node* Tree::generateFromTraversal(int* inorder, int* preorder, int inStart, int inEnd) {
	static int preIndex = 0;

	if (inStart > inEnd) {
		return nullptr;
	}

	Node* node = new Node(preorder[preIndex++]);

	if (inStart == inEnd) {
		return node;
	}

	int splitIndex = searchInorder(inorder, inStart, inEnd, node->val);
	node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
	node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

	return node;
}

int Tree::countDeg1Nodes(Node* ptr) {
	// count LR' + L'R => XOR => ^
	int x = 0;
	int y = 0;
	if (ptr) {
		x = countDeg1Nodes(ptr->lchild);
		y = countDeg1Nodes(ptr->rchild);
		if (ptr->lchild != nullptr ^ ptr->rchild != nullptr) return x + y + 1;
		return x + y;
	}
	return 0;
}

int Tree::countDeg2Nodes(Node* ptr) {
	int x = 0;
	int y = 0;
	if (ptr) {
		x = countDeg2Nodes(ptr->lchild);
		y = countDeg2Nodes(ptr->rchild);
		if (ptr->lchild && ptr->rchild) return x + y + 1;
		return x + y;
	}
	return 0;
}

int Tree::countLeafNodes(Node* ptr) {
	int x = 0;
	int y = 0;
	if (ptr) {
		x = countLeafNodes(ptr->lchild);
		y = countLeafNodes(ptr->rchild);
		if (!ptr->lchild && !ptr->rchild) return x + y + 1;
		return x + y;
	}
	return 0;
}

int main(int argc, char const* argv[])
{
	Tree tr;
	tr.implement();

	// cout << "Preorder Traversal : ";
	// tr.Preorder();
	// cout << endl;
	// cout << "Inorder Traversal : ";
	// tr.Inorder();
	// cout << endl;
	// cout << "Iteractive Inorder Traversal : ";
	// tr.iterativeInorder();
	// cout << endl;
	// cout << "Postorder Traversal : ";
	// tr.Postorder();
	// cout << endl;
	// cout << "Iteractive PostOrder Traversal : ";
	// tr.iterativePostorder();
	// cout << endl;

	cout << "iterativelevelorder Traversal : ";
	cout << "\nNumber of 0 Degree Nodes : " << tr.countLeafNodes();
	cout << "\nNumber of 1 Degree Nodes : " << tr.countDeg1Nodes();
	cout << "\nNumber of 2 Degree Nodes : " << tr.countDeg2Nodes();

	cout << endl;


	return 0;
}
