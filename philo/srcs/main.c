/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:25:09 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/18 17:02:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	assign_variables(t_philo *philo, int ac, char **av)
{
	philo->philo_num = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->num_time_to_eat = ft_atoi(av[5]);
	else
		philo->num_time_to_eat = 0;
}

void	*routine(void *args)
{
	int	philo_num;

	philo_num = *(int *)args;
	printf("Hello world from %i\n", philo_num);
	return (NULL);
}

void	thread_creation(t_philo *p)
{
	pthread_t	philos;
	int			i;
	int			**arg;

	i = -1;
	arg = malloc(sizeof(int *) * p->philo_num);
	if (!arg)
		exit (printf("Allocation failed for arg"));
	while (++i < p->philo_num)
	{
		*(int *)(arg + i) = i;
		if (pthread_create(&philos, NULL, &routine, (void *)(arg + i)) != 0)
			exit (printf("Error during thread creation\n"));
		if (pthread_detach(philos) != 0)
			exit (printf("Error during detach\n"));
	}
	pthread_exit(0);
	printf("Threads has been killed\n");
	i = -1;
	free(arg);
}

int	main(int ac, char **av)
{
	t_philo		p;

	if (ac != 5 && ac != 6)
		return (printf("Wrong number of arguments\n"));
	assign_variables(&p, ac, av);
	if (p.philo_num == 0 || p.time_to_die == 0 \
	|| p.time_to_eat == 0 || p.time_to_sleep == 0)
		return (printf("The arguments can't be 0\n"));
	thread_creation(&p);
}
