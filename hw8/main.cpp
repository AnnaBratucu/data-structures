#include <iostream>
#include <string>
using namespace std;


class TreeNode {                            //Leaf Node
    TreeNode(TreeNode const&);            // no copy
    TreeNode& operator=(TreeNode const&); // no copy

public:
    TreeNode(char operation, int data, TreeNode* p)
      : left(0), right(0), parent(p),
        operation(operation), data(data)
    { //constructor
    }

    ~TreeNode() {
        delete left;
        delete right;
        left = right = 0;
    }

    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    char operation;
    int data;
};

class ExpressionTree {              //expression tree
    ExpressionTree(ExpressionTree const&);            // no copy
    ExpressionTree& operator=(ExpressionTree const&); // no copy
public:
    ExpressionTree() : root(0) {}

    void create();                  //creates binary expression tree
    TreeNode* root;                //instance of TreeNode
    int Evaluate(TreeNode * n);     //evaluates tree
    void InOrder(TreeNode * n);     //traverses tree InOrder
    void PreOrder(TreeNode *n);     //traverses tree PreOrder
    void PostOrder(TreeNode *n);    //traverses tree PostOrder

    ~ExpressionTree()
    {
        delete root;
        root = 0;
    }
};

void ExpressionTree::create() {     //creates binary expression tree
    root              = new TreeNode('*', 3, 0);
    root->left        = new TreeNode('+', 5, root);
    root->left->left  = new TreeNode('2', 2, root->left);
    root->left->right = new TreeNode('3', 3, root->left);
    root->right       = new TreeNode('5', 5, root);
}

int ExpressionTree::Evaluate(TreeNode *n) { //Evaluates tree

    switch(n->operation) { //switch statement to decide what operator is being used
        case '+': return (Evaluate(n->left) + Evaluate(n->right));
        case '-': return (Evaluate(n->left) - Evaluate(n->right));
        case '*': return (Evaluate(n->left) * Evaluate(n->right));
        case '/': return (Evaluate(n->left) / Evaluate(n->right));
    }
    return n->data;
}

void ExpressionTree::InOrder(TreeNode * n) { //traverses the tree InOrder
    if(n) {
        InOrder(n->left);
        cout << n->operation << " ";
        InOrder(n->right);
    }
}

void ExpressionTree::PreOrder(TreeNode * n) { //traverses the tree PreOrder
    if(n) {
        cout << n->operation << " ";
        PreOrder(n->left);
        PreOrder(n->right);
    }
}

void ExpressionTree::PostOrder(TreeNode * n) { //traverses the tree PostOrder
    if(n) {
        PostOrder(n->left);
        PostOrder(n->right);
        cout << n->operation << " ";
    }
}

int main() {                                //main program
    ExpressionTree* mytree = new ExpressionTree();
    mytree->create();
    cout<<"The Answer is: "<<endl;
    cout << mytree->Evaluate(mytree->root);
    cout<<endl;
    cout<<"In InOrder"<<endl;
    mytree->InOrder(mytree->root);
    cout<<endl;
    cout<<"In PreOrder"<<endl;
    mytree->PreOrder(mytree->root);
    cout<<endl;
    cout<<"In PostOrder"<<endl;
    mytree->PostOrder(mytree->root);
    cout<<endl;

    delete mytree;
}
