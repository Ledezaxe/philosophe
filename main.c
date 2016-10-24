/*
** main.c for  in /home/rouane_q/projets/unix/philosophe
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Mon Mar 17 10:25:33 2014 quentin rouanet
** Last update Thu Mar 20 10:32:51 2014 quentin rouanet
*/

#include "philo.h"

void	init_philo(t_philo* philo, int stick[7])
{
  int	i;

  i = 0;
  while (i < 7)
    {
      stick[i] = 0;
      i++;
    }

  i = 0;
  while (i < 7)
    {
      philo[i].nb = i + 1;
      philo[i].status = 0;
      philo[i].nb_stick = 0;
      philo[i].stick = (int *)stick;
      i++;
    }
}

void *functsleep()
{
  sleep(10);
  pthread_exit(0);
}

void *disp_philo(void *arg)
{
  t_philo *philo;
  int	i;

  philo = (t_philo*)arg;
  while (1)
    {
      system("clear");
      i = 0;
      while (i < 7)
	{
	  if (philo[i].status == 0)
	    printf("le philosophe n°%d pionce\n", i + 1);
	  else if (philo[i].status == 1)
	    printf("le philosophe n°%d bouffe\n", i + 1);
	  else if (philo[i].status == 2)
	    printf("le philosophe n°%d réféchit\n", i + 1);
	  else
	    printf("le philosophe n°%d a un \"léger problème\"\n", i + 1);
	  i++;
	}
      sleep(1);
    }
}

int	main()
{
  t_philo	philo[7];
  pthread_t	sleep;
  int		stick[7];
  pthread_t	disp;
  int		i;

  init_philo(philo, stick);
  pthread_create(&disp, NULL, disp_philo, (void *)philo);
  pthread_create(&sleep, NULL, functsleep, NULL);
  i = 0;
  while (i < 7)
    {
      pthread_create(&philo[i].th, NULL, philo_action, (void *)&philo[i]);
      i++;
    }
  pthread_join(sleep, NULL);
  return 1;
}
