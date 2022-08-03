/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:14:12 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:14:14 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	sum(int x, int y)
{
	return (x + y);
}

int	sub(int x, int y)
{
	return (x - y);
}

int	mul(int x, int y)
{
	return (x * y);
}

int	div(int x, int y)
{
	return (x / y);
}

int	mod(int x, int y)
{
	return (x % y);
}
