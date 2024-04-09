#include <iostream>
using namespace std;

template <class T>
class TreeNode {

private:
	T value;
	TreeNode<T>* radacina;
	TreeNode<T>* parinte;
	TreeNode<T>* copii[10];

public:
	TreeNode(const T& val)
	{
		value = val;
		for (int i=0; i<10; i++)
		{
			this->copii[i] = nullptr;
		}
		radacina = this;
		parinte = nullptr;
	}

	void add_node(TreeNode<T>* node) 
	{
		if (node == nullptr)
			radacina = this;

		else 
		{
			int i = 0;
			for (int t=0; t<10; t++)
			{
				TreeNode<T>* n = node->copii[t];
				if (n != nullptr)
					i++;
				else break;
			}
			node->copii[i] = this;
			this->parinte = node;
			this->radacina = node->radacina;
		}
	}
	void delete_node(TreeNode<T>* node) 
	{
		if (node == nullptr) 
		{
			return; 
		}

		TreeNode<T>* parinte = node->parinte;

		if (parinte != nullptr) 
		{
			int index = -1;
			for (int i = 0; i < 10; i++) {
				if (parinte->copii[i] == node) {
					index = i;
					break;
				}
			}

			if (index != -1)
			{
				for (int i = index; i < 9; i++) 
				{
					parinte->copii[i] = parinte->copii[i + 1];
				}
				parinte->copii[9] = nullptr;
			}
		}
		
		for(int i=0; i<10; i++)
		{
			delete_node(node->copii[i]);
		}
		node = nullptr;
	}


	TreeNode<T>* find_node(TreeNode<T>* node, TreeNode<T>* kids[10])
	{
		for (int i = 0; i < 10; i++)
		{
			if (kids[i] != nullptr && node->value == kids[i]->value)
				return kids[i];
			else if (kids[i] != nullptr)
			{
				TreeNode<T>* result = find_node(node, kids[i]->copii);
				if (result != nullptr)
					return result;
			}
		}
		return nullptr;
	}

	TreeNode<T>* find(TreeNode<T>* node) 
	{
		int valoare = node->value;
		if (node->value == radacina->value)
			return radacina;
		else
			find_node(node, radacina->copii);
	}

	int count(TreeNode<T>* node) 
	{
		if (node == nullptr) 
		{
			return count(radacina);
		}
		int nr = 0; 
		for (int i = 0; i < 10; i++) 
		{
			if (node->copii[i] != nullptr) 
			{
				nr++;
				nr += count(node->copii[i]); 
			}
		}
		return nr;
	}

	void insert(TreeNode<T>* node, int index) 
	{
		if (index > 0 && index < copii.size())
		{
			this->copii[index] = node;
		}
	}

	bool operator<(const TreeNode<T>& other) const 
	{
		return value < other.value;
	}

	void sort(bool (*callback)(const TreeNode<T>&, const TreeNode<T>&) = nullptr) {
		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 9 - i; j++) 
			{
				if (copii[j] != nullptr && copii[j + 1] != nullptr) 
				{
					bool ok;
					if (callback != nullptr) ok = callback(*copii[j], *copii[j + 1]);

					else ok = (*copii[j] < *copii[j + 1]);

					if (ok) {
						TreeNode<T>* temp = copii[j];
						copii[j] = copii[j + 1];
						copii[j + 1] = temp;
					}
				}
			}
		}
	}


	TreeNode<T>* get_node(TreeNode<T>* parent = nullptr) {
		if (parent == nullptr) {
			return radacina;
		}

		for (int i = 0; i < 10; i++) {
			if (parent->copii[i] != nullptr) {
				if (parent->copii[i]->value == this->value) {
					return parent->copii[i]; 
				}
				else {
					TreeNode<T>* result = parent->copii[i]->get_node(parent->copii[i]);
					if (result != nullptr) {
						return result; 
					}
				}
			}
		}

		return nullptr; 
	}

};



int main()
{
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node2 = new TreeNode<int>(2);
	TreeNode<int>* node3 = new TreeNode<int>(3);
	TreeNode<int>* node4 = new TreeNode<int>(4);

	root->add_node(node2);
	root->add_node(node3);
	node3->add_node(node4);

	int num_children = root->count(nullptr);
	cout << "Number of children: " << num_children << endl;
	return 0;
}
