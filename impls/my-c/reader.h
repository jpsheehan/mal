#ifndef __READER_H__
#define __READER_H__

#include "list.h"

typedef struct Atom {

} Atom;

typedef enum ASTNodeType {
    T_LIST,
    T_ATOM,
} ASTNodeType;

typedef struct ASTNode
{
    ASTNodeType type;
    union {
        List list;
        Atom atom;
    };
} ASTNode;

typedef struct Token {

} Token;

typedef struct Reader {
    List* tokens;
    int pos;
} Reader;

#endif