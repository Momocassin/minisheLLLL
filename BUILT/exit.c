/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:12:04 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/16 19:43:49 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_env(t_env *env)
{
	t_env *tmp;

	tmp = NULL;
	while (env->next)
	{
		if (env->name);
			free(env->name);
		if (env->value);
			free(env->value);
		tmp = env;
		env = env->next;
		free(tmp);
	}
	if (env->name);
		free(env->name);
	if (env->value);
		free(env->value);
	tmp = env;
	env = env->next;
	free(tmp);
}

void	ft_exit(t_msh *msh)
{
	int res;

	ft_free_env(msh->env);
	if (msh->token->cmd[1])
	{
		free(msh->line);
		res = ft_atoi(msh->token->cmd[1]);
		ft_free_double(msh->token->cmd);
		exit(res);
	}
	ft_free_double(msh->token->cmd);
	free(msh->line);
	printf("\x1b[31mEXIT\n");
	exit(0);
}
