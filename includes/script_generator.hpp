#pragma once

// called with the root to print generate the script
extern void generate_script(const struct Node* node);

// generate_script calls this on the underlying
// directories and files to generate scripts
// to make them
extern void generate_script_node(struct Node* node);

// generates codes for the respective commands
extern void cd(const char* str);
extern void mkdir_p(const char* str);
extern void touch(const char* str);
