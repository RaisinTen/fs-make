#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// called at the root of the AST with 0 indent
void pretty_print_element(struct Node* node, int indent);

// called by pretty_print_element to print out
// the subdirectories and files
// TODO: convert it from being recursive to iterative
void pretty_print(struct Node* node, int indent);

// prints the respective symbols
void pretty_print_tabs(int num_tabs);
void pretty_print_lbrace();
void pretty_print_rbrace();
void pretty_print_colon();
void pretty_print_comma();

#ifdef __cplusplus
}
#endif
