#include <oniguruma.h>
#include <cstring>

#include "_Prof.h"

typedef unsigned char uchar;

class OnigurumaProf : public _Prof {
    regex_t* re;
    OnigSyntaxType* syntax ; 

    bool RE(string& s, string& pat) {
        unsigned char* c_s   = (uchar*)s.c_str();
        unsigned char* c_pat = (uchar*)pat.c_str();
        int lpat = pat.length(),
            lstr = s.length();
        int ret;

        onig_new(&re, c_pat, c_pat + lpat,
                ONIG_OPTION_DEFAULT, ONIG_ENCODING_ASCII, syntax, NULL);
        ret = onig_search(re, c_pat, c_pat + lpat, 
                c_pat, c_pat + lpat, onig_region_new(), ONIG_OPTION_NONE);
        return ret >=0;
    }

    public:
    OnigurumaProf(OnigSyntaxType* syntax) : syntax(syntax) {}
    ~OnigurumaProf() {
        onig_free(re);
    }
};

main(int argc, char** argv)
{
    OnigSyntaxType* syntax;
#define OPTION(SYNTAX) \
    else if (!strcmp(argv[1], #SYNTAX)) { \
        syntax = SYNTAX; }

    if (argc < 2) syntax = ONIG_SYNTAX_DEFAULT;
    OPTION(ONIG_SYNTAX_ASIS) 		    //   plain text
    OPTION(ONIG_SYNTAX_POSIX_BASIC)     //   POSIX Basic RE
    OPTION(ONIG_SYNTAX_POSIX_EXTENDED)  //   POSIX Extended RE
    OPTION(ONIG_SYNTAX_EMACS)           //   Emacs
    OPTION(ONIG_SYNTAX_GREP)            //   grep
    OPTION(ONIG_SYNTAX_GNU_REGEX)       //   GNU regex
    OPTION(ONIG_SYNTAX_JAVA)            //   Java (Sun java.util.regex)
    OPTION(ONIG_SYNTAX_PERL)            //   Perl
    OPTION(ONIG_SYNTAX_PERL_NG)         //   Perl + named group
    OPTION(ONIG_SYNTAX_RUBY)            //   Ruby
    else syntax = ONIG_SYNTAX_DEFAULT;  //   default (== Ruby)

    (new OnigurumaProf(syntax))->Prof();
}
