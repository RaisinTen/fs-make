#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

extern void strip_quotes(char* str); // removes the surrounding pair of quotes from str - the string literal

extern void log_outfile(const char* format, ...);
extern void log_stdout(const char* format, ...);
extern void log_stderr(const char* format, ...);

#ifdef __cplusplus
}
#endif
