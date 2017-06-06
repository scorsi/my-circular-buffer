/*
** read_delim.c for mycircularbuffer in /home/sylvain/Travail/Perso/mycircularbuffer/read_delim.c
**
** Made by Sylvain CORSINI
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sat Jun 03 19:51:51 2017 Sylvain CORSINI
** Last update Sat Jun 03 19:51:51 2017 Sylvain CORSINI
*/

#include		<stdlib.h>
#include		<memory.h>
#include		"mycb.h"

static int		__mycb_loop_check_delim(char *buffer,
						  size_t buffer_size,
						  char *delim)
{
  size_t		i;

  i = 0;
  while (i < buffer_size && buffer[i] != '\0')
  {
    if (strcmp(&buffer[i], delim) == 0)
    {
      buffer[i] = '\0';
      return (0);
    }
    ++i;
  }
  return (1);
}

char			*mycb_read_delim(int fd, size_t buffer_size,
					     char *delim)
{
  static char		*buffer = NULL;
  ssize_t		read_ret;
  ssize_t		buffer_writen_size;

  if (buffer == NULL)
  {
    buffer = malloc(sizeof(char) * buffer_size);
    if (buffer == NULL)
      return (NULL);
  }
  bzero(buffer, sizeof(char) * buffer_size);
  buffer_writen_size = 0;
  while (1)
  {
    read_ret = mycb_read(fd, &buffer[buffer_writen_size],
			 buffer_size - buffer_writen_size);
    if (read_ret == -1 || read_ret == 0)
      return (NULL);
    if (__mycb_loop_check_delim(buffer, buffer_size, delim) == 0)
      return (buffer);
    else
      buffer_writen_size = strlen(buffer);
    if ((size_t) buffer_writen_size > buffer_size)
      return (NULL);
  }
}