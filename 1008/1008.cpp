#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// 无数次的TLE教会了我在DFS的时候，对相同的方块分类，number最重要。
struct square { int top; int right; int bottom; int left; int number; };

bool solve(int n, int tetravex[5][5], vector<square> squares)
{

    for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	    if (tetravex[i][j]==-1)
	    {
		for (int k=0; k<squares.size(); k++)
		    if ( ( squares[k].number!=0 )
			 && ( i>0 ? squares[k].top==squares[tetravex[i-1][j]].bottom : true)
			 && ( j>0 ? squares[k].left==squares[tetravex[i][j-1]].right : true)
		       )
		    {
			tetravex[i][j]=k;
			squares[k].number--;

//			cout<<i<<j<<k<<endl;
			
			if (solve(n, tetravex, squares))
			    return true;

			squares[k].number++;
		    }
		tetravex[i][j]=-1;
		return false;
	    }

    for (int i=0; i<n; i++)
	for (int j=0; j<n-1; j++)
	    if (squares[tetravex[i][j]].right!=squares[tetravex[i][j+1]].left)
	    {
//		cout<<squares[tetravex[i][j]].right<<squares[tetravex[i][j+1]].left<<endl;
		return false;
	    }

    for (int i=0; i<n-1; i++)
	for (int j=0; j<n; j++)
	    if (squares[tetravex[i][j]].bottom!=squares[tetravex[i+1][j]].top)
	    {
//		cout<<squares[tetravex[i][j]].bottom<<squares[tetravex[i+1][j]].top<<endl;
		return false;
	    }

    return true;
}

int main()
{
    int n, tetravex[5][5], game=1;
    vector<square> squares(5*5);
    
    ifstream cin("test.txt");
    while (cin>>n, n!=0)
    {
	squares.clear();

	for (int i=0; i<n*n; i++)
	{
	    square tmp;
	    cin>>tmp.top
	       >>tmp.right
	       >>tmp.bottom
	       >>tmp.left;

	    bool found=false;
	    for (int j=0; j<squares.size(); j++)
		if (squares[j].top==tmp.top && squares[j].right==tmp.right && squares[j].bottom==tmp.bottom && squares[j].left==tmp.left)
		{
		    squares[j].number++;
		    found=true;
		    break;
		}

	    if (!found)
	    {
		tmp.number=1;
		squares.push_back(tmp);
	    }
	}

//	for (int i=0; i<n*n; i++)
//	    cout<<squares[i].top
//		<<squares[i].right
//		<<squares[i].bottom
//		<<squares[i].left
//		<<squares[i].number;

	memset(tetravex, -1, sizeof(tetravex));

	if (game!=1) cout<<endl;
	cout<<"Game "<<game++<<": ";

	if (solve(n, tetravex, squares))
	    cout<<"Possible"<<endl;
	else
	    cout<<"Impossible"<<endl;

    }

    return 0;
}

