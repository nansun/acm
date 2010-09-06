//#include <fstream>
//#include <fstream>
//#include <fstream>
//#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
//    ifstream cin("test.txt");

    int rotor_length, text_number, rotors[3][26], enigma=1;
    char ch, letters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (cin>>rotor_length, rotor_length!=0)
    {
	for (int i=0; i<3; i++)
	    for (int j=0; j<rotor_length; j++)
	    {
		cin>>ch;
		for (int k=0; k<rotor_length; k++)
		    if (letters[k]==ch)
		    {
			// 将rotor翻转，注意是[i][k]不是[i][j]
			// 最后得到的是从密文到明文转换的正的步进值
			rotors[i][k]=(j-k+rotor_length)%rotor_length;
			break;
		    }
	    }

	// 我恨你我恨你我恨你，Presentation Error
	// Insert a blank line between test cases.
	if (enigma>1) cout<<endl;

	cout<<"Enigma "<<enigma++<<":"<<endl;

	cin>>text_number;
	for (int s=0; s<text_number; s++)
	{
	    int start[3]={0};

	    string str;
	    cin>>str;
	    for (int i=0; i<str.size(); i++, start[0]++)
	    {
		if (start[0]==rotor_length) { start[0]=0; start[1]++; }
		if (start[1]==rotor_length) { start[1]=0; start[2]++; }
		if (start[2]==rotor_length) { start[2]=0; }

		int pos=str[i]-'A';
		for (int j=2; j>=0; j--)
		{
		    // 解密时方向是反的,所以要减去偏移值
		    pos=(pos+rotors[j][(pos-start[j]+rotor_length)%rotor_length])%rotor_length;
		}
		str[i]=pos+'a';
	    }
	    cout<<str<<endl;
	}
    }
    return 0;
}
