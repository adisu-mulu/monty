#include "monty.h"
int isOpcodeOnly(const char *str) {
	while (*str) {
		if (*str == ' ') {
	             return 1; // String contains a space
	        }
		str++;
	 }
	return 0;
}
