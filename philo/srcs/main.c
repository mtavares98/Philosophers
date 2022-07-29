/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:02:29 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/29 00:21:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_table	*table;
	t_philo	*philo;
	int		is_dead;

	if (ac != 5 && ac != 6)
		exit_free(NULL, NULL, 1, "Wrong number of arguments\n");
	data = intit_data(ac, av);
	table = init_table(&data);
	if (!table)
		exit_free(&table, NULL, 1, "Allocation failed for the table\n");
	is_dead = 0;
	philo = init_philo(&data, &table, &is_dead);
	if (!philo)
		exit_free(&table, &philo, 1, "Allocation failed for the philo\n");
	thread_creation(&philo);
}
