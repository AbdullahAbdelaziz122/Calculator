// eval.h
#ifndef EVAL_H
#define EVAL_H

#include "tokenizer.h"

int shunting_yard(Token *infix, int infix_len, Token *postfix);

#endif
