#
# $Id: Makefile,v 1.2 2013/08/19 23:31:06 urs Exp $
#

RM       = rm -f
CXXFLAGS = -O6

.PHONY: all
all: tst-endian.s

tst-endian.s: tst-endian.cc endian.hh
	$(CXX) $(CXXFLAGS) -S -o $@ tst-endian.cc

.PHONY: clean
clean:
	$(RM) *.o tst-endian.s
