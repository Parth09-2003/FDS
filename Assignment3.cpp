
#include<iostream>
#include<string.h>
using namespace std;
class str
{
    public:
    int n=0;
    int i;
    string newstr;  
    string newstr1;  
    string palidro;
    string sub;
    string sub1;
void frequency(string a, char l)    
{
    
    for(i=0;i<a.size();i++)
    {
        if(a[i]==l)
        {
            n=n+1;
        }
    }
    cout<<"frequency is"<<n;
}
void newstring(string a, int sta, int endi) 
{
    
    for(i=0;i<a.size();i++)
    {
        if(i>=sta)
        {
            newstr=newstr+a[i]; 
        }
        if(i==endi)
        {
            break;
        }
    }
     cout<<"new string is\n"<<newstr;
   
}
void remove(string a, char remo)
{
    
    for(i=0;i<a.size();i++)
    {
        if(a[i]!=remo)
        {
            newstr1=newstr1+a[i];
        }
    }
    cout<<"removed all occurence of::"<<remo<<"::and new string is\n"<<newstr1;
   
}

void extract(string a)
{
    
    cout<<"Enter substring you want to change";
    cin>>sub1;
    cout<<"Enter substring you want to add";
    cin>>sub;
    int i,h=0;
    int j;
    int start=0,ending=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]==sub1[0])
        {
            h=1;
            int k=i;
            for(j=1;j<sub1.size();j++)
            {
                k=k+1;
                h=h+1;
                if(a[k]!=sub1[j])
                {
                    h=0;
                    break;
                }
        
            }
            if(h==sub1.size())
            {
                start=i;
                ending=start+sub1.size()-1;
            }
            
        }
    }
    if (h==0)
        {
            h==0;
            cout<<"Substring not present"<<a;;
            
        }
    string cat="";
    for(i=0;i<a.size();i++)
    {
        if(i==start)
        {
            for(j=0;j<sub.size();j++)
            {
                cat=cat+sub[j];
            }
            i=i+sub1.size();
        }
        cat=cat+a[i];
    }
    cout<<"new string with replaced string is\n"<<cat;
}
void pallidrome(string a) 
{
    
    for(i=a.size()-1;i>-1;i--) 
    {
        palidro=palidro+a[i];
    }
    if(palidro==a) 
    {
        cout<<"This is a palindrome";
    }
    else
    {
        cout<<"This is not a palindrome";
    }
}
};
int main()
{
    string a;
    str obj;
    char yes;
    cout<<"Enter String you want to do operations  \n";
    cin>>a;
    star:
    int choice;
    cout<<"1.Frequency of occurrence of a particular character in the string\n";
    cout<<"2.Extract a new string from original string by accepting starting position and length\n";
    cout<<"3. removing all occurrences of a character accepted\n";
    cout<<"4. To make an in-place replacement of a substring w of a string by the string x.\n";
    cout<<"5. To check whether given string is palindrome or no\n";
    cin>>choice;
    switch (choice)
    {
        case 1:
            char ch;
            cout<<"Enter the character\n";
            cin>>ch;
            obj.frequency(a,ch);
            break;
        case 2:
            int s,e;
            cout<<"Enter Start position\n :";
            cin>>s;
            cout<<"Enter End position \n:";
            cin>>e;
            obj.newstring(a,s,e);
            break;
        case 3:
            char re;
            cout<<"Enter character :\n ";
            cin>>re;
            obj.remove(a,re);
            break;
        case 4:
            obj.extract(a);
            break;
        case 5:
           obj. pallidrome(a);
            break;
            
    }
    cout<<"\ndo you want to continue program\n[y/n]";
    cin>>yes;
    if(yes=='y')
    {
        goto star;
    }
    else if(yes=='n')
    {
cout<<"\nprogram terminated\n";
    }
	return 0;
}


