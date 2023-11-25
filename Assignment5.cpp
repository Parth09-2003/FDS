
#include<iostream>
#include<math.h>
using namespace std;

const int max_value = 100;
	
	class polynomial
	{
		public:
		int total;
		int i,k;
		int coef[max_value];
		int expo[max_value];
		polynomial()
		{
			total=0;
		}
		void get();
		void display();
		void evaluate();		
		polynomial add_poly (polynomial a,polynomial b);
	};
	
	void polynomial::get()
	{
		cout<<"enter the polynomial values\n";
		cout<<"enter the total terms in polynomial\n";
		cin>>total;
		for(i=0;i<total;i++)
		{
			cout<<"enter the coeficient of poly\t"<<"coef["<<i+1<<"]"<<endl;
			cin>>coef[i];
			cout<<"enter the exponent of poly\t"<<"expo["<<i+1<<"]"<<endl;
			cin>>expo[i];
		}
	}
	void polynomial::display()
	{
		cout<<"your polynomial is:\n";
		for(i=0;i<total;i++)
		{
			cout<<coef[i]<<"x^"<<expo[i]<<"+";
		}
		cout<<"0";
		cout<<"\n";
	}
	void polynomial::evaluate()
	{	
		
		int result=0;
		double val=0;
		cout<<"enter the value of x \n";
		cin>>val;
		for(i=0;i<total;i++)
		{
			result=result+coef[i]*pow(val,expo[i]);
		}
		cout<<"evaluation is :<<result<<endl;
	}
	polynomial polynomial::add_poly (polynomial a,polynomial b)
	{	
	int j=0,k=0,i=0;
		polynomial c;
		while(i<=a.total&&j<=b.total)
		{	
			
			if(a.expo[i]==b.expo[j])
			{
				c.coef[k]=a.coef[i]+b.coef[j];
				c.expo[k]=a.expo[i];
				i++;
				k++;
				j++;
				
			}
			else if (a.expo[i]>b.expo[j])
			{
			c.coef[k]=a.coef[i];
			c.expo[k]=a.expo[i];
			i++;
			k++;
			}
			
			else 
			{
			c.coef[k]=b.coef[j];
			c.expo[k]=b.expo[j];
			k++;
			j++;
			}
			
		}
		while(i<a.total)
		{
			c.coef[k]=a.coef[i];
			c.expo[k]=a.expo[i];
			i++;
			k++;
		}
		while(j<b.total)
		{
			c.coef[k]=b.coef[j];
			c.expo[k]=b.expo[j];
			k++;
			j++;
		}
		c.total=k-1;
		for(k=0;k<c.total;k++)
		{
		cout<<c.coef[k]<<"x^"<<c.expo[k]<<"+";
		}
		cout<<"0";
		cout<<"\n";
		
	}
	
	int main()
	{	int m;
		char y;
		polynomial o;
		polynomial a,b,c;
		start:
		cout<<"case 1: read polynomial\n";
		cout<<"case 2: evaluate polynomial\n";
		cout<<"case 3: add two   polynomial\n";
		cout<<"enter your choice:\t"<<endl;
		cin>>m;
		switch(m)
		{		
		case 1:
		o.get();
		o.display();
		break;
		
		case 2:
		o.get();
		o.evaluate();
		break;
		
		case 3:
		a.get();
		b.get();
		c.add_poly(a,b);
		break;
		
		default:		
		cout<<"enter the valid choice:\n";
		break;
		
		}
		cout<<"you want to continue:[Y/N]\n";
		cin>>y;
		if(y=='y')
		{
			goto start;
		}
		else
		{
			cout<<"your program is terminated";
		}
		return 0;
		
	}


