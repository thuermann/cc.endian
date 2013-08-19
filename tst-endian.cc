//
// $Id: tst-endian.cc,v 1.3 2013/08/19 23:31:26 urs Exp $
//

#include "endian.hh"

be<short> n, m, k = 0x1234;
be<int>   a, b, c = 0x42;
be<long>  x, y, z = 0x0815;

short     s1, s2;
int       i1, i2;
long      l1, l2;

int main()
{
	k = 42;
	c = 666;
	z = 4711;

	n  = s1;
	s2 = m;

	a  = i1;
	i2 = b;

	x  = l1;
	l2 = y;
}

int foo()
{
	int s = 0;
	for (be<int> i = 0; i < 10; i++)
		s += i;
	return s;
}
