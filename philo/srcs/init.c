/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:06:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/09 22:28:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_data	intit_data(int ac, char **av)
{
	t_data	data;

	data.have_last_arg = have_last_arg(ac);
	data.philo_num = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (data.have_last_arg)
		data.num_time_to_eat = ft_atoi(av[5]);
	else
		data.num_time_to_eat = 0;
	return (data);
}

t_table	*init_table(t_data *data)
{
	t_table	*table;
	int		i;

	table = malloc(sizeof(t_table) * data->philo_num);
	if (!table)
		return (NULL);
	i = -1;
	while (++i < data->philo_num)
	{
		table[i].have_fork = 1;
		pthread_mutex_init(&table[i].mutex_fork, NULL);
	}
	return (table);
}

t_death	*init_death(void)
{
	static pthread_mutex_t	death_m;
	static int				is_death = 0;
	static t_death			death;

	pthread_mutex_init(&death_m, NULL);
	death.death = &death_m;
	death.is_death = &is_death;
	return (&death);
}

t_philo	*init_philo(t_data *data, t_table **table, t_death *death)
{
	t_philo					*philo;
	static pthread_mutex_t	print;
	int						i;

	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
	{
		pthread_mutex_destroy(death->death);
		return (NULL);
	}
	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < data->philo_num)
	{
		philo[i].data = *data;
		philo[i].id = i;
		philo[i].table = *table;
		philo[i].print = &print;
		philo[i].death = death;
		philo[i].num_time_eaten = -1;
	}
	return (philo);
}
