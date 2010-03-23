#include <pcrecpp.h>

#include "_Prof.h"

struct PCREProf : public _Prof {
    bool RE(string& s, string& pat) {
        pcrecpp::RE re(pat);
        return re.FullMatch(s);
    }
};

main()
{
    (new PCREProf())->Prof();
}
