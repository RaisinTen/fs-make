#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// called at the root of the AST with 0 indent
extern void pretty_print_element(struct Node* node, int indent);

// called by pretty_print_element to print out
// the subdirectories and files
// TODO: convert it from being recursive to iterative
extern void pretty_print(struct Node* node, int indent);

// prints the respective symbols
extern void pretty_print_tabs(int num_tabs);
extern void pretty_print_lbrace();
extern void pretty_print_rbrace();
extern void pretty_print_colon();
extern void pretty_print_comma();

#ifdef __cplusplus
}
#endif
