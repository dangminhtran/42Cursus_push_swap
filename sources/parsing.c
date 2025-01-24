/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:12:12 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 18:59:55 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifier si les arguments sont des nombres
int check_args(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                // write(2, "Error\n", 6);
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
    int i = 1;
    while (argv[i])
    {
        int j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                // write(2 "Error\n", 6);
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
    int i = 1;
    while (argv[i])
    {
        if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
        {
            // write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
    return (1);
}

// Verifier si les nombres sont dans le bon ordre
int check_order(char **argv)
{
    int i = 1;

    while (argv[i] && argv[i + 1])
    {
        if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
        {
        //    write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
    return (1);
}

char **parse_args(int argc, char **argv)
{
    char **args = malloc(sizeof(char *) * argc);
    if (!args)
        return (NULL);

    for (int i = 1; i < argc; i++)
    {
        args[i - 1] = strdup(argv[i]);
        if (!args[i - 1])
        {
            free_args(args, i - 1);
            return (NULL);
        }
    }
    args[argc - 1] = NULL;
    return (args);
}

void free_args(char **args, int argc)
{
    for (int i = 0; i < argc; i++)
        free(args[i]);
    free(args);
}

int validate_args(char **args, int argc)
{
    // Vérifier que chaque argument est un nombre valide
    for (int i = 0; i < argc - 1; i++)
    {
        char *arg = args[i];
        int j = 0;

        // Vérifier si chaque caractère est un chiffre
        if (arg[j] == '-' || arg[j] == '+')
            j++;
        while (arg[j])
        {
            if (arg[j] < '0' || arg[j] > '9')
                return (0);
            j++;
        }
    }

    // Vérifier si les arguments sont dans la plage valide
    for (int i = 0; i < argc - 1; i++)
    {
        long long num = ft_atoi(args[i]);
        if (num > 2147483647 || num < -2147483647)
            return (0);
    }

    // Vérifier l'unicité des arguments
    for (int i = 0; i < argc - 1; i++)
    {
        for (int j = i + 1; j < argc - 1; j++)
        {
            if (ft_atoi(args[i]) == ft_atoi(args[j]))
                return (0);
        }
    }

    return (1);
}


