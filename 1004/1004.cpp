//#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;

void generate_sequences(string src,
			int pos,
		       	stack<char> stk,
		       	deque<string> seq,
			string tmp,
			string dst)
{
    if (pos==src.size() && stk.empty() && tmp==dst)
    {
	while (!seq.empty())
	{
	    cout<<seq.front();
	    seq.pop_front();
	}

	cout<<endl;

	return;
    }

    if (pos<src.size())
    {
	// push
	stk.push(src[pos++]);
	seq.push_back("i ");

	// continue
	generate_sequences(src, pos, stk, seq, tmp, dst);

	// roll back
	seq.pop_back();
	pos--;
	stk.pop();
    }

    if (!stk.empty() && dst.find(tmp+stk.top())==0)
    {
	// pop
	tmp+=stk.top();
	stk.pop();
	seq.push_back("o ");

	// continue
	generate_sequences(src, pos, stk, seq, tmp, dst);
	
	// roll back
	seq.pop_back();
	stk.push(tmp[tmp.size()-1]);
	tmp.erase(tmp.end()-1);
    }

    return;
}

int main()
{
//    ifstream cin("test.txt");
    string src, dst;
    while (cin>>src>>dst)
    {
       	string tmp;
	stack<char> stk;
	deque<string> seq;

	cout<<"["<<endl;
	generate_sequences(src, 0, stk, seq, tmp, dst);
	cout<<"]"<<endl;
    }

    return 0;
}
