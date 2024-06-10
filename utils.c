/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:36:54 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/10 14:54:57 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	divisor;
	int		sign;

	result = 0;
	sign = 1;
	divisor = 0.1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
		if ('-' == *str++)
			sign = -1;
	while ((*str >= '0' && *str <= '9'))
		result = (result * 10.0) + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while ((*str >= '0' && *str <= '9'))
		{
			result = result + (*str - '0') * divisor;
			divisor *= 0.1;
			str++;
		}
	}
	return (sign * (result));
}
