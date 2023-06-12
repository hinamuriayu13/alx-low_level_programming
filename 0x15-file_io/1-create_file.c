#include "main.h"

/**

    create_file - function for file creation

    @filename: the name of the file ,

    @text_content: what's  written within the file.

    Return: 1 if it success. -1 n case of failure.
    */
    int create_file(const char *filename, char *text_content)
    {
    int fdesc;
    int nletters;
    int nw;

    if (!filename)
    return (-1);

    fdesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (fdesc == -1)
    return (-1);

    if (!text_content)
    text_content = "";

    for (nletters = 0; text_content[nletters]; nletters++)
    ;

    nw = write(fdesc, text_content, nletters);

    if (nw == -1)
    return (-1);

    close(fdesc);

    return (1);
    }
