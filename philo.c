/*
** philo.c for  in /home/rouane_q/projets/unix/philosophe
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Mar 18 15:23:57 2014 quentin rouanet
** Last update Thu Mar 20 10:33:49 2014 quentin rouanet
*/

#include "philo.h"

void philo_status(t_philo *philo, int last)
{
  if (philo->nb_stick == 0 && last != 0)
    {
      philo->status = 0;
      sleep(3);
    }
  else if (philo->nb_stick == 1 && last != 1)
    {
      philo->status = 1;
      sleep(2);
    }
  else if (philo->nb_stick == 2 && last != 2)
    {
      philo->status = 2;
      sleep(1);
    }
  else
    philo->status = 3;
}

int pre_stat(t_philo *philo, int last)
{
  if (last == 2)
    {
      philo->status = 0;
      return 0;
    }
  return 1;
}

void stick_use(t_philo *philo)
{
  if (philo->stick[philo->nb] == 0)
    {
      philo->nb_stick++;
      philo->stick[philo->nb] = philo->nb;
    }
  if (philo->stick[STICK(philo->nb)] == 0)
    {
      philo->nb_stick++;
      philo->stick[STICK(philo->nb)] = philo->nb;
    }
}

void *philo_action(void *arg)
{
  t_philo *philo;
  int last;

  last = -1;
  philo = (t_philo*)arg;
  while (philo->status != 3)
    {
      if (pre_stat(philo, last) != 0)
	stick_use(philo);
      philo_status(philo, last);
      philo->nb_stick = 0;
      last = philo->status;
      if (philo->stick[philo->nb] == philo->nb)
	philo->stick[philo->nb] = 0;
      if (philo->stick[STICK(philo->nb)] == philo->nb)
	philo->stick[STICK(philo->nb)] = 0;
    }
  pthread_exit(0);
}
