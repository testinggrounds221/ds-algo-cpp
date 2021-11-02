#include<iostream>
#include<stack>

using namespace std;

class Node {
public:
	Node* lchild;
	int val;
	Node* rchild;
};

class BST {
public:
	Node* root;
	BST();

	Node* rInsert(int key) { return rInsert(root, key); }
	Node* rInsert(Node* ptr, int key);

	void iInsert(int key) { iInsert(root, key); }
	void iInsert(Node* ptr, int key);

	void Inorder(Node* ptr);
	void Inorder() { Inorder(root); }

	void Preorder(Node* ptr);
	void Preorder() { Preorder(root); }


	Node* iSearch(int key);

	Node* rSearch(int key) { return rSearch(root, key); }
	Node* rSearch(Node* ptr, int key);

	Node* inorderPredecessor(Node* ptr);
	Node* inorderSuccessor(Node* ptr);

	Node* rDelete(int key) { return rDelete(root, key); }
	Node* rDelete(Node* ptr, int key);

	void fromPreorder(int* pre, int n);
};

int height(Node* ptr) {
	if (!ptr) return 0;
	int l = height(ptr->lchild);
	int r = height(ptr->rchild);
	if (l > r) return l + 1;
	else return r + 1;
}

BST::BST() {
	root = nullptr;
}

Node* BST::inorderPredecessor(Node* ptr) {
	while (ptr && ptr->rchild) ptr = ptr->rchild;
	return ptr;
}

Node* BST::inorderSuccessor(Node* ptr) {
	while (ptr && ptr->lchild) ptr = ptr->lchild;
	return ptr;
}

Node* BST::rDelete(Node* ptr, int key) {
	Node* q;
	if (!ptr) return nullptr;
	if (!ptr->lchild && !ptr->rchild) {
		if (ptr == root) { root = nullptr; }
		delete ptr;
		return nullptr;
	}
	if (ptr->val > key) ptr->lchild = rDelete(ptr->lchild, key);
	else if (ptr->val < key) ptr->rchild = rDelete(ptr->rchild, key);
	else {
		if (height(ptr->lchild) > height(ptr->rchild)) {
			q = inorderPredecessor(ptr->lchild);
			ptr->val = q->val;
			ptr->lchild = rDelete(ptr->lchild, q->val);
		}
		else {
			q = inorderSuccessor(ptr->rchild);
			ptr->val = q->val;
			ptr->rchild = rDelete(ptr->rchild, q->val);
		}
	}
	return ptr;
}

Node* BST::iSearch(int key) {
	Node* ptr = root;
	while (ptr) {
		if (ptr->val == key) return ptr;
		else if (ptr->val < key) ptr = ptr->lchild;
		else ptr = ptr->rchild;
	}
	return NULL;
}

Node* BST::rSearch(Node* ptr, int key) {
	if (ptr) {
		if (ptr->val == key) return ptr;
		else if (ptr->val < key) return rSearch(ptr->lchild, key);
		else return rSearch(ptr->rchild, key);
	}
	return NULL;
}

void BST::Inorder(Node* p) {
	if (p) {
		Inorder(p->lchild);
		cout << p->val << ", " << flush;
		Inorder(p->rchild);
	}
}

void BST::Preorder(Node* p) {
	if (p) {
		cout << p->val << ", " << flush;
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

Node* BST::rInsert(Node* ptr, int key) {
	Node* t;
	if (!ptr) {
		t = new Node;
		t->val = key;
		t->lchild = nullptr;
		t->rchild = nullptr;
		return t;
	}
	if (key < ptr->val)
		ptr->lchild = rInsert(ptr->lchild, key);
	else
		ptr->rchild = rInsert(ptr->rchild, key);
	return ptr;
}

void BST::iInsert(Node* ptr, int key) {
	Node* t = root;
	Node* r;
	Node* p;
	if (!root) {
		p = new Node;
		p->val = key;
		p->lchild = nullptr;
		p->rchild = nullptr;
		root = p;
		return;
	}
	while (t) {
		r = t;
		if (key < t->val) t = t->lchild;
		else if (key > t->val) t = t->rchild;
		else return;
	}
	// Now t points at NULL and r points at insert location
	p = new Node;
	p->val = key;
	p->lchild = nullptr;
	p->rchild = nullptr;

	if (key < r->val) r->lchild = p;
	if (key > r->val) r->rchild = p;
}

void BST::fromPreorder(int* pre, int n) {
	Node* ptr;
	stack<Node*> stk;
	int i = 0;
	root = new Node;
	root->val = pre[i++];
	root->lchild = nullptr;
	root->rchild = nullptr;

	ptr = root;

	while (i < n) {
		int ele = pre[i];
		if (ele < ptr->val) {
			Node* t = new Node;
			t->lchild = t->rchild = nullptr;
			t->val = ele;
			ptr->lchild = t;
			stk.push(ptr);
			ptr = t;
			i++;
		}
		else {
			if (pre[i] > ptr->val && pre[i] < stk.empty() ? 32767 : stk.top()->val) {
				Node* t = new Node;
				t->lchild = t->rchild = nullptr;
				t->val = ele;
				ptr->rchild = t;
				ptr = t;
				i++;
			}
			else {
				ptr = stk.top();
				stk.pop();
			};
		}
	}

}

int main(int argc, char const* argv[])
{
	BST bst;

	BST bt;
	bt.root = bt.rInsert(10);
	bt.root = bt.rInsert(70);
	bt.root = bt.rInsert(30);
	bt.root = bt.rInsert(20);
	bt.root = bt.rInsert(40);
	bt.root = bt.rInsert(50);
	bt.root = bt.rInsert(60);
	bt.Inorder();
	cout << "\nDeleted" << bt.rDelete(60)->val << endl;
	cout << "Deleted" << bt.rDelete(60)->val << endl;
	cout << "Deleted" << bt.rDelete(60)->val << endl;
	cout << "Deleted" << bt.rDelete(60)->val << endl;
	cout << "Deleted" << bt.rDelete(60)->val << endl;

	bt.Inorder();


	// cout << height(bt.root);

	// int A[] = { 30,20,10,15,25,40,50,45 };
	// BST bt;
	// int n = sizeof(A) / sizeof(A[0]);
	// bt.fromPreorder(A, n);


	printf("\n");
	// bt.Preorder();



	// cout << "Ended";
	return 0;
}

