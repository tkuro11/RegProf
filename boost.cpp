#include <boost/regex.hpp>

#include "_Prof.h"

struct BoostRegexProf : public _Prof {
    bool RE(string& s, string& pat) {
        boost::regex re(pat);
        return regex_match(s, re);
    }
};

main()
{
    (new BoostRegexProf())->Prof();
}
