//#include <fstream>
#include <iostream>
using namespace std;

int main()
{
//    ifstream cin("test.txt");
    int Ca, Cb, N;
    while (cin>>Ca>>Cb>>N)
    {
	int B=0;
	while (B!=N)
	{
	    cout<<"fill A"<<endl<<"pour A B"<<endl;
	    B+=Ca;

	    if (B>Cb)
	    {
		cout<<"empty B"<<endl<<"pour A B"<<endl;
		B-=Cb;
	    }
	}
	cout<<"success"<<endl;
    }

    return 0;
}
