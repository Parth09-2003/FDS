#include<iostream>
#include<string.h>
#include<stack>

using namespace std ; 

class StringX
{
    public : 
    string str;
    stack<char>sobj;
    StringX(string abc)
    {
        str = abc;
    }

    void ReverseStack()
    {
        stack <char> stack ;
        for (int iCnt = 0 ; iCnt < str.length() ; iCnt++)
        {
            stack.push(str[iCnt]);
        }
        for (;!stack.empty() ; )
        {
            cout<<stack.top();
            stack.pop();
        }
    }

    bool Reverse()
    {
        string filter  , rev  ;
        char temp = '\0';
        for (int i = 0 ; i< str.length() ; i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
            {
                sobj.push(tolower(str[i]));
                filter += tolower(str[i]);
            }
        }

        while (!sobj.empty())
        {
            rev += sobj.top();
            sobj.pop();
        }
        cout<<"Reverse String is : "<<rev<<endl;

    return rev==filter ;

    }
};

int main(int argc , char * argv[])
{
    StringX sobj ("Poor Dan is in a droop!!");
    cout<<sobj.Reverse()<<endl;
    sobj.ReverseStack();

    return 0;
}
