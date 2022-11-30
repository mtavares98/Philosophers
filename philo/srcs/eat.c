/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:02:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/30 18:06:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	taking_fork(t_philo *p, int is_first)
{
	int	first;
	int	second;

	first = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	second = (p->id - ((!is_first)));
	if (pthread_mutex_lock(&p->table[first].mutex_fork) != 0)
		return (0);
	print_message(p, "has taken a fork", 0);
	if (pthread_mutex_lock(&p->table[second].mutex_fork) != 0)
	{
		pthread_mutex_unlock(&p->table[first].mutex_fork);
		return (0);
	}
	print_message(p, "has taken a fork", 0);
	return (1);
}

int	putting_forks(t_philo *p, int is_first)
{
	int	first;
	int	second;

	first = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	second = (p->id - ((!is_first)));
	print_message(p, "has putting a fork", 0);
	if (pthread_mutex_unlock(&p->table[first].mutex_fork) != 0)
		return (0);
	print_message(p, "has putting a fork", 0);
	if (pthread_mutex_unlock(&p->table[second].mutex_fork) != 0)
		return (0);
	return (1);
}

int	eat(t_philo *p)
{
	if (!taking_fork(p, (!p->id)))
		return (0);
	print_message(p, "is eating", 1);
	usleep(p->data.time_to_eat * 1000);
	putting_forks(p, (!p->id));
	return (1);
}
