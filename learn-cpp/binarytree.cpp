#include <iostream>
#include <queue>
#include <stack>
#include <unistd.h>

class node
{
    public:
        node(int d = 0, node* p = NULL, node* lf = NULL, node* rt = NULL) 
            : _data(d), _parent(p), _left(lf), _right(rt) {}
    public:
        int _data;
        node* _parent;
        node* _left;
        node* _right;
};

class tree
{
    public:
        tree() : _root(NULL) {}
        ~tree() {}

        void insert(node* n);
        node* remove(node* n);

        node* max() const { return _max(_root); }
        node* min() const { return _min(_root); }
        node* search(int key) const;

        void per_order() const { _per_order(_root); }
        void post_order() const { _post_order(_root); }
        void in_order() const { _in_order(_root); }

        void npre_order() const;
        void npost_order() const;
        void nin_order() const;

    private:
        void _per_order(node* n) const; 
        void _post_order(node* n) const;
        void _in_order(node* n) const;
        node* _min(node* n) const;
        node* _max(node* n) const;
        node* _succssor(node* n) const;

    private:
        node* _root;
};

node* tree::_max(node* p) const
{
    while(p and p->_right) {
        p = p->_right;
    }
    return p;
}

node* tree::_min(node* p) const
{
    while(p and p->_left) {
        p = p->_left;
    }
    return p;
}

node* tree::search(int key) const
{
    node* p = _root;
    while(p and p->_data != key) {
        p = (key < p->_data) ? p->_left : p->_right;
    }
    return p;
}

node* tree::_succssor(node* n) const
{
    if(n->_right) {
        return _min(n->_right);
    }

    node* p = n->_parent;
    node* c = n;
    while(p and c == p->_right) {
        c = p;
        p = p->_parent;
    }

    return p;
}

void tree::insert(node* n) 
{
    node* t = NULL;
    node* r = _root;
    while(r) {
        t = r;  // remember root
        if(n->_data < t->_data) {
            r = r->_left;
        } else {
            r = r->_right;
        }
    }

    n->_parent = t;

    if(!t) {        // empty tree
        _root = n;  // set root to node
    } else {
        if(n->_data < t->_data) {
            t->_left = n;
        } else {
            t->_right = n;
        }
    }
}

node* tree::remove(node* n)
{
    /* found the remove node, it will be node or node's succssor */
    node* rm;

    if(n->_left == NULL or n->_right == NULL) {
        rm = n;   // node has 0 or 1 child, just rm node directly
    } else {
        rm = _succssor(n);      // rm node's succssor
    }

    /* found the remove node's child */
    node* c = (rm->_left ? rm->_left : rm->_right); 

    /* set child's parent */
    if(c) {
        c->_parent = rm->_parent;
    }

    /* set parent's child */
    if(rm == _root) {
        _root = c;  // rm root
    } else {
        if(rm == rm->_parent->_left) {  // rm node is it's parent's left node
            rm->_parent->_left = c;
        } else {
            rm->_parent->_right = c;    // rm node is it's parent's right node
        }
    }

    if(rm != n) {
        n->_data = rm->_data;
    }

    return rm;
}

void tree::_per_order(node* n) const 
{
    if(n) {
        std::cout << n->_data << " ";
        _per_order(n->_left);
        _per_order(n->_right);
    }
}

void tree::_post_order(node* n) const 
{
    if(n) {
        _post_order(n->_left);
        _post_order(n->_right);
        std::cout << n->_data << " ";
    }
}

void tree::_in_order(node* n) const 
{
    if(n) {
        _in_order(n->_left);
        std::cout << n->_data << " ";
        _in_order(n->_right);
    }
}

void tree::npre_order() const
{
    std::stack<node*> s;
    s.push(_root);

    node* p;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        std::cout << p->_data << " ";

        if(p->_right) s.push(p->_right);
        if(p->_left) s.push(p->_left);
    }
}

void tree::npost_order() const
{
    std::stack<node*> s;
    s.push(_root);

    node* pre = NULL;
    node* cur;
    while(!s.empty()) {
        cur = s.top();

        // leaf or children have accessed, print
        if((cur->_left == NULL and cur->_right == NULL) or
            (pre and (pre == cur->_left or pre == cur->_right))) {
            std::cout << cur->_data << " ";
            s.pop();
            pre = cur;
        } else {
            if(cur->_right) s.push(cur->_right);
            if(cur->_left) s.push(cur->_left);
        }
    }
}

void tree::nin_order() const
{
    std::stack<node*> s;

    node* p = _root;
    while(p or !s.empty()) {
        while(p) {
            s.push(p);
            p = p->_left;
        }

        p = s.top();
        std::cout << p->_data << " ";
        s.pop();

        p = p->_right;
    }
}


int main()
{
    tree t;

    t.insert(new node(15));
    t.insert(new node(5));
    t.insert(new node(16));
    t.insert(new node(3));
    t.insert(new node(12));
    t.insert(new node(20));
    t.insert(new node(10));
    t.insert(new node(13));
    t.insert(new node(18));
    t.insert(new node(23));
    t.insert(new node(6));
    t.insert(new node(7));

    std::cout << t.max()->_data << "\n";
    std::cout << t.min()->_data << "\n";
    std::cout << t.search(6)->_data << "\n";

    std::cout << "      pre order: ";
    t.per_order();
    std::cout << "\n";

    std::cout << "     npre order: ";
    t.npre_order();
    std::cout << "\n";

    std::cout << "     post order: ";
    t.post_order();
    std::cout << "\n";

    std::cout << "    npost order: ";
    t.npost_order();
    std::cout << "\n";

    std::cout << "       in order: ";
    t.in_order();
    std::cout << "\n";

    std::cout << "      nin order: ";
    t.nin_order();
    std::cout << "\n";

    node* p = t.search(5);
    p = t.remove(p);
    std::cout << p->_data << "\n";

    return 0;
}
