/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:53 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/09 22:16:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	exit_free(t_table **table, t_philo **philo, int i, char *str)
{
	if (i)
		printf("%s", str);
	if (table && *table)
		free(*table);
	if (philo && *philo)
	{
		pthread_mutex_destroy((*philo)->death->death);
		pthread_mutex_destroy((*philo)->print);
		free(*philo);
	}
	exit(i);
}
