//
// $Id: endian.hh,v 1.2 2013/08/19 23:31:16 urs Exp $
//

#ifndef ENDIAN_HH
#define ENDIAN_HH

#include <limits.h>
#include <byteswap.h>

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

// Assume the host is little-endian.
template <typename T> T cpu_to_be(T n)
{
	return bswap(n);
}

template <typename T> T be_to_cpu(T n)
{
	return bswap(n);
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
};

#endif
