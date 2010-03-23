#include <re2/re2.h>

#include "_Prof.h"

struct RE2Prof : public _Prof {
    bool RE(string& s, string& pat) {
        return RE2::FullMatch(s, pat);
    }
};

main()
{
    (new RE2Prof())->Prof();
}
