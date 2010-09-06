#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ifstream cin("test.txt");

    int n, m, k;
    while (cin>>n>>m>>k, !(m==0 && n==0 && k==0))
    {
	multimap<pair<int, char>, pair<int, int> > transition_table;
	for (int i=0; i<n; i++)
	    for (int j=0; j<k; j++)
	    {
		string strline;
		getline(cin, strline);
		istringstream streamline(strline);

		pair<int, int> tmp;
		while (streamline>>tmp.first>>tmp.second)
		    transition_table.insert(pair<pair<int, char>, pair<int, int> >(pair<int, char>(i, char('a'+j)), tmp));
	    }

	int L;
	while (cin>>L, L!=-1)
	{
	}
    }
}
