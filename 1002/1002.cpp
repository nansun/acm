//#include <fstream>
#include <iostream>
using namespace std;

int put_castle(int n, char city[4][4])
{
    int x, y, min=n+n, k;

    for (int i=0; i<n; i++)
    {
	for (int j=0; j<n; j++)
	{
	    if (city[i][j]=='.')
	    {
		int tmp=0;
		for (k=i-1; k>=0 && city[k][j]!='X'; k--) tmp++;
		for (k=i+1; k<n && city[k][j]!='X'; k++) tmp++;
		for (k=j-1; k>=0 && city[i][k]!='X'; k--) tmp++;
		for (k=j+1; k<n && city[i][k]!='X'; k++) tmp++;
		if (tmp<min) x=i, y=j, min=tmp;
	    }
	}
    }
    
    if (min==n+n) return 0;

    city[x][y]='O';
    for (k=x-1; k>=0 && city[k][y]!='X'; k--)
	city[k][y]=='-' ? city[k][y]='+' : city[k][y]='|';
    for (k=x+1; k<n && city[k][y]!='X'; k++)
	city[k][y]=='-' ? city[k][y]='+' : city[k][y]='|';
    for (k=y-1; k>=0 && city[x][k]!='X'; k--)
	city[x][k]=='|' ? city[x][k]='+' : city[x][k]='-';
    for (k=y+1; k<n && city[x][k]!='X'; k++)
	city[x][k]=='|' ? city[x][k]='+' : city[x][k]='-';
    
    return 1+put_castle(n, city);
}

int main()
{
//    ifstream cin("test.txt");

    int n;
    char city[4][4];
    while (cin>>n && n!=0)
    {
	for (int i=0; i<n; i++)
	    for (int j=0; j<n; j++)
		cin>>city[i][j];

	cout<<put_castle(n, city)<<endl;

/*
	for (int i=0; i<n; i++)
	{
	    for (int j=0; j<n; j++)
	    {
		cout<<city[i][j];
	    }
	    cout<<endl;
	}
*/
    }

    return 0;
}
