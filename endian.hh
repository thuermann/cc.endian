//
// $Id: endian.hh,v 1.1 2013/08/19 23:31:06 urs Exp $
//

#ifndef ENDIAN_HH
#define ENDIAN_HH

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

#endif
