/* HELLO! */

#include <iostream>
#include <ctype.h>
#include "table.h"
#include "err_hdl.h"

enum token_value {
    NAME, NUMBER, END,
    PLUS = '+',
    MINUS = '-',
    MUL = '*',
    DIV = '/',
    PRINT = ';',
    ASSIGN = '=',
    LP = '(',
    RP = ')',
} curr_token;

token_value get_token();
double prim();
double term();
double expr();

double number_value;
char name_string[256];

double prim()
{
    /* primary handler */
    switch (curr_token) {
    case NUMBER:
        get_token();
        return number_value;
    case NAME:
        if (get_token() == ASSIGN) {
            name *n = insert(name_string);
            get_token();
            n->value = expr();
            return n->value;
        }
        return look(name_string)->value;
    case MINUS:
        get_token();
        return -prim();
    case LP:
    {
        get_token();
        double e = expr();
        if (curr_token != RP)
            return error("Not found ')'");
        get_token();
        return e;
    }
    case END:
        return 1;
    default:
        return error("Need first");
    }
}

double term()
{
    /* Devides and multiplies */
    double left = prim();
    for (;;) {
        switch (curr_token) {
        case MUL:
            get_token();
            left *= prim();
            break;
        case DIV:
        {
            get_token();
            double d = prim();
            if (d == 0) 
                return error("divided on zero");
            left /= d;
        }
            break;
        default:
            return left;
        }
    }
}

double expr()
{
    /* Adds and substructs */
    double left = term();
    for (;;) {
        switch (curr_token) {
        case PLUS:
            get_token();
            left += term();
            break;
        case MINUS:
            get_token();
            left -= term();
            break;
        default:
            return left;
        }
    }
}

token_value get_token()
{
    char ch;
    do {
        if (!std::cin.get(ch))
            return curr_token = END;
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
    case ';':
    case '\n':
        std::cin >> std::ws;
        return curr_token = PRINT;
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        return curr_token = token_value(ch);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        std::cin.putback(ch);
        std::cin >> number_value;
        return curr_token = NUMBER;
        break;
    default:
        if (isalpha(ch)) {
            char *p = name_string;
            *p++ = ch;
            while(std::cin.get(ch) && isalnum(ch))
                *p++ = ch;
            std::cin.putback(ch);
            *p = 0;
            return curr_token = NAME;
        }
        error("Unknown token");
        return curr_token = PRINT;
    }
}

int main(void)
{
    insert("pi")->value = 3.1415926535897932385;
    insert("e")->value = 2.7182818284590452354;

    while (std::cin) {
        get_token();
        if (curr_token == END)
            break;
        else if (curr_token == PRINT)
            continue;
        
        std::cout << expr() << std::endl;
    }
    return no_of_errors;
}
