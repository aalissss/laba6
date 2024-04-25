#include <iostream>
using namespace std;

//узел дерева
struct Treenode {
	int key;
	Treenode* left = nullptr;
	Treenode* right = nullptr;
};

//структура дерева
struct Tree {
	Treenode* root = nullptr;
	int cnt = 0;

	//функция добавления элемента
	void add(int data) {
		if (root == nullptr) {
			root = new Treenode;
			root->key = data;
			root->left = nullptr;
			root->right = nullptr;
			cnt++;
		}
		else {
			Treenode* temp = root;
			while (true) {
				if (data < temp->key) {
					if (temp->left == nullptr) {
						temp->left = new Treenode;
						temp->left->key = data;
						temp->left->left = nullptr;
						temp->left->right = nullptr;
						cnt++;
						break;
					}
					else {
						temp = temp->left;
					}
				}
				else if (data >= temp->key) {
					if (temp->right == nullptr) {
						temp->right = new Treenode;
						temp->right->key = data;
						temp->right->left = nullptr;
						temp->right->right = nullptr;
						cnt++;
						break;
					}
					else {
						temp = temp->right;
					}
				}
				else {
					break;
				}
			}
		}
	}

	//удаление элемента
	void remove(int key) {
		if (root == nullptr) {
			return;
		}
		Treenode* parent = root;
		Treenode* temp = root;
		while (temp != nullptr) {
			if (key < temp->key) {
				parent = temp;
				temp = temp->left;
			}
			else if(key >= temp -> key){
				parent = temp;
				temp = temp->right;
			}
			else {
				if (temp->left != nullptr && temp->right != nullptr) {
					Treenode* minimum = temp->right;
					while (minimum->left != nullptr) {
						minimum = minimum->left;
					}
					temp->key = minimum->key;
					key = minimum->key;
				}

				Treenode* child = nullptr;
				if (temp->left != nullptr) {
					child = temp->left;
				}
				else {
					child = temp->right;
				}

				if (parent->left == temp) {
					parent->left = child;
				}
				else {
					parent->right = child;
				}
				delete temp;
				cnt--;
				break;
			}
		}
	}

	//удаление всех элементов
	void clear() {
		while (root != nullptr) {
			Treenode* temp = root;
			if (root->left != nullptr) {
				root = root->left;
			}
			else {
				root = root->right;
			}
			delete temp;
		}
		root = nullptr;
		cnt = 0;
	}

	//содержит ли дерево заданный элемент
	bool containst(int data) {
		Treenode* temp = root;
		while (temp != nullptr) {
			if (temp->key == data) {
				return true;
			}
			else if (temp->key > data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	}

	//количество элементов коллекции
	int count() {
		return cnt;
	}
};


int main()
{
	Tree tree;
	setlocale(LC_ALL, "ru");
	int key, check;
	cout << "Введите числа для заполнения дерева. Для окончания ввода введите число 0." << endl;
	while (true) {
		cin >> key;
		if (key == 0) {
			break;
		}
		tree.add(key);
	}
	cout << tree.count() << endl;
	cout << "Введите числа для нахождения их в дереве. Для окончания ввода введите число 0." << endl;
	while (true) {
		cin >> check;
		if (check == 0) {
			break;
		}
		if (tree.containst(check)) {
			cout << "Это число есть в дереве!" << endl;
		}
		else {
			cout << "Этого числа нет в дереве:(" << endl;
		}
	}
	tree.clear();
	cout << "В дереве нет элементов" << endl;
}