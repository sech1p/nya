/*
 * nya~ interpreter
 * 2021 sech1p, licensed under CC0 license
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nyanterpreter(char *code) {
	int i = 0;

	for(int j = 0; j < strlen(code); j++) {
		switch(code[j]) {
			case 'n':
				i--;
				break;
			case 'y':
				i++;
				break;
			case 'a':
				putchar(i);
				break;
			case '~':
				i = 0;
				break;
			default:
				continue;
		}
	}
	putchar('\n');
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <file.nya>\n", argv[0]);
		return 1;
	} else {
		FILE *file_ptr;
		char *buffer;
		long size;

		file_ptr = fopen(argv[1], "r");
		if(file_ptr == NULL) {
			fprintf(stderr, "Could not open %s file\n", argv[1]);
			return 1;
		}

		fseek(file_ptr, 0L, SEEK_END);
		size = ftell(file_ptr);
		rewind(file_ptr);

		buffer = calloc(1, size + 1);

		fread(buffer, size, 1, file_ptr);
		fclose(file_ptr);

		nyanterpreter(buffer);

		free(buffer);
	}
	return 0;
}
