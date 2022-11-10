/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:02:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/10 22:00:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	taking_fork(t_philo *p, t_time *t, int is_first)
{
	int	first;
	int	second;

	first = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	second = (p->id - ((!is_first)));
	pthread_mutex_lock(&p->table[first].mutex_fork);
	if (first == second)
		return (1);
	if (p->table[first].have_fork)
	{
		p->table[first].have_fork = 0;
		pthread_mutex_unlock(&p->table[first].mutex_fork);
		print_message(p, t, "has taken a fork", 0);
		pthread_mutex_lock(&p->table[second].mutex_fork);
		p->table[second].have_fork = 0;
		pthread_mutex_unlock(&p->table[second].mutex_fork);
		print_message(p, t, "has taken a fork", 0);
	}
	else
		pthread_mutex_unlock(&p->table[first].mutex_fork);
	return (0);
}

void	putting_forks(t_philo *p, int is_first)
{
	int	first;
	int	second;

	first = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	second = (p->id - ((!is_first)));
	pthread_mutex_lock(&p->table[first].mutex_fork);
	if (!p->table[first].have_fork)
	{
		p->table[first].have_fork = 1;
		pthread_mutex_unlock(&p->table[first].mutex_fork);
		pthread_mutex_lock(&p->table[second].mutex_fork);
		p->table[second].have_fork = 1;
		pthread_mutex_unlock(&p->table[second].mutex_fork);
	}
	else
		pthread_mutex_unlock(&p->table[first].mutex_fork);
	return ;
}

int	eat(t_philo *p, t_time *t)
{
	if (taking_fork(p, t, (!p->id)))
		return (1);
	usleep(p->data.time_to_eat / 100);
	pthread_mutex_lock(p->print);
	print_message(p, t, "is eating", 1);
	pthread_mutex_unlock(p->print);
	putting_forks(p, (!p->id));
	return (0);
}
