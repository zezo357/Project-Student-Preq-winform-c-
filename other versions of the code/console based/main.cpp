
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <time.h>
#include<bits/stdc++.h>
//#include <sys/time.h>
using namespace std;
class output{
public:
    vector<string> wanted,can,cant;
    void print(){
sort(wanted.begin(),wanted.end());
sort(can.begin(),can.end());
	set_difference(wanted.begin(), wanted.end(), can.begin(), can.end(),
        inserter( cant,  cant.begin()));
	     cout<<"The following courses are OK to take:"<<endl<<endl;
    for (int i = 0; i <  can.size(); i++) {
		cout <<  can.at(i) << "\n";}
		cout<<endl<<endl;
		 cout<<"The following courses are CANNOT be taken:"<<endl<<endl;
    for (int i = 0; i <  cant.size(); i++) {
		cout <<  cant.at(i) << "\n";
	}} };

class node{
public:
	string value;
	string status;
	node *left;
	node *right;
node *middle;
        node(string valuei,node *lefti=NULL,node *righti=NULL,node *middlei=NULL){value=valuei;
        left=lefti;
        right=righti;
        middle=middlei;
        status="unknown";
        }
};

class btree{
public:
	btree();
	~btree();

	void insert(string key,string preq);
	node *search(string key);
	void destroy_tree();
	void inorder_print();

	void print();
	void changestatus(string key);
    void checkcanbetaken(output &qwe);

private:
	void destroy_tree(node *leaf);
	void insert(string key,string preq, node *leaf);
	node *search(string key, node *leaf);
	void inorder_print(node *leaf);

	void print(node *leaf);

void checkcanbetaken(node *leaf,output &qwe);
	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(string key,string preq, node *leaf){
node *tmp;tmp=search(preq);if(tmp !=NULL){if(tmp->left == NULL){tmp->left = new node(key);}else{if(tmp->right == NULL&&tmp->left->value !=key&&tmp->value ==preq){tmp->right = new node(key);}}}

if(leaf->middle != NULL){
			insert(key,preq ,leaf->middle);
		}else{
			leaf->middle = new node(key);

		}


	}

void btree::insert(string key,string preq){
	if(root != NULL){

		insert(key,preq, root);

	}else{
		root = new node(preq);
insert(key,preq, root);
	}
}

node *btree::search(string key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}

		else{return search(key, leaf->middle);}


}
	else{
		return NULL;}}


node *btree::search(string key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}




void btree::print(){
	print(root);
	cout << "\n";
}

void btree::print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		print(leaf->left);
		print(leaf->right);
		print(leaf->middle);
	}
}

void btree::checkcanbetaken(node *leaf,output &qwe){

	if(leaf != NULL){

            if(leaf->status=="allowed"&&find(qwe.wanted.begin(),qwe.wanted.end(),leaf->value)!=qwe.wanted.end()){
		qwe.can.insert(qwe.can.end(),leaf->value);}

		checkcanbetaken(leaf->left,qwe);
		checkcanbetaken(leaf->right,qwe);
		checkcanbetaken(leaf->middle,qwe);
		}
}

void btree::checkcanbetaken(output &qwe){
	checkcanbetaken(root,qwe);
}
void btree::changestatus(string key){
	node *tmp;tmp=search(key);
	if(tmp!=NULL){tmp->status="taken";}
	if(tmp!=NULL){if(tmp->left !=NULL){tmp->left->status="allowed";}}
	if(tmp!=NULL){if(tmp->right !=NULL){tmp->right->status="allowed";}}
}
int main(){


	btree *tree = new btree();
output qwe;
vector<string> input;
string course,preq;
int courses;



if(freopen("file.out","r",stdin)==NULL){cout<<"file.out is not found";}else{

cin>>courses;
cin.ignore();
   for(int i=1;i<=courses;i++){
    getline(cin,preq);
    getline(cin,course);

    tree->insert(course,preq);
}
   cout<<endl;
   //to print the tree
//tree->print();
if(freopen("test.txt","r",stdin)==NULL){cout<<"test.txt is not found";}else{
//if wanted to write the input
//freopen("CON","r",stdin);
cout<<endl;
cout<<"Enter the courses which you already studied:"<<" enter 99 to finish entering the courses"<<endl;
getline(cin,preq);

while(preq!="99"){

tree->changestatus(preq);

getline(cin,preq);}
cout<<endl;
cout<<"Enter the courses that you want to study:"<<" enter 99 to finish entering the courses"<<endl;
getline(cin,preq);

while(preq!="99"){

qwe.wanted.insert(qwe.wanted.end(),preq);

getline(cin,preq);}


tree->checkcanbetaken(qwe);
qwe.print();
tree->destroy_tree();
}}
}
