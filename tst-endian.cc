//
// $Id: tst-endian.cc,v 1.4 2017/11/30 10:19:54 urs Exp $
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

void bar (void)
{
	n *= 2;
	m *= 3;
	k /= 4;

	a += b;
	c -= a;

	// The following is equivalent to b += 10.
	b += 4;
	b += 6;

	// The following two stmts are a NOP and could be
	// completely eliminated.
	x++;
	--x;

	// The following is equivalent to y += 2.
	y++;
	++y;

	// The following is equivalent to l1 = l2 = z.
	l1 = z++;
	l2 = --z;
}

int foo()
{
	int s = 0;
	for (be<int> i = 0; i < 10; i++)
		s += i;
	return s;
}
