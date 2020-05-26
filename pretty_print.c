#include <stdio.h>
#include <assert.h>

#include "commons.h"
#include "pretty_print.h"
#include "node.h"

void pretty_print_element(struct Node* node, int indent)
{
    pretty_print_lbrace();

    if(node->children)
    {
        ++indent;
        pretty_print(node->children, indent);
        puts("");
        --indent;
    }

    pretty_print_tabs(indent);
    pretty_print_rbrace();
}

void pretty_print(struct Node* node, int indent)
{
    pretty_print_tabs(indent);

    printf("\"%s\"", node->name);

    pretty_print_colon();
    if(node->children)
    {
        pretty_print_element(node->children, indent);
    }
    else
    {
        printf("null");
    }

    if(node->next)
    {
        pretty_print_comma();
        pretty_print(node->next, indent);
    }
}

void pretty_print_lbrace()
{
    puts("{");
}

void pretty_print_rbrace()
{
    printf("}");
}

void pretty_print_colon()
{
    printf(": ");
}

void pretty_print_comma()
{
    puts(",");
}

void pretty_print_tabs(int num_tabs)
{
    for(int i = 0; i < num_tabs; ++i)
    {
        printf("    ");
    }
}
