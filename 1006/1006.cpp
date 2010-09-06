//#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
//    ifstream cin("test.txt");

    int k, n;
    char code_table[]="_abcdefghijklmnopqrstuvwxyz.";
    string ciphertext, plaintext;
    while(cin>>k && k!=0)
    {
	cin>>ciphertext;
	n=ciphertext.size();
	plaintext=ciphertext;
	
	for (int i=0, j; i<n; i++)
	{
	    for (j=0; code_table[j]!=ciphertext[i]; j++) {};
	    plaintext[(k*i)%n]=code_table[(j+i)%28];
	}

	cout<<plaintext<<endl;
    }


    return 0;
}
