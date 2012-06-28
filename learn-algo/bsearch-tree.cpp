#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

struct node 
{
    node*   _parent;
    node*   _left;
    node*   _right;
    int     _val;
    node(int v = 0) : _parent(NULL), _left(NULL), _right(NULL), _val(v) {}
};

struct tree
{
    node*   _root;
    tree() : _root(NULL) {}
    void insert(int v);
    node* remove(int v);
    node* find(int v) const;
    node* successor(node* x) const;
    node* max(node* x) const;
    node* min(node* x) const;
};

node* tree::successor(node* x) const
{
    if (x->_right != NULL)
        return min(x->_right);
    
    node* y = x->_parent;
    while(y != NULL && x == x->_right) {
        x = y;
        y = y->_parent;
    }
    return y;
};

void tree::insert(int v)
{
    node* z = new node(v);

    node* y = NULL;
    node* x = _root;
    while(x != NULL) {
        y = x;
        if(z->_val < x->_val) 
            x = x->_left;
        else
            x = x->_right;
    }

    z->_parent = y;
    if(y == NULL)
        _root = z;
    else{ 
        if (z->_val < y->_val) 
            y->_left = z;
        else
            y->_right = z;
    }
}

node* tree::find(int v) const
{
    node* x = _root;
    while(x != NULL and v != x->_val) {
        if(v < x->_val) 
            x = x->_left;
        else
            x = x->_right;
    }
    return x;
}

node* tree::remove(int v)
{
    node* z = find(v);
    if(z == NULL)
        return z;

    node* y;
    node* x;

    // get y to REMOVE
    if(z->_left == NULL || z->_right == NULL)
        y = z;              // one or zero child
    else
        y = successor(z);   // two child, let y to be z's successor

    if(y->_left != NULL)    // x to be y's left or right child
        x = y->_left;
    else
        x = y->_right;

    if(x != NULL)                   // if y has child(x)
        x->_parent = y->_parent;    // let x's parent's to be y's parent

    if(y->_parent == NULL) {        // if y has not parent(MUST BE ROOT)
        _root = x;
    } else {                        // let x to replace y
        if(y == y->_parent->_left)  // let y's parent's child to be x
            y->_parent->_left = x;
        else
            y->_parent->_right = x;
    }

    if(y != z)                      // not REMOVE z, but just replace it's value
        z->_val = y->_val;          // REMOVE y

    return y;
}

node* tree::max(node* x) const
{
    node* z = x;
    while(z != NULL && z->_right != NULL) {
        z = z->_right;
    }
    return z;
}

node* tree::min(node* x) const
{
    node* z = x;
    while(z != NULL && z->_left != NULL) {
        z = z->_left;
    }
    return z;
}

void print_tree(const node* t)
{
    stack<const node*> s;
    const node* z = t;
    while(z != NULL || s.size() > 0) {
        if(z != NULL) {
            s.push(z);
            z = z->_left;
        } else {
            z = s.top();
            s.pop();
            printf("%d\n", z->_val);
            z = z->_right;
        }
    }
}

void print_tree_r(const node* t)
{
    if(t->_left != NULL) { print_tree(t->_left); }
    printf("%d\n", t->_val);
    if(t->_right != NULL) { print_tree(t->_right); }
}

void graph_dot(const node* t, const char* file)
{
    FILE* f = fopen(file, "w");
    fprintf(f, "digraph G{\n");
    printf("digraph G{\n");
    stack<const node*> s;
    s.push(t);
    const node* z;
    while(s.size() > 0) {
        z = s.top();
        s.pop();
        if(z != NULL) {
            if(z->_left != NULL){
                fprintf(f, "%d->%d [color=lightgrey];\n", z->_val, z->_left->_val);
                printf("%d->%d [color=lightgrey];\n", z->_val, z->_left->_val);
            } 
            if(z->_right != NULL) {
                fprintf(f, "%d->%d [color=lightblue];\n", z->_val, z->_right->_val);
                printf("%d->%d [color=lightblue];\n", z->_val, z->_right->_val);
            } 
            s.push(z->_right);
            s.push(z->_left);
        }
    }
    fprintf(f, "}\n");
    printf("}\n");
}

int main()
{
    tree t;
    int arr[] = {15,5,16,3,12,20,10,13,18,23,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; ++i)
        t.insert(arr[i]);

    graph_dot(t._root, "bst_1.dot");
    t.remove(5);
    graph_dot(t._root, "bst_rm5.dot");

    //print_tree(t._root);
    printf("max: %d\n", t.max(t._root)->_val);
    printf("min: %d\n", t.min(t._root)->_val);

    return 0;
}
