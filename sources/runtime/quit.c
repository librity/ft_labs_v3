/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:35:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/02 11:33:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	quit(void)
{
	ts_fprintf(stdout, GB"See ya!\n"RC);
	exit(EXIT_SUCCESS);
}

void	help_and_quit(void)
{
	ft_putstr(HELP_MSG);
	quit();
}

// TODO: SIMPLIFY!
void	simplify_and_quit(void)
{
	ft_putstr("TODO: SIMPLIFY!\n");
	quit();
}

void	close_thread_pool_and_quit(void)
{
	close_thread_pool();
	quit();
}
