// File main.c

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "testScanner.h"

int main(int argc, char* argv[]){
	// File pointer
	FILE *fp = NULL;
		
	 if(argc == 1){
		// input file pointer 
		fp = stdin;

	
		if (fp == NULL){
			fprintf(stderr, "Unable To Start stdin: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		// Ask for user input
		if (isatty(0)){
			printf("\nFile Not Found. \nEnter Input: ");
		}

		if(!feof(fp)){
			testScanner(fp);
		}

		fclose(fp);
	} else if (argc == 2) {
		// file input
		char *fileName = argv[1];
		fp = fopen(fileName, "r");

		//  input file failure 
		if (fp == NULL){
			fprintf(stderr, "Unable To Open '%s': %s\n", argv[1], strerror(errno));
			exit(EXIT_FAILURE);
		}

		if(!feof(fp)){
			testScanner(fp);
		}
		if (feof(fp)){
			printf("\nScanning completed.\n");
			fclose(fp);
		}
	}
 
 	// Throw error if more than 2 arguments are given
	else {
		printf("Error: Too many arguments\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}