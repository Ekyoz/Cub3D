/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:30:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/02 13:02:55 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool is_map(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        while(str[i] && ft_isspace(str[i]))
            i++;
        if((str[i] == '1' || str[i] == '0'))
        {
            if(i == 0  || ft_isspace(str[i - 1]))
                return true;
        }
        if(str[i] == '\0')
            return false;
        i++;
    }
    return false;
}

bool space_before(char *str, int index)
{
    int i;

    i = 0;
    while(i < index)
    {
        if(str[i] != ' ' || str[i] != '\t')
            return false;
        i++;
    }
    return true;
}

bool space_inside(char *start, char *end)
{
    int i;
    int j;
    
    j = 0;
    i = end - start;
    while(j < i)
    {
        if(start[j] != ' ' && start[j] != '\t')
        {
            return false;
        }
        j++;
    }
    return true;
}
