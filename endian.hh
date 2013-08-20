//
// $Id: endian.hh,v 1.4 2013/08/20 09:02:42 urs Exp $
//

#ifndef ENDIAN_HH
#define ENDIAN_HH

#include <limits.h>
#include <byteswap.h>

static int endianness(void)
{
	static const union { int w; char c[4]; } w = { 0x01020304 };

	if (w.c[0] == 4 && w.c[1] == 3 && w.c[2] == 2 && w.c[3] == 1)
		return 0;
	else if (w.c[0] == 1 && w.c[1] == 2 && w.c[2] == 3 && w.c[3] == 4)
		return 1;
	else
		return -1;
}

template <typename T> T bswap(T n)
{
	switch (sizeof(T) * CHAR_BIT) {
	case 8:
		return n;
	case 16:
		return bswap_16(n);
	case 32:
		return bswap_32(n);
	case 64:
		return bswap_64(n);
	default:
		// shouldn't happen
		return n;
	}
}

template <typename T> T cpu_to_be(T n)
{
	return endianness() == 0 ? bswap(n) : n;
}

template <typename T> T be_to_cpu(T n)
{
	return endianness() == 0 ? bswap(n) : n;
}

template <typename T> class be {
	T val;
public:
	be(T n = 0) : val(cpu_to_be(n)) {}
	be &operator=(const be &b) {
		val = b.val;
		return *this;
	}
	be &operator=(const T &n) {
		val = cpu_to_be(n);
		return *this;
	}
	operator T() { return be_to_cpu(val); }
	be operator++() {
		val = cpu_to_be(be_to_cpu(val) + 1);
		return *this;
	}
	be operator++(int) {
		be ret = *this;
		++*this;
		return ret;
	}
};

#endif
