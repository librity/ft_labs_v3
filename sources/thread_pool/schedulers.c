/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedulers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 21:31:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static void	spawn_schedulers(void)
{
	t_dlist	*thread_node;
	t_dlist	*target_node;

	thread_node = *schedulers();
	target_node = *targets();
	while (thread_node != NULL || target_node != NULL)
	{
		nspawn_thread(thread_node, &run_scheduler, nget_target(target_node));
		thread_node = thread_node->next;
		target_node = target_node->next;
	}
	if (thread_node != NULL && target_node != NULL)
		die(SPAWN_SCHEDULERS_ERR);
}

#define CREATE_MSG "Creating scheduler threads."

void	create_schedulers(void)
{
	tdebug(CREATE_MSG);
	initialize_n_threads(schedulers(), targets_count());
	if (targets_count() != schedulers_count())
		die(INIT_SCHEDULERS_ERR);
	spawn_schedulers();
}

#define CANCEL_MSG "Canceling scheduler threads."

void	cancel_schedulers(void)
{
	tdebug(CANCEL_MSG);
	cancel_threads(schedulers());
}

#define JOIN_MSG "Joining scheduler threads."

void	join_schedulers(void)
{
	tdebug(JOIN_MSG);
	join_threads(schedulers());
}