//
//
//
//

typedef enum { TOKEN_NUMBER, TOKEN_OPERATOR, TOKEN_LPAREN, TOKEN_RPAREN } TokenType;

typedef struct {
    TokenType type;
    int value;
    char op;
} Token;


int tokenize(const char *input, Token *tokens, int max_tokens);
