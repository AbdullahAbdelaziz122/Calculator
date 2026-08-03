# Calculator

A command-line calculator that parses and evaluates arithmetic expressions written in C. Implements the Shunting-Yard algorithm for infix to postfix conversion and evaluates expressions using a stack-based approach.

## Features

- Integer arithmetic (`+`, `-`, `*`, `/`)
- Operator precedence (`*` and `/` before `+` and `-`)
- Parentheses for grouping
- Unary minus support (e.g., `-5`, `3 * -4`)
- Error detection:
  - Division by zero
  - Mismatched parentheses
  - Invalid characters
  - Empty input
  - Input buffer overflow

## Build

```bash
make
```

This produces the executable `calc`.

## Usage

```bash
./calc
Enter expression: 3 + 5 * 2
Result: 13
```

## Project Structure

```
Calculator/
├── src/
│   ├── main.c          – Input handling, validation, orchestration
│   ├── tokenizer.c     – Tokenization (numbers, operators, parentheses)
│   ├── tokenizer.h     – Token definitions and prototypes
│   ├── eval.c          – Shunting-Yard conversion and evaluation
│   ├── eval.h          – Eval function prototypes
│   ├── stack.c         – Operator stack implementation
│   ├── stack.h         – Stack definitions
│   ├── value_stack.c   – Integer stack for evaluation
│   └── value_stack.h   – Value stack definitions
├── Makefile

README.md
.gitignore
```

## Implementation Details

- **Input Handling**: `fgets()` with buffer overflow detection
- **Tokenization**: Scans input, produces tokens with types (NUMBER, OPERATOR, LPAREN, RPAREN)
- **Infix to Postfix**: Shunting-Yard algorithm with operator precedence
- **Evaluation**: Stack-based postfix evaluation
- **Error Handling**: Propagates errors with descriptive messages

## Limitations

- Integer arithmetic only (no floating-point support)
- Maximum expression length: 100 characters
- No variable support
- No modulo or exponentiation operators
- Integer overflow undefined (e.g., `2147483647 + 1`)

## Future Work

- Floating-point arithmetic (`double`)
- Additional operators: `%` (modulo), `^` (exponentiation)
- Interactive REPL mode
- Variable assignment and retrieval
- Scientific functions (`sin`, `cos`, `sqrt`, etc.)
- Support for expressions from files

## Lessons Learned

- Tokenization requires careful handling of unary minus and multi-digit numbers
- Shunting-Yard algorithm requires precise precedence and associativity rules
- Separation of concerns (tokenizer, parser, evaluator) improves maintainability
- Robust error handling is critical for user-facing applications

## License

MIT

