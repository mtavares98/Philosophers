/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:02:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/07 16:51:27 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	putting_forks(t_philo *p, int fork)
{
	pthread_mutex_lock(&p->table[fork].mutex_fork);
	p->table[fork].have_fork = 1;
	pthread_mutex_unlock(&p->table[fork].mutex_fork);
}

void	taking_fork(t_philo *p, int fork)
{
	while (!is_dead(p))
	{
		pthread_mutex_lock(&p->table[fork].mutex_fork);
		if (p->table[fork].have_fork)
		{
			p->table[fork].have_fork = 0;
			pthread_mutex_unlock(&p->table[fork].mutex_fork);
			break ;
		}
		else
			pthread_mutex_unlock(&p->table[fork].mutex_fork);
	}
}

void	eat(t_philo *p)
{
	int	first;
	int	second;

	first = ((p->id == 0) * (p->data.philo_num - 1)) + ((p->id != 0) * (p->id));
	second = (p->id - (p->id != 0));
	taking_fork(p, first);
	if (!check_death(p))
		print_message(p, "has taken a fork");
	taking_fork(p, second);
	if (!check_death(p))
		print_two_messages(p);
	sleep_action(p->data.time_to_eat, p);
	putting_forks(p, first);
	putting_forks(p, second);
}
