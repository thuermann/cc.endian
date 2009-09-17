//
// $Id: be.cc,v 1.1 2009/09/17 19:11:25 urs Exp $
//

#include <arpa/inet.h>

class be_int {
    int i;
public:
    be_int(int n = 0) : i(htonl(n)) {}
    be_int &operator=(const be_int &b) {
	i = b.i;
	return *this;
    }
    be_int &operator=(const int &b) {
	i = htonl(b);
	return *this;
    }
    operator int() { return ntohl(i); }
};

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
