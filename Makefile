ALL=re2 pcre
CC=$(CXX)
CXXFLAGS=-O5

RE2LIBS=-lpthread -lre2
PCRELIBS=-lpcrecpp

all: $(ALL)

re2: re2.o _Prof.o $(RE2LIBS)
pcre: pcre.o _Prof.o $(PCRELIBS)


clean:
	rm -f *.o $(ALL)
