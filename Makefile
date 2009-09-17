#
# $Id: Makefile,v 1.1 2009/09/17 19:11:25 urs Exp $
#

RM       = rm -f
CXXFLAGS = -O6

.PHONY: all
all: be.s

be.s: be.cc
	$(CXX) $(CXXFLAGS) -S -o $@ be.cc

.PHONY: clean
clean:
	$(RM) *.o be.s
