// File testScanner.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#include "scanner.h"
#include "testScanner.h"

void testScanner (FILE *input);

const int TOKENNAMESIZE = 36;
// List of token names (for printing)
char *tokenNames[TOKENNAMESIZE] = {
	"End of File",
	"Error",
	"Identifier",
	"Integer",
	"Equal Sign",
	"Less Than",
	"Greater Than",
	"Equal Equal",
	"Colon",
	"Plus Sign",
	"Minus Sign",
	"Asterisk",
	"Slash",
	"Number Sign",
	"Period",
	"And Sign",
	"Open Parenthesis", 
	"Close Parenthesis",
	"Comma",
	"Open Brace",
	"Close Brace",
	"Semicolon",
	"Open Bracket",
	"Close Bracket",
	"Begin Keyword",
	"End Keyword",
	"Repeat Keyword",
	"Void Keyword",
	"Var Keyword",
	"Return Keyword",
	"Scan Keyword",
	"Write Keyword",
	"Program Keyword",
	"If Keyword",
	"Then Keyword",
	"Let Keyword"
};

// function calls testScanner
void testScanner (FILE *input){
	token tempTk;
	int line = 1;
	do {
		tempTk = scanner(input, &line);
		if(strcmp(tokenNames[tempTk.id], "Error") == 0){
		printf("Scanner Error: %s Line: %i.\n", tempTk.tkString, tempTk.line);
			printf("Exiting\n");
			exit(EXIT_FAILURE);
		} else {
			printf("Line %i Type: %s Value: %s \n", tempTk.line, tokenNames[tempTk.id], tempTk.tkString);
		}
	} while(!feof(input));
}