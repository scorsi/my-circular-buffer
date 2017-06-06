/*
** mycb.h for mycircularbuffer in /home/sylvain/Travail/Perso/mycircularbuffer/mycb.h
**
** Made by Sylvain CORSINI
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sat Jun 03 19:49:00 2017 Sylvain CORSINI
** Last update Sat Jun 03 19:49:00 2017 Sylvain CORSINI
*/

#ifndef MYCIRCULARBUFFER_MYCB_H
#define MYCIRCULARBUFFER_MYCB_H

#include <unistd.h>

#define			MYCB_BUFFER_SIZE	(100)

ssize_t			mycb_read(int fd, char *str,
				  size_t str_size);

char			*mycb_read_delim(int fd, size_t buffer_size,
					 char *delim);

#endif //MYCIRCULARBUFFER_MYCB_H
