/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:12:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:25 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifier si les arguments sont des nombres
int check_args(char **argv)
{
    int i;
    
    i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                write(2, "Error in the written args\n", 27);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

// Verifier si les nombres sont uniques
int check_uniques(char **argv)
{
    int i;
    
    i = 1;
    while (argv[i])
    {
        int j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                write(2, "Error because doubles\n", 22);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}
// Verifier si les nombres sont dans la bonne plage
int check_range(char **argv)
{
    int i;
    
    i = 1;
    while (argv[i])
    {
        if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
        {
             write(2, "Error in range\n", 15);
            return (0);
        }
        i++;
    }
    return (1);
}

// Verifier si les nombres sont dans le bon ordre
int check_order(char **argv)
{
    int i;
    
    i = 1;
    while (argv[i] && argv[i + 1])
    {
        if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
            return (0);
        i++;
    }
    return (1);
}

char **parse_args(int argc, char **argv)
{
    char **args = malloc(sizeof(char *) * argc);
    if (!args)
        return (NULL);

    int i = 1;
    while (i < argc)
    {
        args[i - 1] = strdup(argv[i]);
        if (!args[i - 1])
        {
            free_args(args, i - 1);
            return (NULL);
        }
        i++;
    }
    args[argc - 1] = NULL;
    return (args);
}

void free_args(char **args, int argc)
{
    int i;

    i = 0;
    while (i < argc)
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int validate_args(char **args, int argc)
{
    int i;

    i = 0;
    // Vérifier que chaque argument est un nombre valide
    while (args[i])
    {
        int j = 0;
        if (args[i][j] == '-' || args[i][j] == '+')
            j++;
        while (args[i][j])
        {
            if (args[i][j] < '0' || args[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }

    // Vérifier si les arguments sont dans la plage valide
    i = 0;
    while (args[i])
    {
        long long num = ft_atoi(args[i]);
        if (num > 2147483647 || num < -2147483647)
            return (0);
        i++;
    }
    
    // Vérifier l'unicité des arguments
    while (i < argc - 1)
    {
        int j = i + 1;
        while (j < argc - 1)
        {
            if (ft_atoi(args[i]) == ft_atoi(args[j]))
                return (0);
            j++;
        }
    }

    return (1);
}


