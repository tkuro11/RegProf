#include <iostream>
#include <string>

using namespace std;

struct _Prof {
    void Prof();
    virtual bool RE(string&, string&) = 0;
    bool RE(string* s , string* pat) {this->RE(*s, *pat); }
};
