/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:06:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/29 00:52:06 by mtavares         ###   ########.fr       */
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
		data.num_time_to_eat = 2147483648;
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
		table[i].have_fork = 1;
	return (table);
}

t_philo	*init_philo(t_data *data, t_table **table, int	*is_dead)
{
	t_philo	*philo;
	int		i;

	philo = NULL;
	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < data->philo_num)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].is_dead = is_dead;
		philo[i].table = *table;
	}
	return (philo);
}
