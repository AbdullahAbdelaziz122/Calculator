// eval.h
#ifndef EVAL_H
#define EVAL_H

#include "tokenizer.h"

int shunting_yard(Token *infix, int infix_len, Token *postfix, int max_postfix);
void print_postfix(Token *postfix, int count);
#endif
