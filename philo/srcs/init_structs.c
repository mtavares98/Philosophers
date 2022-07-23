/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:41:14 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/23 23:49:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*create_philo(t_gen *gen, t_table *table, pthread_mutex_t *mutex, \
int *is_dead)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * (gen->philo_num));
	if (!philo)
		exit(0);
	i = -1;
	while (++i < gen->philo_num)
	{
		philo->gen = gen;
		philo->id = i;
		philo->is_dead = is_dead;
		philo->table = table;
		philo->mutex = mutex;
	}
	return (philo);
}

t_gen	create_gen(int ac, char **av)
{
	t_gen	gen;

	gen.philo_num = ft_atoi(av[1]);
	gen.time_to_die = ft_atoi(av[2]);
	gen.time_to_eat = ft_atoi(av[3]);
	gen.time_to_sleep = ft_atoi(av[4]);
	gen.have_last_arg = 1;
	if (ac == 6)
		gen.num_time_to_eat = ft_atoi(av[5]);
	else
	{
		gen.have_last_arg = 1;
		gen.time_to_eat = 0;
	}
}

t_table	*create_table(int philo_num)
{
	t_table	*table;
	int		i;

	table = malloc(sizeof(t_table) * (philo_num));
	if (!table)
		exit(0);
	i = -1;
	while (++i < philo_num)
	{
		table[i].id = i;
		table[i].fork = 1;
	}
	return (table);
}
