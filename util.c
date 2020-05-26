#include <string.h>

#include "commons.h"
#include "util.h"

void strip_quotes(char* s)
{
    const int N = strlen(s) - 3;
    int i = 0;
    while(i <= N)
    {
        s[i] = s[i + 1];
        ++i;
    }
    s[i] = '\0';
}
