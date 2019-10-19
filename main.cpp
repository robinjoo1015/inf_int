#include "inf_int.h"
#include <iostream>

using namespace std;

int main()
{
/*
	inf_int a, e;
	inf_int b(100);
	inf_int c("321111111111122222222222233333333333444444444445555555555");
	inf_int d("123451987651234572749499923455022211");
	inf_int f = d;
	inf_int g(f);
	

	// cin >> g ;   // not required

	a = b * c;
	// e=g/f;       // not required
	e = c + d;
	b = d - c;
	f = c * d;
	if (true) {
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << "c : " << c << endl;
		cout << "d : " << d << endl;
		cout << "e : " << e << endl;
		cout << "f : " << f << endl;
		cout << "g : " << g << endl;
	}

	inf_int asdf("-103610361036");
	inf_int fdsa("14159265358979");
	cout << "asdf : " << asdf << endl;
	cout << "fdsa : " << fdsa << endl;
	//cout << asdf + fdsa << endl;
	//cout << asdf - fdsa << endl;
	//cout << fdsa - asdf << endl;
	cout << "asdf*fdsa : " << asdf * fdsa << endl;



	return 0;
	*/
	inf_int A, B, zero;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	cout << endl;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "B - A = " << B - A << endl;
	cout << "-A - B = " << - A - B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "-A * B = " <<  - A * B << endl;
	cout << "-A * -B = " << - A * - B << endl;
}
