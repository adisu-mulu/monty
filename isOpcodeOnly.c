#include "monty.h"
int isOpcodeOnly(const char *str) {
	while (*str) {
		if (*str == ' ') {
	             return 0;
	        }
		str++;
	 }
	return 1;
}
