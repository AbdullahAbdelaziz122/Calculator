#ifndef TOKENIZER_H
#define TOKENIZER_H


typedef enum { TOKEN_NUMBER, TOKEN_OPERATOR, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_INVALID } TokenType;

typedef struct {
    TokenType type;
    int value;
    char op;
} Token;


int tokenize(const char *input, Token *tokens, int max_tokens);
void print_token(Token t);
void print_tokens(Token *tokens, int tokens_count);
#endif
