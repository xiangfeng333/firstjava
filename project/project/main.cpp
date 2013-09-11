#include<iostream>
#include<fstream>
using namespace std;
int max(int**B,int i,int j,int n)
{
	int a=0, b=0, c=0;
	if(((j-1)>=0)&&(B[i-1][j-1]!=-1))
		a=B[i-1][j-1];
	if(B[i-1][j]!=-1)
		b=B[i-1][j];
	if(((j+1)<n)&&(B[i-1][j+1]!=-1))
		c=B[i-1][j+1];
	if(a<=c&&b<=c)
		return c;
	if(a<=b&&c<=b)
		return b;
	if(b<=a&&c<=a)
		return a;

}
int max1(int**B,int i,int j,int n)
{
	int a=0, b=0, c=0;
	if(((j-1)>=0)&&(B[i-1][j-1]!=-1))
		a=B[i-1][j-1];
	if(B[i-1][j]!=-1)
		b=B[i-1][j];
	if(((j+1)<n)&&(B[i-1][j+1]!=-1))
		c=B[i-1][j+1];
	if(b<=a&&c<=a)
		return j-1;
	if(a<=b&&c<=b)
		return j;
	if(a<=c&&b<=c)
		return j+1;
}
void lop(int**A,int**B,int m,int n)
{
	cout<<"please input start place:";
	int i,j;
	int t1,t2,o;
	cin>>o;
	j=o-1;
	t1=t2=j;
	B[0][j]=A[0][j];
	for(i=1;i<m;i++)
	{
		if(t1-1>=0)
			t1--;
		if(t2+1<n)
			t2++;
		for(j=t1;j<=t2;j++)
			B[i][j]=max((int**)B,i,j,n)+A[i][j];
	}
	int k=-1,p;
	for(t1;t1<=t2;t1++)
		if(B[m-1][t1]>k)
		{
			k=B[m-1][t1];
			p=t1;
		}
    int *op=new int[m];
    ofstream out;
	out.open("output.txt",ios::trunc); 
	out<<k<<"\t"<<"（最大价值）"<<"\n";
	out<<o<<"\t"<<"（开始位置，用户输入）"<<"\n";
	op[m-1]=p;
	for(int h=m-2;h>0;h--)
	{
		op[h]=max1((int**)B,h+1,op[h+1],n);
	}
	for(int h=1;h<m;h++)
		out<<op[h]+1<<"\t"<<"(在第"<<h+1<<"排的位置）\n";
	out.close();
	delete[]op;
}


int main()
{
	char a[1000];
	int m=0,n=0,temp;
	ifstream in("test.txt");
	if(!in.good())
	{
		cout<<"no file";
		return 0;
	}
		int i=0;
		in.getline(a,100,'\n');
		while(a[i]!=' ')
		{
			temp=(int)a[i]-48;
			m=m*10+temp;
			i++;
		}
		i++;
		int count=0;
		while(a[i]!='\0')
		{
			temp=(int)a[i]-48;
			n=n*10+temp;
			i++;
			count++;
		}
	int** arr=new int*[m];
	for(int i=0;i<m;++i)
		arr[i]=new int[n];
	int** sumarr=new int*[m];
	for(int i=0;i<m;++i)
		sumarr[i]=new int[n];
	for(int h=0;h<m;++h)
		for(int f=0;f<n;++f)
			{
				arr[h][f]=0;
				sumarr[h][f]=-1;
		}
	for(int j=0;j<m;j++)
	{
		int i=0;
		in.getline(a,100,'\n');
		while(a[i]!='\0')
		{
			for(int k=0;k<n;k++)
			{
				count=0;
				while((a[i]!=',')&&(a[i]!='\0'))
				{
					temp=(int)a[i]-48;
					arr[j][k]=arr[j][k]*10+temp;
					i++;
					count++;
				}
				i++;
				}
			i--;
		}
	}
	in.close();

	lop((int**)arr,(int**)sumarr,m,n);

	for(int h=0;h<m;h++)
		{
			delete[]arr[h];
			delete[]sumarr[h];
	}
	delete[]arr;
	delete[]sumarr;
	return 0;
}