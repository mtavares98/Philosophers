/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:36:17 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/30 18:02:50 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*philo_work(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(p->print);
	p->t = init_timer();
	p->t->start = current_time();
	p->last_meal = p->t->start;
	p->last_action = p->t->start;
	pthread_mutex_unlock(p->print);
	while (++p->num_time_eaten * (p->data.have_last_arg) <= \
	(p->data.have_last_arg) * p->data.num_time_to_eat && \
	!is_dead(p))
	{
		eat(p);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is sleeping", 0);
		usleep(p->data.time_to_sleep * 1000);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is thinking", 0);
	}
	return (NULL);
}

void	thread_creation(t_philo **philo)
{
	static pthread_mutex_t	print;
	int						i;

	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < (*philo)[0].data.philo_num)
	{
		(*philo)[i].print = &print;
		pthread_create(&(*philo)[i].philo, NULL, &philo_work, (*philo + i));
	}
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_join((*philo)[i].philo, NULL);
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
}
