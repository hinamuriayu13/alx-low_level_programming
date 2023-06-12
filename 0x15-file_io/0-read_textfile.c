#include "main.h"

/**
 * read_textfile - Function Reads a text file,
 * @filename: the name of the file ,
 * @letters: Number of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdesc;
	ssize_t nr, nw;
	char *buf;

	if (!filename)
		return (0);

	fdesc = open(filename, O_RDONLY);

	if (fdesc == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nr = read(fdesc, buf, letters);
	nw = write(STDOUT_FILENO, buf, nr);

	close(fdesc);

	free(buf);

	return (nw);
}
