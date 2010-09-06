#include <cstdio>
using namespace std;

int main()
{
    double k=1, x=0, psix=0, tail=0;

    for (k=10001; k<=1400000; k++)
	tail+=1/(k*(k+1)*k);

    for (x=0; x<=2; x+=0.001)
    {
	psix=0;
	for (k=1; k<=10000; k++)
	{
	    psix+=1/(k*(k+1)*(k+x));
	}
	psix+=tail;
	psix*=1-x;
	psix+=1;

	printf("%5.3f %16.12f\n", x, psix);
    }

    return 0;
}
