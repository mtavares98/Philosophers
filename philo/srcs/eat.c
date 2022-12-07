/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:02:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/06 21:48:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	putting_forks(t_philo *p, int fork)
{
	pthread_mutex_lock(&p->table[fork].mutex_fork);
	if (!p->table[fork].have_fork && p->hold_forks)
	{
		p->table[fork].have_fork = 1;
		pthread_mutex_unlock(&p->table[fork].mutex_fork);
		print_message(p, "has putting a fork", 0);
		p->hold_forks--;
	}
	else
		pthread_mutex_unlock(&p->table[fork].mutex_fork);
	return (1);
}

int	taking_fork(t_philo *p, int fork)
{
	pthread_mutex_lock(&p->table[fork].mutex_fork);
	if (p->table[fork].have_fork)
	{
		p->table[fork].have_fork = 0;
		pthread_mutex_unlock(&p->table[fork].mutex_fork);
		print_message(p, "has taken a fork", 0);
		p->hold_forks++;
	}
	else
	{
		pthread_mutex_unlock(&p->table[fork].mutex_fork);
		return (0);
	}
	return (1);
}

int	eat(t_philo *p)
{
	int	first;
	int	second;

	first = ((p->id == 0) * (p->data.philo_num - 1)) + ((p->id != 0) * (p->id));
	second = (p->id - (p->id != 0));
	while (!taking_fork(p, first))
		;
	while (!taking_fork(p, second))
	{
		if (putting_forks(p, first))
			continue ;
	}
	if (p->hold_forks == 2)
	{
		print_message(p, "is eating", 1);
		usleep(p->data.time_to_eat * 1000);
		putting_forks(p, first);
		putting_forks(p, second);
		return (0);
	}
	return (1);
}
