#include <iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

void add_value(int a, node **t)
{
  if ((*t) == NULL)
    {
      (*t) = new node;
      (*t) -> data = a;
      (*t) -> left = NULL;
      (*t) -> right = NULL;
      return;
    }
  if (a > ((*t) -> data))
    {
      add_value(a, &(*t) -> right); 
    }
  if (a < ((*t) -> data))
    {
  add_value(a, &(*t) -> left);
    }
}


void pre_order(node (*tree))
{
  if (tree != NULL)
  {
  cout << tree -> data << " ";
  pre_order(tree -> left);
  pre_order(tree -> right);
  }
}

void inf_order(node (*tree))
{
  if (tree != NULL)
  {
    inf_order(tree -> left);
    cout << tree -> data << " ";
    inf_order(tree -> right);
  }
}



void post_order(node (*tree))
{
  if (tree != NULL)
  {
    post_order(tree -> left);
    post_order(tree -> right);
    cout << tree -> data << " ";
  }
}


void find_value(node (*tree), int k)
{
  if (tree != NULL)
  {
    if((tree -> data) == k)
    {
      cout << "нашлось " << k << endl;
      k = 0;
    }
    else 
    {
      find_value(tree -> left, k);
      find_value(tree -> right, k);
    }
  }
}


int main()
{
  int k;
  struct node *tree;
  tree = NULL;
  add_value(1, &tree);
  add_value(2, &tree);
  add_value(13, &tree);
  add_value(41, &tree);
  add_value(54, &tree);
  add_value(63, &tree);
  add_value(11, &tree);
  pre_order(tree);
}
