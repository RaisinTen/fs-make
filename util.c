#include <string.h>

#include "commons.h"
#include "util.h"

void strip_quotes(char* str)
{
    const int N = strlen(str) - 3;
    int i = 0;
    while(i <= N)
    {
        str[i] = str[i + 1];
        ++i;
    }
    str[i] = '\0';
}
