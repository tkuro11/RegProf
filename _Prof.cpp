#include <sys/time.h>

#include "_Prof.h"

inline static long long gettime() 
{
    struct timeval tv;
    ::gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void _Prof::Prof() {
    long long t;
    
    this->RE(new string("b"), new string("b?b"));

    for (int n = 1; n< 29; n++) {
        string s(n, 'a');
        string pat;

        for (int i = 0; i< n; i++) pat += string("a?");
        pat += s;

        t = gettime();
        if (!this->RE(s, pat)) { cerr << "something wrong!!" << endl; break;}

        cout << gettime() - t<< endl;
    }
}
