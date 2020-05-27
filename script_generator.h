#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// called with the root to print generate the script
void generate_script(const struct Node* node);

// generate_script calls this on the underlying
// directories and files to generate scripts
// to make them
void generate_script_node(struct Node* node);

// generates codes for the respective commands
void cd(const char* str);
void mkdir_p(const char* str);
void touch(const char* str);

#ifdef __cplusplus
}
#endif
