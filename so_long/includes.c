/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:51:35 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/28 14:51:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_intlen(int c)
{
	int	len;

	len = 0;
	if (c <= 0)
		len++;
	while (c != 0)
	{
		len++;
		c = c / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	len = ft_intlen(n);
	num = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}