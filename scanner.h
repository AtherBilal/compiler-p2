// File scannher.h

#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

#define SPECIALCHARS 20
#define TOKENS 27
#define KEYWORDS 12


typedef struct characterLookup{
	int input;
	int column;
}characterMap;

typedef struct stateLookup{
	int state;
	token_ID tkEnum;
}stateMap;

token scanner(FILE *infile, int *line);
token lookup(int state, char *str);
int findColumn(int currentChar);


#endif 
