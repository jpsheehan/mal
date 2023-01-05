#include <stdlib.h>
#include <regex.h>
#include <string.h>

#include "reader.h"
#include "list.h"

Token reader_read(Reader* r)
{
    return *(Token*)List_Get(r->tokens, r->pos++);
}

Token reader_peek(Reader* r)
{
    return *(Token*)List_Get(r->tokens, r->pos);
}

char* strdup_from_regex_match(const char* src, regmatch_t * pMatch)
{
    int length = pMatch->rm_eo - pMatch->rm_so;
    if (length <= 0) return NULL;

    char* str = calloc(length + 1, sizeof(char));
    if (str == NULL) return NULL;

    memmove(str, (src + pMatch->rm_so), length);
    str[length] = '\0';

    return str;
}

List* tokenise(const char* program)
{
    int result;
    regex_t pattern;
    regmatch_t matches[1000] = {0};
    size_t nmatch = 1000;

    result = regcomp(&pattern, "[\\s,]*(~@|[\\[\\]{}()'`~^@]|\"(?:\\\\.|[^\\\\\"])*\"?|;.*|[^\\s\\[\\]{}('\"`,;)]*)", 0);

    if (!result) {
        return NULL;
    }

    result = regexec(&pattern, program, nmatch, matches, 0);
    if (result) {
        regfree(&pattern);
        return NULL;
    }

    List* tokens = List_New(strdup_from_regex_match(program, &matches[0]));
    regmatch_t *match = &matches[1];
    while (match->rm_eo) {
        List_Push(tokens, strdup_from_regex_match(program, match));
    }

    regfree(&pattern);

    return tokens;
}

List* read_form(Reader* reader)
{
    return NULL;
}

List* read_str(const char* program)
{
    List* tokens = tokenise(program);
    Reader reader = {
        .pos = 0,
        .tokens = tokens,
    };

    return read_form(&reader);
}

