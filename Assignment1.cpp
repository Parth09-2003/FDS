#include<iostream>
#include<string>
using namespace std;
class stud 
{
	public :
	string name;
	int rn;
	int c[4];
	string contest[4]={"Coding contest","Project Competiton","Paper Presentation","MasterMind"};
	void display()
	{	
		cout<<"Enter Name :";		
		cin>>name;
		cout<<"Enter Roll no. :";
		cin>>rn;
		cout<<"Press 1 if yes \nPress 0 if no :";  
		int temp=0;
		int i;
		for(i=0;i<4;i++)
		{
			temp=0;
			cout<<"Have you participated in "<<contest[i]<<" :";
			cin>>temp;
			c[i]=temp; 
		}
	}
};

int main()
{
	int n,i;
    int yes=1;
    int choice; 
	cout<<"Enter number of Students :";
	cin>>n;
	stud a[n];	
	for(i=0;i<n;i++)
	{
		a[i].display();
	}
	do 	{
	cout<<"1.Participants in coding and Project\n";
    cout<<"2.Participants in coding or project or both or mastermind\n";
    cout<<"3.Participants in coding but not in mastermind\n";
    cout<<"4.Participants in all events \n";
	cin>>choice;
	switch (choice)
	{
	case 1:
		for(i=0;i<n;i++)
		{
			if (a[i].c[0]==1 && a[i].c[1]==1)
			{
				cout<<a[i].name;
				cout<<"\n";
			}
		}
		break;
	case 2:
		for(i=0;i<n;i++)
		{
			if ((a[i].c[0]==1 || a[i].c[1]==1) || (a[i].c[0]==1 && a[i].c[1]==1) || (a[i].c[3]==1))
			{
				cout<<a[i].name;
				cout<<"\n";
			}
		}
		break;
	case 3:
		for(i=0;i<n;i++)
		{
			if (a[i].c[0]==1 && a[i].c[3]==0)
			{
				cout<<a[i].name;
				cout<<"\n";
			}
		}
		break;
	case 4:
		for(i=0;i<n;i++)
		{
			if (a[i].c[0]==1 && a[i].c[1]==1 && a[i].c[2]==1 && a[i].c[3]==1)
			{
				cout<<a[i].name;
				cout<<"\n";
			}
		}
		break;
	}
	cout<<"Do you want to continue : \1:Yes \0:No \n"; 
	cin>>yes;	
	}
	while(yes==1);
	
	return 0;
}

