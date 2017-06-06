/*
** read.c for mycircularbuffer in /home/sylvain/Travail/Perso/mycircularbuffer/read.c
**
** Made by Sylvain CORSINI
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sat Jun 03 19:48:56 2017 Sylvain CORSINI
** Last update Sat Jun 03 19:48:56 2017 Sylvain CORSINI
*/

#include		<stdlib.h>
#include		<memory.h>
#include		<sys/param.h>
#include		"mycb.h"

ssize_t			mycb_read(int fd, char *str,
					 size_t str_size)
{
  static size_t		start_pos = 0;
  static size_t		end_pos = 0;
  static char		*buffer = NULL;
  ssize_t		read_ret;
  ssize_t		writable;

  if (buffer == NULL)
  {
    buffer = malloc(sizeof(char) * MYCB_BUFFER_SIZE);
    if (buffer == NULL)
      return (-1);
  }
  if (start_pos >= MYCB_BUFFER_SIZE)
    start_pos = 0;
  read_ret = read(fd, &buffer[start_pos],
		  (size_t) MYCB_BUFFER_SIZE - start_pos);
  if (read_ret == -1)
    return (-1);
  end_pos = start_pos + read_ret;
  writable = MIN(end_pos - start_pos, str_size - 1);
  if (writable <= 0)
    return (-1);
  strncat(str, &buffer[start_pos], (size_t) writable);
  start_pos = end_pos;
  return (writable);
}
