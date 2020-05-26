#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

void generate_script(const struct Node*);
void generate_script_node(struct Node*);
void cd(const char*);
void mkdir_p(const char*);
void touch(const char*);

#ifdef __cplusplus
}
#endif
