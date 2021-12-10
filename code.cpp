#include<iostream>
#include<string>
using namespace std;

struct node{
        char info;
        int ocurrence;
        node* left;
        node* right;
};


node* makeNode(char info){
        node* childnode;
        childnode = new node;
        childnode->ocurrence = 1;
        childnode->info = info;
        childnode->left = NULL;
        childnode->right = NULL;
        return childnode;
}

void BST(node * &Tree, char c)
{ node * T;
  T = makeNode( c);
  if (!Tree) Tree = T;
  else if (c < Tree->info)BST(Tree->left, c);
  else if (c > Tree->info)BST(Tree->right, c);
  else Tree->ocurrence +=1;
}

void inorder(node * Tree)
{
 if (!Tree) return;
 else
 {
        inorder(Tree->left);
        cout << Tree->info << "  " << Tree->ocurrence << "  ";
        inorder(Tree->right);
 }

}


int main()
{ node * Tree = NULL;
  char temp, ch, again = ' ';
  while (again != 'n'&& again != 'N')
        {  cout << "Please enter a char ";
           cin >> ch;   
           BST(Tree, ch);
           cout << "Would  you like to insert new char? (y/n)";
           cin >> again;
        }
  cout <<"The in order traversal of the Tree is ";
  inorder(Tree);
}


