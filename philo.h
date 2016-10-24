/*
** philo.h for  in /home/rouane_q/projets/unix/philosophe
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Mar 18 11:47:12 2014 quentin rouanet
** Last update Wed Mar 19 09:34:31 2014 quentin rouanet
*/

#ifndef PHILO_H__
# define PHILO_H__

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_philo
{
  int		nb;
  pthread_t	th;
  int		*stick;
  int		status;
  int		nb_stick;
}		t_philo;

#define STICK(x) (x) == 0 ? 7 : (x) - 1

void *philo_action(void *arg);

#endif /* !PHILO_H__ */
