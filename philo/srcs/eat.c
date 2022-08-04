/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:19:52 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 03:08:24 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_id_0(t_philo *p)
{
	if (is_dead(p))
		return ;
	pthread_mutex_lock(&p->table[p->data->philo_num - 1].mutex_fork);
	print_message(p, "has taken a fork", 0);
	p->table[p->data->philo_num - 1].have_fork = 0;
	pthread_mutex_lock(&p->table[p->id].mutex_fork);
	print_message(p, "has taken a fork", 0);
	p->table[p->id].have_fork = 0;
	print_message(p, "is eating", 1);
	usleep(p->data->time_to_eat);
	p->table[p->data->philo_num - 1].have_fork = 1;
	pthread_mutex_unlock(&p->table[p->data->philo_num - 1].mutex_fork);
	p->table[p->id].have_fork = 1;
	pthread_mutex_unlock(&p->table[p->id].mutex_fork);
}

static void	philo_id_diff_0(t_philo *p)
{
	if (is_dead(p))
		return ;
	pthread_mutex_lock(&p->table[p->id].mutex_fork);
	print_message(p, "has taken a fork", 0);
	p->table[p->id].have_fork = 0;
	pthread_mutex_lock(&p->table[p->id - 1].mutex_fork);
	print_message(p, "has taken a fork", 0);
	p->table[p->id + 1].have_fork = 0;
	print_message(p, "is eating", 1);
	usleep(p->data->time_to_eat);
	p->table[p->id].have_fork = 1;
	pthread_mutex_unlock(&p->table[p->id].mutex_fork);
	p->table[p->id - 1].have_fork = 1;
	pthread_mutex_unlock(&p->table[p->id - 1].mutex_fork);
}

void	eat(t_philo *p)
{
	if (!p->id)
		philo_id_0(p);
	else
		philo_id_diff_0(p);
}
