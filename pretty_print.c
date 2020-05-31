#include <stdio.h>
#include <assert.h>

#include "commons.h"
#include "pretty_print.h"
#include "node.h"
#include "util.h"

void pretty_print_element(struct Node* node, int indent)
{
    pretty_print_lbrace();

    if(node->children)
    {
        ++indent;
        pretty_print(node->children, indent);
        log_stdout("\n");
        --indent;
    }

    pretty_print_tabs(indent);
    pretty_print_rbrace();
}

void pretty_print(struct Node* node, int indent)
{
    pretty_print_tabs(indent);

    log_stdout("\"%s\"", node->name);

    pretty_print_colon();
    if(node->children)
    {
        pretty_print_element(node->children, indent);
    }
    else
    {
        // printf("null");
        log_stdout("null");
    }

    if(node->next)
    {
        pretty_print_comma();
        pretty_print(node->next, indent);
    }
}

void pretty_print_lbrace()
{
    log_stdout("{\n");
}

void pretty_print_rbrace()
{
    log_stdout("}");
}

void pretty_print_colon()
{
    log_stdout(": ");
}

void pretty_print_comma()
{
    log_stdout(",\n");
}

void pretty_print_tabs(int num_tabs)
{
    for(int i = 0; i < num_tabs; ++i)
    {
        log_stdout("    ");
    }
}
