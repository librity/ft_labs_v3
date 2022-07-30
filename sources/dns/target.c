/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/30 16:46:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

static t_dns_target	*new_dns_target(t_new_dns_target p)
{
	t_dns_target	*new;

	new = (t_dns_target *)ft_lalloc(lalloc(), sizeof(t_dns_target));
	new->name = ft_strdup_lalloc(lalloc(), p.name);
	new->address.name = ft_strdup_lalloc(lalloc(), p.address_name);
	new->frequency = p.frequency;
	new->server.ipv4 = ft_strdup_lalloc(lalloc(), p.server_ipv4);
	return (new);
}

void	add_dns_target(t_new_dns_target p)
{
	t_dns_target	*dns_target;

	dns_target = new_dns_target(p);
	ft_dlst_add_lalloc(lalloc(), dns_targets(), dns_target);
}