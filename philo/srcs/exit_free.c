/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:53 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:48:14 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	exit_free(t_table **table, t_philo **philo, int i, char *str)
{
	int	j;

	j = -1;
	if (i)
		printf("%s", str);
	if (table && *table)
	{
		j = -1;
		while (++i < (*philo)[0].data.philo_num)
			pthread_mutex_destroy(&(*table)[i].mutex_fork);
		free(*table);
	}
	if (philo && *philo)
	{
		pthread_mutex_destroy(&(*philo)->death->death);
		pthread_mutex_destroy((*philo)->print);
		free(*philo);
	}
	exit(i);
}
