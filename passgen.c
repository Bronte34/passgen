#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define arr_size 4

void clear_arr(char *input_string)
{
	for (int i = 0; i < arr_size; i++)
		input_string[i] = '\0';
}

void save_password(char *pass_address)
{
	FILE *save_file;

	save_file = fopen("password.txt", "a+");
	fprintf(save_file, "%s\n", pass_address);
	fclose(save_file);
}

void generate_password(char *password, int password_length) 
{
	int i, selector;

	srand((unsigned)time(NULL));
	for (i = 0; i < password_length; i++) {
		selector = rand() % 3;
		switch (selector) {
			case 0:
				password[i] = (rand() % ('z' - 'a' + 1)) + 'a'; //generate random lower case character between a to z
				break;
			case 1:
				password[i] = (rand() % ('Z' - 'A' + 1)) + 'A'; //generate random upper case character between A to Z
				break;
			case 2:
				password[i] = (rand() % ('9' - '0' + 1)) + '0'; //generate random number between 0 to 9
				break;
		}
	}
	password[i + 1] = '\0';
}

int main(void)
{
	int  password_length;

	char input_string[arr_size];
	char *endp;

	printf("Set the length of the password you want to generate (max = 99) : ");
	fgets(input_string, sizeof(input_string), stdin);
	password_length = strtol(input_string, &endp, 10);
	
	char password[password_length + 1];
	char *password_address = &password[0];

	generate_password(password_address, password_length);
	printf("password = %s\n", password);

	printf("Do you want to save it ? (y/n) : ");
	clear_arr(input_string);
	fgets(input_string, sizeof(input_string), stdin);

	if (input_string[0] == 'y') {
		save_password(password_address);
		puts("password saved");
	} else {
		puts("Program Finished");
	}

	return 0;
}
