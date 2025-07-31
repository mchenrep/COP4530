#ifndef BET_hpp
#define BET_hpp

#include "BET.h"
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

// HELPER FUNCTION DEFINITIONS

bool isOperator(const std::string& token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isOperand(const string token)
{
    for(auto i = 0; i < token.size(); i++)
    {
        if(!isalnum(token[i]))
        {
            return false;
        }
    }
    return true;
}

int precedence(string op)
{
    if(op == "+" || op == "-")
        return 0;
    if(op == "*" || op == "/")
        return 1;
    return -1;
}

// BET FUNCTION DEFINITIONS

BET::BET() : root(nullptr){}

BET::BET(const string postfix): root(nullptr) 
{ 
    buildFromPostfix(postfix); 
}

BET::BET(const BET& rhs)
{
    root = clone( rhs.root );
}

BET::~BET()
{
    makeEmpty(root);
}

bool BET::buildFromPostfix(const string postfix)
{
    makeEmpty(root);
    stack<BinaryNode*> s;
    stringstream ss(postfix);
    string token;
    while(ss >> token)
    {
        if(isOperand(token)){
            BinaryNode* node = new BinaryNode(token,nullptr,nullptr);
            s.push(node);
            cout<<node->data<<endl;
        }
        else if(isOperator(token))
        {
            if(s.size() < 2)
                return false;
            BinaryNode* rt = s.top();
            s.pop();
            BinaryNode* lt = s.top();
            s.pop();
            BinaryNode* node = new BinaryNode(token, lt, rt);
            s.push(node); // builds root(s)/leave(s) of the tree
            cout<<node->data<<" "<<node->left->data<<" "<<node->right->data<<endl;
        }
        
    }
    if(s.size() > 1) // if there are operators or operands still in the stack after, this means it's an invalid postfix expression    
        return false;
    root = s.top();
    return true;
}

const BET & BET::operator= (const BET & rhs)
{
    makeEmpty(root);
    root = clone(rhs.root);
    return *this;  
}

void BET::printInfixExpression()
{
    printInfixExpression(root);
}

void BET::printPostfixExpression()
{
    printPostfixExpression(root);
}

size_t BET::size()
{
    return size(root);
}

size_t BET::leaf_nodes()
{
    return leaf_nodes(root);
}

bool BET::empty() 
{
    return root == nullptr;
}

bool BET::contains( const string & x, BinaryNode *t ) const
{
    if( t == nullptr )
        return false;
    else if( x < t->data )
        return contains( x, t->left );
    else if( t->data < x )
        return contains( x, t->right );
    else
        return true;
}

void BET::makeEmpty()
{
    makeEmpty(root);
}

void BET::remove(const string &x)
{
    remove(x, root);
}

// BINARYNODE STRUCT DEFINITIONS

void BET::remove(const string &x, BinaryNode * & t)
{
    if( t == nullptr )
        return; // Item not found; do nothing
    if( x < t->data )
        remove( x, t->left );
    else if( t->data < x )
        remove( x, t->right );
    else if( t->left != nullptr && t->right != nullptr ) // Two children
    {
        t->data = findMin( t->right )->data;
        remove( t->data, t->right );
    }
    else
    {
        BinaryNode *oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
}

void BET::makeEmpty(BinaryNode* &t)
{
    if(t) 
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

BET::BinaryNode * BET::clone(BinaryNode *t) const
{
    if( t == nullptr )
        return nullptr;
    else
        return new BinaryNode{ t->data, clone( t->left ), clone( t->right ) };
}

void BET::printPostfixExpression(BinaryNode *n) 
{
    if(n != nullptr)
    {
        printPostfixExpression(n->left);
        printPostfixExpression(n->right);
        cout << n->data << " ";
    }
}

size_t BET::size(BinaryNode *t) 
{
    if(t != nullptr)
    {
        return 1+size(t->left) + size(t->right);
    }
    return 0;
}

size_t BET::leaf_nodes(BinaryNode *t) // FIX
{
    if (t==nullptr) 
        return 0;
    if (t->left==nullptr && t->right==nullptr) 
        return 1;
    return leaf_nodes(t->left) + leaf_nodes(t->right);
}

BET::BinaryNode * BET::findMin( BinaryNode *t ) const
{
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
}

void BET::printInfixExpression(BinaryNode *n) 
{
    if(n != nullptr)
    {
        bool p = false; // boolean for needing parenthesis
        if(isOperator(n->data) && n->left && isOperator(n->left->data))
        {
            if(precedence(n->data) > precedence(n->left->data))
                p = true;
        }
        if(p)
            cout<<"( ";
        printInfixExpression(n->left);
        if(p)
            cout<<") ";
        cout<<n->data<<" ";
        
        p = false;
        if(isOperator(n->data) && n->right && isOperator(n->right->data))
        {
            if(precedence(n->data) >= precedence(n->right->data))
                p = true;
        }
        if(p)
            cout<<"( ";
        printInfixExpression(n->right);
        if(p)
            cout<<") ";
            
    }
}


#endif


