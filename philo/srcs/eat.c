/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:02:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/28 17:45:08 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	putting_fork(t_philo *p, t_time *t, int index)
{
	pthread_mutex_lock(&p->table[index].mutex_fork);
	if (p->table[index].have_fork)
	{
		pthread_mutex_unlock(&p->table[index].mutex_fork);
		return (0);
	}
	p->table[index].have_fork = 1;
	pthread_mutex_unlock(&p->table[index].mutex_fork);
	pthread_mutex_lock(p->print);
	print_message(p, t, "has putting a fork", 0);
	pthread_mutex_unlock(p->print);
	return (1);
}

int	taking_fork(t_philo *p, t_time *t, int index)
{
	pthread_mutex_lock(&p->table[index].mutex_fork);
	if (!p->table[index].have_fork)
	{
		pthread_mutex_unlock(&p->table[index].mutex_fork);
		return (0);
	}
	p->table[index].have_fork = 0;
	pthread_mutex_unlock(&p->table[index].mutex_fork);
	pthread_mutex_lock(p->print);
	print_message(p, t, "has taken a fork", 0);
	pthread_mutex_unlock(p->print);
	return (1);
}

int	taking_aux(t_philo *p, t_time *t, int is_first)
{
	int	left;
	int	right;
	int	ret;

	left = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	right = (p->id - ((!is_first)));
	if (left == right)
		return (-1);
	ret = taking_fork(p, t, left);
	if (!ret)
		return (ret);
	ret += taking_fork(p, t, right);
	if (ret == 1)
		ret -= putting_fork(p, t, left);
	return (ret);
}

void	putting_forks(t_philo *p, t_time *t, int is_first)
{
	int	left;
	int	right;

	left = ((is_first) * (p->data.philo_num - 1)) + ((!is_first) * (p->id));
	right = (p->id - ((!is_first)));
	pthread_mutex_lock(&p->table[left].mutex_fork);
	putting_fork(p, t, left);
	putting_fork(p, t, right);
	return ;
}

void	eat(t_philo *p, t_time *t)
{
	int	complete;

	complete = 0;
	while (complete != 2)
		complete = taking_aux(p, t, (!p->id));
	pthread_mutex_lock(p->print);
	print_message(p, t, "is eating", 1);
	usleep(p->data.time_to_eat * 1000);
	pthread_mutex_unlock(p->print);
	putting_forks(p, t, (!p->id));
	return ;
}
