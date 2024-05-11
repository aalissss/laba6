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
				else if (data > temp->key) {
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
		Treenode* parent = nullptr;
		Treenode* temp = root;
		while (temp != nullptr) {
			if (key == temp->key) {
				break;
			}
			parent = temp;
			if (key < temp->key) {
				temp = temp->left;
			}
			else if(key > temp -> key){
				temp = temp->right;
			}
		}
		if (temp == nullptr) {
			return;
		}
		if ((temp->right != nullptr) && (temp->left != nullptr)) {
			parent = temp;
			Treenode* minimum = temp->right;
			while (minimum->left != nullptr) {
				parent = minimum;
				minimum = minimum->left;
			}
			temp->key = minimum->key;
			temp = minimum;
		}
		Treenode* child = nullptr;
		if (temp->left != nullptr) {
			child = temp->left;
		}
		else {
			child = temp->right;
		}
		if (temp != root) {
			if (parent->left == temp) {
				parent->left = child;
			}
			else if (parent->right == temp) {
				parent->right = child;
			}
		}
		else {
			root = child;
		}
		delete temp;
		cnt--;
	}

	//удаление всех элементов
	void clear() {
		if (cnt == 0) {
			return;
		}
		Treenode* parent = root;
		Treenode* temp = root;
		while (cnt > 0) {
			while (temp->left != nullptr || temp->right != nullptr) {
				parent = temp;
				if (temp->left != nullptr) {
					temp = temp->left;
				}
				else if (temp->right != nullptr) {
					temp = temp->right;
				}
			}
			if (parent->left == temp) {
				parent->left = nullptr;
			}
			else if (parent->right == temp){
				parent->right = nullptr;
			}
			delete temp;
			cnt--;
			temp = root;
		}
		root = nullptr;
	}

	//содержит ли дерево заданный элемент
	bool contains(int data) {
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
	cout << "Введите числа для нахождения их в дереве. Для окончания ввода введите число 0." << endl;
	while (true) {
		cin >> check;
		if (check == 0) {
			break;
		}
		if (tree.contains(check)) {
			cout << "Это число есть в дереве!" << endl;
		}
		else {
			cout << "Этого числа нет в дереве:(" << endl;
		}
	}
	tree.clear();
	cout << "В дереве нет элементов" << endl;
}