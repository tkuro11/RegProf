ALL=re2 pcre onig boost
CC=$(CXX)
CXXFLAGS=-O5

RE2LIBS=-lpthread -lre2
PCRELIBS=-lpcrecpp
ONIGLIBS=-lonig
BOOSTREGEXLIBS=-lboost_regex

all: $(ALL)

re2: re2.o _Prof.o $(RE2LIBS)
pcre: pcre.o _Prof.o $(PCRELIBS)
onig: onig.o _Prof.o $(ONIGLIBS)
boost: boost.o _Prof.o $(BOOSTREGEXLIBS)




clean:
	rm -f *.o $(ALL)
