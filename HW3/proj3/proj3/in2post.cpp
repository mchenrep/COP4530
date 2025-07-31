#include "stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;
using namespace cop4530;

bool isOperand(const string& token)
{
    for(int i = 0; i < token.size(); i++)
    {
        if(!isalnum(token[i]))
        {
            return false;
        }
    }
    return true;
}

bool isInt(const string& token)
{
    for(int i = 0; i < token.size(); i++)
    {
        if(!isdigit(token[i]))
        {
            return false;
        }
    }
    return true;
}

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int precedence(string op)
{
    if(op == "+" || op == "-")
        return 0;
    if(op == "*" || op == "/")
        return 1;
    return -1;
}

string infix2postfix(const vector<string> &infix) {
    string r;
    Stack<string> s;
    for(int i = 0; i < infix.size(); i++)
    { 
        if(isOperand(infix[i]))
        {
            r+=infix[i];
            r+=" ";
        }
        else if(isOperator(infix[i]) || infix[i] == "(")
        {
            while(!s.empty() && s.top() != "(" && precedence(s.top()) >= precedence(infix[i]))
            {
                r+=s.top();
                r+=" ";
                s.pop();
            }
            s.push(infix[i]);
        }
        else if(infix[i] == ")")
        {
            while(!s.empty() && s.top() != "(")
            {
                r+=s.top();
                r+=" ";
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty())
    {
        r+=s.top();
        r+=" ";
        s.pop();
    }
    return r;
}

string evaluate(string postfix)
{
    Stack<string> s;
    stringstream ss(postfix);
    string token;
    while(ss>>token)
    {
            if(isOperand(token))
            {
                if(!isInt(token))
                    return postfix;
                s.push(token);
            }
            else
            {
                if(s.size() >= 2)
                {
                    int op,op2;
                    if(isInt(s.top()))
                    {
                        op = stoi(s.top());
                        s.pop();
                        if(isInt(s.top()))
                        {
                            op2 = stoi(s.top());
                            s.pop();
                        }
                        if(token == "+")
                            s.push(to_string(op+op2));
                        else if(token == "-")
                            s.push(to_string(op2-op));
                        else if(token == "*")
                            s.push(to_string(op*op2));
                        else if(token == "/")
                            s.push(to_string(op2/op));
                    }
                }
            }
    }
    return s.top();
}


int main()
{
    string inpt;
    cout<<"Enter infix expression (\"exit\" to quit): \n";
    getline(cin,inpt);
    while(inpt != "exit")
    {
        stringstream ss(inpt);
        vector<string> infix;
        string token;
        while(getline(ss,token,' '))
            infix.push_back(token); 
        string postfix = infix2postfix(infix);
        cout<<"Postfix expression: "<<postfix<<"\n";
        cout<<"Postfix evaluation: "<<evaluate(postfix)<<"\n";
        cout<<"Enter infix expression (\"exit\" to quit): \n";
        getline(cin,inpt);
    }
}