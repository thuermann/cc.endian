//
// $Id: tst-endian.cc,v 1.1 2013/08/19 23:31:06 urs Exp $
//

#include "endian.hh"

be_int be1, be2;
be_int x = 42;

int foo(void)
{
	x   = be2;
	be1 = 666;

	return be2;
}

int bar(int n)
{
	be1 = n;
	return be2;
}
