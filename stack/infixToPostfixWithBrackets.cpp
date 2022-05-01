#include <iostream>
#include <cstring>
#include <sstream>

#include "stack2.h"

using namespace std;

bool isOperator (string str)
{
    bool ret = false;

    if ((str == "+") || (str == "-")
            || (str == "/") || (str == "*"))
    {
        ret = true;
    }

    return ret;
}

bool isHigherPriorityThan (string one, string two)
{
    if (one == "*" || one == "/")
    {
        return true;
    }
    else if ((one == "+" || one == "-") 
            && (two == "*" || two == "/"))
    {
        return false;
    }
    else if ((one == "(") || (two == "(")
        ||(one == "(" || two == "("))
    {
        return false;
    }
    return true;

}

int main()
{
    string str = "a + b * ( ( c - d ) * e )";
    string out;
    string popObj;

    stack <string>s;

    string token;

    istringstream iss(str); 

    cout <<"string: "<<str << endl;
    
    while (getline(iss, token, ' '))
    {
        cout << __func__ << __LINE__ << " : token = " << token << endl; 
        if (isOperator(token))
        {
            cout << "\t" << __func__ << __LINE__ << " :is a operator  " << endl; 
            s.top(&popObj);
            while (popObj.length())
            {
                if (isHigherPriorityThan(popObj, token))
                {
                    cout << "\t\t" << __func__ << __LINE__ << " :cannot add token "
                        << token << " in stack, since top of the stack is " << popObj << endl;
                    if (s.pop(&popObj) != FAILURE)
                    {
                        out += popObj;
                    }
                    cout << "\t\t" << __func__ << __LINE__ << "pop top of stack " << endl;
                    if (s.top(&popObj) == FAILURE)
                    {
                        break;
                    }
                    continue;
                }
                break;
            }
            cout << "\t\t " << "pushing token " << token << endl;
            if (s.push(token) == FAILURE)
            {
                cout << "push operation failed" << endl;
                return -1;
            }
        }
        else if (token == "(")
        {
            cout << "\t" << __func__ << __LINE__ << " :is a open parentheses. push it to stack" << endl; 
            if (s.push(token) == FAILURE)
            {
                cout << "push operation failed" << endl;
                return -1;
            }
        }
        else if (token == ")")
        {
            cout << "\t" << __func__ << __LINE__ << " :is a close parentheses " << endl; 
            s.top(&popObj);
            while (popObj != "(")
            {
                out += popObj;
                if (s.pop(&popObj) == FAILURE)
                {
                    cout << __func__ << __LINE__ <<" :push operation failed" << endl;
                    return -1;
                }
                s.top(&popObj);
            }
            if (popObj == "(")
            {
                if (s.pop(&popObj) == FAILURE)
                {
                    cout << __func__ << __LINE__ <<" :push operation failed" << endl;
                    return -1;
                }
            }
        }
        else
        {
            out += token;
        }
    }

    while (s.stackLen())
    {
        if (s.pop(&popObj) != FAILURE)
        {
            out += popObj;
        }
    }
    
    cout << out << endl;

    return 0;
}
