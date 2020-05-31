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

#include <stdarg.h>

/*
 * infile logger
 */
extern FILE* infile;
void log_infile(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(infile, format, args);
    va_end(args);
}

/*
 * outfile logger
 */
extern FILE* outfile;
void log_outfile(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(outfile, format, args);
    va_end(args);
}

/*
 * stdout logger
 */
void log_stdout(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

/*
 * stderr logger
 */
void log_stderr(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}
