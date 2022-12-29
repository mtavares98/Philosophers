/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:06:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:41:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	intit_data(int ac, char **av)
{
	t_data	data;

	data.philo_num = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data.num_time_to_eat = ft_atoi(av[5]);
	else
		data.num_time_to_eat = -1;
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
	static t_death	death;

	pthread_mutex_init(&death.death, NULL);
	return (&death);
}

t_time	*init_timer(void)
{
	static t_time	timer;

	return (&timer);
}

t_philo	*init_philo(t_data *data, t_table **table, t_death *death)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
	{
		pthread_mutex_destroy(&death->death);
		return (NULL);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		philo[i].data = *data;
		philo[i].id = i + 1;
		philo[i].table = *table;
		philo[i].death = death;
		philo[i].num_time_eaten = 0;
		philo[i].t = init_timer();
	}
	return (philo);
}
