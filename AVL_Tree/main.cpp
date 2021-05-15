#include <iostream>
using namespace std;

struct node
{
  int data;
  unsigned char height;
  node *left;
  node *right;
};

unsigned char height(node *t)
{
	return t ? t -> height : 0;
} 

int bfactor(node *t)
{
  return height(t -> right) - height(t -> left);
}

void fixheight(node *t)
{
	unsigned char hl = height(t -> left);
	unsigned char hr = height(t -> right);
	t -> height = (hl > hr ? hl : hr) + 1;
}

node* rightrotate(node *t)
{
  node* p = t -> left;
  t -> left = p -> right;
  p -> right = t;
  fixheight(t);
  fixheight(p);
  return p;
}

node* leftrotate(node *t)
{
  node* p = t -> right;
  t -> right = p -> left;
  p -> left = t;
  fixheight(p);
  fixheight(t);
  return t;
}

node* balance(node *t)
{
  fixheight(t);
  if (bfactor(t) == 2)
  {
    if (bfactor(t -> right) < 0)
    {
      (t -> right) = rightrotate(t -> right);
    }
    return leftrotate(t);
  }
  if (bfactor(t) == -2)
  {
    if (bfactor(t -> left) > 0)
    {
      (t -> left) = leftrotate(t -> left);
    }
    return rightrotate(t);
  }

  return t;
}

node* add_value(int a, node *t)
{
  if (t == NULL)
    {
      t = new node;
      t -> data = a;
      t -> left = NULL;
      t -> right = NULL;
    }
  if (a > (t -> data))
    {
      add_value(a, t -> right); 
    }
  if (a < (t -> data))
    {
      add_value(a, t -> left);
    }
  return balance(t);    
}


void pre_order(node *t)
{
  if (t != NULL)
  {
  cout << t -> data << " ";
  pre_order(t -> left);
  pre_order(t -> right);
  }
}

void inf_order(node *t)
{
  if (t != NULL)
  {
    inf_order(t -> left);
    cout << t -> data << " ";
    inf_order(t -> right);
  }
}

void post_order(node *t)
{
  if (t != NULL)
  {
    post_order(t -> left);
    post_order(t -> right);
    cout << t -> data << " ";
  }
}

int main()
{
  int k;
  struct node *tree;
  tree = NULL;
  add_value(1, tree);
  add_value(2, tree);
  add_value(13, tree);
  add_value(41, tree);
  add_value(54, tree);
  add_value(63, tree);
  add_value(11, tree);
  pre_order(tree);
  post_order(tree);
  inf_order(tree);
}
