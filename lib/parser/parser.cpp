#include "parser.h"
char parse_array[10];

void parser_parse(char *input){
        sscanf(input, "%s%s%s%S", parse_array[0], parse_array[1], parse_array[2], parse_array[3]);
}