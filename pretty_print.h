#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

void pretty_print(struct Node*, int);
void pretty_print_element(struct Node*, int);
void pretty_print_tabs(int);
void pretty_print_lbrace();
void pretty_print_rbrace();
void pretty_print_colon();
void pretty_print_comma();

#ifdef __cplusplus
}
#endif
