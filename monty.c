#include"monty.h"

/**
 * main - Entry point
 * Description: Main program function that receive
 *				the byte code file as argv[1] and
 *				parse it line by line then calls
 *				the needed function to execute the instruction
 * @argc: number of arguments
 * @argv: arguments passed to the main program
 * Return: return 0 for success or exit with (EXIT_FAILURE) when error occures
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *ptr = NULL;
	char line[256];
	int err_flag = 0, line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (empty_or_comment(line))
		{
			line_num++;
			continue;
		}

		processLine(line, &ptr, line_num, &err_flag);
		line_num++;
		if (err_flag)
		{
			free_stack(&ptr);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(&ptr);

	return (0);
}

/**
 * empty_or_comment - Check if a line is empty or a comment
 * @line: line to check
 * Return: 1 if line is empty or a comment, 0 otherwise
*/
int empty_or_comment(const char *line)
{
	size_t i;
	size_t len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		len--;
	}

	for (i = 0; i < len; i++)
	{
		if (!isspace(line[i]) && line[0] != '#')
			return (0);
	}
	return (1);
}
