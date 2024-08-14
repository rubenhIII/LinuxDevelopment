#include <stdio.h>
#include <errno.h>

extern int errno;

int main(int argc, char **argv)
{
	FILE *file;
	char *file_name = (char*)argv[1];

	if(argc<=1){
		puts("There is not file argument!");
		return 0;
	} else {
		file = fopen(file_name, "r");
		if(file){
			puts("The file was opened succesfully!");
			fclose(file);
		} else{
			printf("Open file %s with error!:\n", file_name);
			perror("");
		}
	}

	return 0;
}


