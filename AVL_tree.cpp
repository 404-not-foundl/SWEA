#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BinaryNode {
protected:
	int key; int value;
	BinaryNode* left; BinaryNode* right;
public:
	BinaryNode(int key = 0, int value = 0,
		BinaryNode* left = NULL, BinaryNode* right = NULL) {
		this->key = key; this->value = value;
		this->left = left; this->right = right;
	}
	bool isLeaf() {
		return this->left == NULL && this->right == NULL;
	}
	bool hasTwoChildren() {
		return this->left != NULL && this->right != NULL;
	}
	bool hasOneChild() {
		return (this->left != NULL && this->right == NULL) ||
			(this->left == NULL && this->right != NULL);
	}
	void setKey(int key) { this->key = key; }
	int getKey() { return this->key; }
	void setValue(int value) { this->value = value; }
	int getValue() { return this->value; }
	void setLeft(BinaryNode* left) { this->left = left; }
	BinaryNode* getLeft() { return this->left; }
	void setRight(BinaryNode* right) { this->right = right; }
	BinaryNode* getRight() { return this->right; }
};

class BinaryTree {
protected:
	BinaryNode* root;
public:
	BinaryTree() { this->root = NULL; }
	~BinaryTree() {
		removeNodes(this->root);
	}
	bool isEmpty() { return this->root == NULL; }
	void setRoot(BinaryNode* node) { this->root = node; }
	BinaryNode* getRoot() { return this->root; }
	void preorder() {
		cout << "preorder: ";
		preorder(this->root);
		cout << endl;
	}
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf("%c ", node->getKey()); // visit node
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}
	void inorder() {
		cout << "inorder: ";
		inorder(this->root);
		cout << endl;
	}
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			printf("%c ", node->getKey()); // visit root
			inorder(node->getRight());
		}
	}
	void postorder() {
		cout << "postorder: ";
		postorder(this->root);
		cout << endl;
	}
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			printf("%c ", node->getKey()); // visit root
		}
	}
	void removeNodes(BinaryNode* node) {
		if (node != NULL) {
			removeNodes(node->getLeft());
			removeNodes(node->getRight());
			delete node;
		}
	}
	void levelorder() {
		queue<BinaryNode*> Q;
		Q.push(this->root); // enqueue
		cout << "levelorder: ";
		while (!Q.empty()) {
			BinaryNode* cur_node = Q.front(); Q.pop(); // dequeue
			if (cur_node != NULL) {
				printf("%c ", cur_node->getKey()); // visit root
				Q.push(cur_node->getLeft()); // enqueue
				Q.push(cur_node->getRight()); // enqueue
			}
		}
		cout << endl;
	}
	BinaryNode* getSuccessor(BinaryNode* node) {
		while (node->getLeft() != NULL)
			node = node->getLeft();
		return node;
	}
};

class BinarySearchTree : public BinaryTree {
private:
	BinaryNode* search(BinaryNode* node, int key) {
		if (node == NULL || key == node->getKey())
			return node;
		else if (key < node->getKey())
			return search(node->getLeft(), key);
		else
			return search(node->getRight(), key);
	}
	void insert(BinaryNode* node, int key, int value) {
		if (key == node->getKey())
			node->setValue(value);
		else if (key < node->getKey()) {
			if (node->getLeft() == NULL)
				node->setLeft(new BinaryNode(key, value));
			else
				insert(node->getLeft(), key, value);
		}
		else {
			if (node->getRight() == NULL)
				node->setRight(new BinaryNode(key, value));
			else
				insert(node->getRight(), key, value);
		}
	}
	BinaryNode* remove(BinaryNode* node, BinaryNode* parent, int key) {
		if (node == NULL) return NULL;
		if (key < node->getKey())
			return remove(node->getLeft(), node, key);
		else if (key > node->getKey())
			return remove(node->getRight(), node, key);
		else { // key == node->getKey()
			if (node->hasTwoChildren()) {
				BinaryNode* succ = this->getSuccessor(node->getRight());
				node->setKey(succ->getKey());
				node->setValue(succ->getValue());
				// remove the successor
				succ = this->remove(node->getRight(), node, succ->getKey());
				return succ;
			}
			else if (node->hasOneChild()) {
				BinaryNode* child = (node->getLeft() != NULL) ?
					node->getLeft() : node->getRight();
				if (node == this->root) this->root = child;
				else {
					if (parent->getLeft() == node) parent->setLeft(child);
					else parent->setRight(child);
				}
				return node;
			}
			else if (node->isLeaf()) {
				if (node == this->root) this->root = NULL;
				else {
					if (parent->getLeft() == node) parent->setLeft(NULL);
					else parent->setRight(NULL);
				}
				return node;
			}
		}
	}
public:
	// if search succeeds, return true otherwise false
	bool search(int key) {
		BinaryNode* node = search(this->root, key);
		if (node != NULL)
			cout << "Search node with " << key
			<< " succeeds." << endl;
		else
			cout << "Search node with "
			<< key << " fails due to out-of-key." << endl;
		return node != NULL;
	}
	void insert(int key, int value) {
		if (isEmpty()) this->root = new BinaryNode(key, value);
		else insert(this->root, key, value);
	}
	// if remove succeeds, return true otherwise false
	bool remove(int key) {
		BinaryNode* node = remove(this->root, NULL, key);
		if (node == NULL) {
			//cout << "Remove node with " << key
			//	<< " fails due to out-of-key." << endl;
			return false;
		}
		else {
			//cout << "Remove node with " << key
			//	<< " succeeds." << endl;
			delete node;
			return true;
		}
	}
	
	bool balance;
	int check = 0;

	void isBalanced() {
		BinaryNode* node = this->root;

		balance = isBalanced_c(node);
		if (!balance)
			check++;

		if (node->hasTwoChildren()) {
			balance_t(node->getLeft(), node->getRight());
		}
		else if (node->hasOneChild()) {
			if (node->getLeft() == NULL)
				balance_o(node->getRight());
			else
				balance_o(node->getLeft());
		}

		if (check)
			cout << "Unbalanced" << endl;
		else
			cout << "Balanced" << endl;
	}
	int balance_t(BinaryNode* l_node, BinaryNode* r_node) {
		balance = isBalanced_c(l_node);
		if (!balance)
			check++;
		balance = isBalanced_c(r_node);
		if (!balance)
			check++;
		if (l_node->hasTwoChildren()) {
			balance_t(l_node->getLeft(), l_node->getRight());
		}
		else if (l_node->hasOneChild()) {
			if (l_node->getLeft() == NULL)
				balance_o(l_node->getRight());
			else
				balance_o(l_node->getLeft());
		}
		if (r_node->hasTwoChildren()) {
			balance_t(r_node->getLeft(), r_node->getRight());
		}
		else if (r_node->hasOneChild()) {
			if (r_node->getLeft() == NULL)
				balance_o(r_node->getRight());
			else
				balance_o(r_node->getLeft());
		}

		return 0;
	}
	int balance_o(BinaryNode* node) {
		balance = isBalanced_c(node);
		if (!balance)
			check++;
		if (node->hasTwoChildren()) {
			balance_t(node->getLeft(), node->getRight());
		}
		else if (node->hasOneChild()) {
			if (node->getLeft() == NULL)
				balance_o(node->getRight());
			else
				balance_o(node->getLeft());
		}

		return 0;
	}

	bool isBalanced_c(BinaryNode* node){
		if (node->hasTwoChildren()) {
			if (node->getLeft()->isLeaf()) {
				if (node->getRight()->hasTwoChildren()) {
					if (node->getRight()->getLeft()->isLeaf() && node->getRight()->getRight()->isLeaf())
						return true;
					else
						return false;
				}
				else if (node->getRight()->hasOneChild()) {
					if (node->getRight()->getLeft() == NULL) {
						if (node->getRight()->getRight()->isLeaf())
							return true;
						else
							return false;
					}
					else {
						if (node->getRight()->getLeft()->isLeaf())
							return true;
						else
							return false;
					}
				}
				else {
					return true;
				}
			}
			else if (node->getRight()->isLeaf()) {
				if (node->getLeft()->hasTwoChildren()) {
					if (node->getLeft()->getLeft()->isLeaf() && node->getLeft()->getRight()->isLeaf())
						return true;
					else
						return false;
				}
				else if (node->getLeft()->hasOneChild()) {
					if (node->getLeft()->getLeft() == NULL) {
						if (node->getLeft()->getRight()->isLeaf())
							return true;
						else
							return false;
					}
					else {
						if (node->getLeft()->getLeft()->isLeaf())
							return true;
						else
							return false;
					}
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
		else if (node->hasOneChild()) {
			return true;
		}
		else {
			return true;
		}
	}
};


int main() {
	int n, value;
	char c;
	BinarySearchTree tree;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c >> value;
		if (c == 'I') {
			tree.insert(value, value);
		}
		else if (c == 'D') {
			tree.remove(value);
		}
		else {
			cout << "ERROR" << endl;
			return 0;
		}
	}

	tree.isBalanced();
}

