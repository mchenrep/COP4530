#ifndef BET_h
#define BET_h
#include <iostream>
#include <stack>

using namespace std;

class BET {
    public:
        BET(); // default constructor
        BET(const string postfix); /*one-parameter constructor, where parameter "postfix" is string containing a postfix expression. 
        The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by space.*/
        BET(const BET& rhs); // copy constructor
        ~BET(); // destructor
            
        bool buildFromPostfix(const string postfix);
        const BET & operator= (const BET & rhs);
        BET & operator=(BET && rhs);
        void printInfixExpression();
        void printPostfixExpression();
        size_t size();
        size_t leaf_nodes();
        bool empty();
            
        void makeEmpty();
	    void insert(const string &x);
	    void remove(const string &x);


    private:      
        struct BinaryNode {
	        string data;
	        BinaryNode *left;
	        BinaryNode *right;

	        BinaryNode(const string &d, BinaryNode *lt, BinaryNode *rt)
		    : data{d}, left{lt}, right{rt} {}
	        BinaryNode(string && d, BinaryNode *lt, BinaryNode *rt)
            : data{std::move(d)}, left{lt}, right{rt} {}
        };
                
        BinaryNode * root = nullptr;
	    void remove(const string &x, BinaryNode * & t);
        bool contains( const string & x, BinaryNode *t ) const;
        void printInfixExpression(BinaryNode *n);
        void makeEmpty(BinaryNode* &t);
        void printPostfixExpression(BinaryNode *n);
        size_t size(BinaryNode *t);
        size_t leaf_nodes(BinaryNode *t);
        BinaryNode * findMin( BinaryNode *t ) const;
        BinaryNode * clone(BinaryNode *t) const;
};

#include "BET.hpp"

#endif
