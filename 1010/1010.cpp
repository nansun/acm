//#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;

// 注意浮点数的精度。这道题一定要用double和FLT_EPSILON或DBL_EPSILON才能过

bool intersect(double X0, double Y0, double X1, double Y1, double X2, double Y2, double X3, double Y3)
{
    if (min(X0, X1)>max(X2, X3) || min(X2, X3)>max(X0, X1) || min(Y0, Y1)>max(Y2, Y3) || min(Y2, Y3)>max(Y0, Y1))
	return false;

    double Ax=X0-X2, Ay=Y0-Y2, Bx=X1-X2, By=Y1-Y2, Cx=X3-X2, Cy=Y3-Y2;
    double AxC=Ax*Cy-Ay*Cx, BxC=Bx*Cy-By*Cx;

    double ax=X2-X0, ay=Y2-Y0, bx=X3-X0, by=Y3-Y0, cx=X1-X0, cy=Y1-Y0;
    double axc=ax*cy-ay*cx, bxc=bx*cy-by*cx;

    return (AxC*BxC<=0 && axc*bxc<=0);
}

int main()
{
//    fstream cin("test.txt");

    int n;
    double s;
    bool possible;
    vector<double> X, Y;

    string strline;
    int case_number=0;
    while (getline(cin, strline))
    {
	istringstream streamline(strline);
	if (strline.find(' ')==string::npos)
	{
	    if (case_number>0)
	    {
		if (n<3 || n!=X.size()) possible=false;

		if (possible)
		    for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
			    if (i!=j && (i+1)%n!=j && (j+1)%n!=i
				&& intersect(X[i], Y[i], X[(i+1)%n], Y[(i+1)%n], X[j], Y[j], X[(j+1)%n], Y[(j+1)%n]))
				{ possible=false; break; }

		for (int i=0; i<n; i++)
		    s+=0.5*(Y[(i+1)%n]+Y[i])*(X[(i+1)%n]-X[i]);
		s=abs(s);

		// 由于浮点数的精度问题，s==0无法通过
		if (s<DBL_EPSILON) possible=false;

		if (case_number>1) cout<<endl;
		cout<<"Figure "<<case_number<<": ";

		cout.precision(2);
		if (possible) cout<<fixed<<s<<endl;
		else cout<<"Impossible"<<endl;
	    }


	    streamline>>n;
	    s=0; possible=true; X.clear(), Y.clear(); case_number++;
	}
	else
	{
	    double x, y;
	    streamline>>x>>y;
	    X.push_back(x), Y.push_back(y);
	}
    }

    return 0;
}
