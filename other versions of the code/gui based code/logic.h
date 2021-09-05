

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

class output {
public:
	vector <string> wanted, can, cant;
	void org() {
		sort(wanted.begin(), wanted.end());
		sort(can.begin(), can.end());
		set_difference(wanted.begin(), wanted.end(), can.begin(), can.end(),
			inserter(cant, cant.begin()));
	}
	void clear() {
		wanted.clear();
		can.clear();
		cant.clear();

	}


};
	class node {
	public:
		string value;
		string status;
		node* left;
		node* right;
		node* middle;
		node(string valuei, node* lefti = NULL, node* righti = NULL, node* middlei = NULL) {
			value = valuei;
			left = lefti;
			right = righti;
			middle = middlei;
			status = "unknown";
		}
	};

	class btree {
	public:
		btree() { root = NULL; }
		~btree() { destroy_tree(); }

		void insert(string key, string preq) {
			if (root != NULL) {

				insert(key, preq, root);

			}
			else {
				root = new node(preq);
				insert(key, preq, root);
			}
		}
		node* search(string key) { return search(key, root); }
		void destroy_tree() { destroy_tree(root); }
		void changestatus(string key) {
			node* tmp; tmp = search(key);
			if (tmp != NULL) { tmp->status = "taken"; }
			if (tmp != NULL) { if (tmp->left != NULL) { tmp->left->status = "allowed"; } }
			if (tmp != NULL) { if (tmp->right != NULL) { tmp->right->status = "allowed"; } }
		}
		
			void clearstatus() {
				clearstatus(root);
			}
	

	
		void checkcanbetaken(output& qwe) { checkcanbetaken(root, qwe); }
	private:
		void clearstatus(node* leaf) {
			if (leaf != NULL) {
				leaf->status = "unknown";
				clearstatus(leaf->left);
				clearstatus(leaf->right);
				clearstatus(leaf->middle);
			}
			/*if (leaf->right != NULL) {
				clearstatus(leaf->eight);
			}*/

		}
		void destroy_tree(node* leaf) {
			if (leaf != NULL) {
				destroy_tree(leaf->left);
				destroy_tree(leaf->right);
				destroy_tree(leaf->middle);
				delete leaf;
			}
		}
		void insert(string key, string preq, node* leaf) {
			node* tmp; tmp = search(preq); if (tmp != NULL) { if (tmp->left == NULL) { tmp->left = new node(key); } else { if (tmp->right == NULL && tmp->left->value != key && tmp->value == preq) { tmp->right = new node(key); } } }

			if (leaf->middle != NULL) {
				insert(key, preq, leaf->middle);
			}
			else {
				leaf->middle = new node(key);

			}
		}
		node* search(string key, node* leaf) {
			if (leaf != NULL) {
				if (key == leaf->value) {
					return leaf;
				}
				else { return search(key, leaf->middle); }
			}
			else {
				return NULL;
			}
		}
		void checkcanbetaken(node* leaf, output& qwe){
			if (leaf != NULL) {

				if (leaf->status == "allowed" && find(qwe.wanted.begin(), qwe.wanted.end(), leaf->value) != qwe.wanted.end()) {
					qwe.can.insert(qwe.can.end(), leaf->value);
				}

				checkcanbetaken(leaf->left, qwe);
				checkcanbetaken(leaf->right, qwe);
				checkcanbetaken(leaf->middle, qwe);
			}
		}

		node* root;
	};


	