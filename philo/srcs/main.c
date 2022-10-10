/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:02:29 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/09 22:21:27 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*	That big if is for doing exit_free when one of the conditions is true.
	The last line is for doing exit_free when i have the last argument
	invalid, which is optional. */

int	main(int ac, char **av)
{
	t_data	data;
	t_table	*table;
	t_philo	*p;
	t_death	*death;
	int		is_not_valid;

	if (ac != 5 && ac != 6)
		exit_free(NULL, NULL, 1, "Wrong number of arguments\n");
	data = intit_data(ac, av);
	is_not_valid = ((data.philo_num <= 0) + (data.time_to_die <= 0) + \
	(data.time_to_eat <= 0) + (data.time_to_sleep <= 0)) + \
	(((!data.have_last_arg) * -1) + (data.num_time_to_eat <= 0));
	if (is_not_valid)
		exit_free(NULL, NULL, 1, "Invalid arguments\n");
	table = init_table(&data);
	if (!table)
		exit_free(&table, NULL, 1, "Allocation failed for the table\n");
	death = init_death();
	p = init_philo(&data, &table, death);
	if (!p)
		exit_free(&table, &p, 1, "Allocation failed for the philo\n");
	thread_creation(&p);
	exit_free(&table, &p, 0, NULL);
	return (0);
}
