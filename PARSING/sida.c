/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sida.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:23:20 by motaouss          #+#    #+#             */
/*   Updated: 2023/01/20 04:32:09 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sidametocosita(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sidaction(void)
{
	signal (SIGINT, sidametocosita);
	signal (SIGQUIT, SIG_IGN);
}
