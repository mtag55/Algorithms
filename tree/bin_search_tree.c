

typedef struct node
{
    int data;
    struct node* p;
    struct node* left;
    struct node* right;
} node;

node* iterative_tree_search(node* x, int val)
{
    while(x != NULL && x->data != val)
    {
        if(x->data > val)
            x = x->left;
        else
            x = x->right
    }
    return x;
}

node* recursive_tree_search(node* x, int val)
{
    if(x->data == val || x == NULL)
        return x;
    if(x->data > val)
        return recursive_tree_search(x->left, val);
    else
        return recursive_tree_search(x->right, val);
}

node* tree_minimum(node* x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}

node* tree_maximum(node* x)
{
    while(x->right != NULL)
        x = x->right;
    return x;
}

node* tree_minimum_recursive(node* x)
{
    if(x->left== NULL)
        return x;
    return tree_minimum_recursive(x->left);
}

node* tree_maximum_recursive(node* x)
{
    if(x->right == NULL)
        return x;
    return tree_maximum_recursive(x->right);
}

node* tree_successor(node* x)
{
    if(x->right!= NULL)
        return tree_minimum(x->right);
    node* y = x->p;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;

}

node* tree_predecessor(node* x)
{
    if(x->left != NULL)
        return tree_maximum(x->left);
    node* y = x->p;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->p;
    }
    return y;
}
