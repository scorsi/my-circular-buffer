/*
** main.c for mycircularbuffer in /home/sylvain/Travail/Perso/mycircularbuffer/main.c
**
** Made by Sylvain CORSINI
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Fri Jun 02 17:12:49 2017 Sylvain CORSINI
** Last update Fri Jun 02 17:12:49 2017 Sylvain CORSINI
*/

#include <stdlib.h>
#include <stdio.h>
#include "mycb.h"

int main()
{
  char *str;

  str = mycb_read_delim(STDIN_FILENO, 512, "bite\n");
  if (str == NULL)
    return (EXIT_FAILURE);
  dprintf(STDOUT_FILENO, "res: %s\n", str);
  return (EXIT_SUCCESS);
}
