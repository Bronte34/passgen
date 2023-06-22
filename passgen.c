#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define arr_size 4

void clear_arr(char *input_string)
{
	for (int i = 0; i < arr_size; i++)
		input_string[i] = '\0';
}

int main(void)
{
	int  i, pass_length;
	int selector; 

	char input_string[arr_size];
	char *endp;

	FILE *save_file;

	printf("Set the length of the password you want to generate (max = 99) : ");
	fgets(input_string, sizeof(input_string), stdin);
	pass_length = strtol(input_string, &endp, 10);

	char pass[pass_length + 1];

	srand((unsigned)time(NULL));
	for (i = 0; i < pass_length; i++) {
		selector = rand() % 3;
		switch (selector) {
			case 0:
				pass[i] = (rand() % ('z' - 'a' + 1)) + 'a'; //generate random lower case character between a to z
				break;
			case 1:
				pass[i] = (rand() % ('Z' - 'A' + 1)) + 'A'; //generate random upper case character between A to Z
				break;
			case 2:
				pass[i] = (rand() % ('9' - '0' + 1)) + '0'; //generate random number between 0 to 9
				break;
		}
	}
	pass[i + 1] = '\0';
	printf("pass = %s\n", pass);

	printf("Do you want to save it ? (y/n) : ");
	clear_arr(input_string);
	fgets(input_string, sizeof(input_string), stdin);

	if (input_string[0] == 'y') {
		save_file = fopen("password.txt", "a+");
		fprintf(save_file, "%s\n", pass);
		fclose(save_file);
	}
	puts("Program Finished");

	//test changes

	return 0;
}
