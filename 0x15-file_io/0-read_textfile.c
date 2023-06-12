#include "main.h"
#include <stdlib.h>

/**
 * read_textfile_custom - Read text file and print its contents to STDOUT.
 * @filename: Name of the text file to read
 * @letters: Maximum number of letters to be read
 *
 * Return: Number of bytes read and printed, or 0 on failure or invalid input.
 */
ssize_t read_textfile_custom(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd, bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buf, letters);
	bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	free(buf);
	close(fd);

	return bytes_written;
}
