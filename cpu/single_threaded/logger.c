#include <stdio.h>
#include <stdarg.h>
#include "logger.h"

void logger(const char *format, ...) 
{	
	char buf[1000];

	// Getting the string
	va_list argptr;
	va_start (argptr, format);
	vsnprintf(buf, 1000, format, argptr);
	va_end (argptr);

	// Printing the string regularly
	printf("%s", buf);

	// Appending the string to a file
	
	FILE *f;
	f = fopen("benchmark.log", "a+");
	if (f == NULL) {
		fclose(f);
		printf("Something went wrong with logger");
		return;
	}
	fprintf(f, "%s", buf);
	fclose(f);
}