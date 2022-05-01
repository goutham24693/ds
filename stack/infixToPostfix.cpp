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
    return true;

}

int main()
{
    string str = "a * b + c * d - e";
    string out;
    string popObj;

    stack <string>s;

    char * op = NULL;
    string token;

    istringstream iss(str); 
    
    while (getline(iss, token, ' '))
    {
        if (isOperator(token))
        {
            s.top(&popObj);
            while (popObj.length())
            {
                if (isHigherPriorityThan(popObj, token))
                {
                    if (s.pop(&popObj) != FAILURE)
                    {
                        out += popObj;
                    }
                    if (s.top(&popObj) == FAILURE)
                    {
                        break;
                    }
                    continue;
                }
                break;
            }
            if (s.push(token) == FAILURE)
            {
                return -1;
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
