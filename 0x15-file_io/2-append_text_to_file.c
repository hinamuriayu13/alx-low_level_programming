#include "main.h"

/**
 * append_text_to_file - Function adds / "appends" text at the end of a file
 * @filename:The name of the file 
 * @text_content: Added content
 *
 * Return: 1 if the file is there. -1 if it fails or does not exist.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fdesc;
    int letters;
    int nw;

    if (!filename)
        return (-1);

    fdesc = open(filename, O_WRONLY | O_APPEND);

    if (fdesc == -1)
        return (-1);

    if (text_content)
    {
        for (letters = 0; text_content[letters]; letters++)
            ;

        nw = write(fdesc, text_content, letters);

        if (nw == -1)
            return (-1);
    }

    close(fdesc);

    return (1);
}
