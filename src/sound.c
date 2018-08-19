/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:35:42 by mnoskov           #+#    #+#             */
/*   Updated: 2018/08/14 18:24:36 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	steps(void)
{
	system("afplay assets/steps-short.mp3 &");
}

void	fon(void)
{
	system("afplay assets/fon.wav &");
}
