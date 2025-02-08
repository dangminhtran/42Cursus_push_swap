/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:15:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/08 18:15:59 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// V0
int is_sorted(t_stack *stack)
{
    t_list *current = stack->head;
    while (current && current->next)
    {
        if (current->number > current->next->number)
            return (0);
        current = current->next;
    }
    return (1);
}

void sort_three(t_stack *stack)
{
    int first = stack->head->number;
    int second = stack->head->next->number;
    int third = stack->head->next->next->number;

    if (first > second && second < third && first < third)
        sa(&stack->head);
    else if (first > second && second > third)
    {
        sa(&stack->head);
        rra(&stack->head);
    }
    else if (first > second && second < third && first > third)
        ra(&stack->head);
    else if (first < second && second > third && first < third)
    {
        sa(&stack->head);
        ra(&stack->head);
    }
    else if (first < second && second > third && first > third)
        rra(&stack->head);
}

void sort_small_stack(t_stack *stack)
{
    if (stack->size <= 1)
        return;
    if (stack->size == 2)
    {
        if (stack->head->number > stack->head->next->number)
            sa(&stack->head);
        return;
    }
    if (stack->size == 3)
        sort_three(stack);
}

int find_min_position(t_stack *stack)
{
    t_list *current = stack->head;
    int min = current->number;
    int pos = 0;
    int min_pos = 0;
    
    while (current)
    {
        if (current->number < min)
        {
            min = current->number;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

// V0 - FONCTIONNE MAIS PAS OPTIMISEE
// void push_swap(t_stack **stack_a, t_stack **stack_b)
// {
//     if (!stack_a || !*stack_a || (*stack_a)->size <= 1)
//         return;
//     if ((*stack_a)->size <= 3)
//     {
//         sort_small_stack(*stack_a);
//         return;
//     }
//     while ((*stack_a)->size > 3)
//     {
//         int min_pos = find_min_position(*stack_a);    
//         while (min_pos > 0)
//         {
//             if (min_pos <= (*stack_a)->size / 2)
//                 ra(&(*stack_a)->head);
//             else
//                 rra(&(*stack_a)->head);
//             min_pos = find_min_position(*stack_a);
//         }
//         pb(&(*stack_a)->head, &(*stack_b)->head);
//         (*stack_a)->size--;
//         (*stack_b)->size++;
//     }
//     sort_small_stack(*stack_a);
//     while ((*stack_b)->size > 0)
//     {
//         pa(&(*stack_a)->head, &(*stack_b)->head);
//         (*stack_a)->size++;
//         (*stack_b)->size--;
//     }
// }

// AJOUT DE FONCTIONS V1
/*
int get_max(t_stack *stack)
{
    t_list *current = stack->head;
    int max = current->number;

    while (current)
    {
        if (current->number > max)
            max = current->number;
        current = current->next;
    }
    return max;
}

int *copy_and_sort_stack(t_stack *stack)
{
    int size;
    size = stack->size;

    int *arr;
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;

    t_list *current;
    current = stack->head;

    int i;
    i = 0;

    while (i < size)
    {
        arr[i] = current->number;
        current = current->next;
        i++;
    }

    int j;
    j = 0;
    int k;
    k = 0;

    while (j < size - 1)
    {
        while (k < size - j - 1)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp;
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
            k++;
        }
        j++;
       
    }

    return arr;
}
*/

// AJOUT DE FONCTIONS V2

 void handle_small_stack(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_a)->size > 3)
    {
        int min_pos = find_min_position(*stack_a);
        int size = (*stack_a)->size;
        
        if (min_pos <= size / 2)
        {
            for (int i = 0; i < min_pos; i++)
                ra(&(*stack_a)->head);
        }
        else
        {
            for (int i = 0; i < size - min_pos; i++)
                rra(&(*stack_a)->head);
        }
        pb(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size--;
        (*stack_b)->size++;
    }
    sort_small_stack(*stack_a);
}
/*
int get_chunk_count(int size)
{
    if (size <= 100)
        return (5);
    return (11);
}

void rotate_to_closest(t_stack **stack, int chunk_max, char stack_name)
{
    t_list *tmp = (*stack)->head;
    int closest_pos = (*stack)->size;
    int pos = 0;
    
    while (tmp)
    {
        if (tmp->number <= chunk_max)
        {
            closest_pos = pos;
            break;
        }
        pos++;
        tmp = tmp->next;
    }
    
    if (closest_pos <= (*stack)->size / 2)
        (stack_name == 'a') ? ra(&(*stack)->head) : rb(&(*stack)->head);
    else
        (stack_name == 'a') ? rra(&(*stack)->head) : rrb(&(*stack)->head);
}

int count_chunk_numbers(t_stack *stack, int chunk_max)
{
    int count = 0;
    t_list *tmp = stack->head;
    
    while (tmp)
    {
        if (tmp->number <= chunk_max)
            count++;
        tmp = tmp->next;
    }
    return (count);
}

void process_chunk(t_stack **stack_a, t_stack **stack_b, int chunk_max)
{
    int numbers_to_push = count_chunk_numbers(*stack_a, chunk_max);
    int pushed = 0;
    
    while (pushed < numbers_to_push)
    {
        if ((*stack_a)->head->number <= chunk_max)
        {
            pb(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size--;
            (*stack_b)->size++;
            pushed++;
        }
        else
            rotate_to_closest(stack_a, chunk_max, 'a');
    }
}

int find_max_position(t_stack *stack)
{
    t_list *tmp = stack->head;
    int max = tmp->number;
    int max_pos = 0;
    int pos = 0;
    
    while (tmp)
    {
        if (tmp->number > max)
        {
            max = tmp->number;
            max_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return (max_pos);
}

void rotate_to_max(t_stack **stack_b)
{
    int max_pos = find_max_position(*stack_b);
    
    while (max_pos > 0)
    {
        if (max_pos <= (*stack_b)->size / 2)
        {
            rb(&(*stack_b)->head);
            max_pos--;
        }
        else
        {
            rrb(&(*stack_b)->head);
            max_pos = (max_pos + 1) % (*stack_b)->size;
        }
    }
}

void push_back_sorted(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_b)->size > 0)
    {
        rotate_to_max(stack_b);
        pa(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size++;
        (*stack_b)->size--;
    }
}

void sort_chunks(t_stack **stack_a, t_stack **stack_b)
{
    int *sorted = copy_and_sort_stack(*stack_a);
    if (!sorted)
        return;

    int size = (*stack_a)->size;
    int num_chunks = get_chunk_count(size);
    int chunk_size = size / num_chunks;
    
    for (int i = 0; i < num_chunks; i++)
    {
        int chunk_max = sorted[((i + 1) * chunk_size) - 1];
        if (i == num_chunks - 1)
            chunk_max = sorted[size - 1];
            
        process_chunk(stack_a, stack_b, chunk_max);
    }
    
    free(sorted);
    push_back_sorted(stack_a, stack_b);
}
*/

/*
void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || (*stack_a)->size <= 1 || is_sorted(*stack_a))
        return;

    if ((*stack_a)->size <= 3)
    {
        sort_small_stack(*stack_a);
        return;
    }
    
    if ((*stack_a)->size <= 5)
    {
        handle_small_stack(stack_a, stack_b);
        while ((*stack_b)->size > 0)
        {
            pa(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size++;
            (*stack_b)->size--;
        }
        return;
    }
    
    sort_chunks(stack_a, stack_b);
}
*/


// CA FONCTIONNE - V1
// void push_swap(t_stack **stack_a, t_stack **stack_b)
// {
//     if (!stack_a || !*stack_a || (*stack_a)->size <= 1 || is_sorted(*stack_a))
//         return;
//     // Handle small stacks efficiently
//     if ((*stack_a)->size <= 3)
//     {
//         sort_small_stack(*stack_a);
//         return;
//     }
//     if ((*stack_a)->size <= 5)
//     {
//         while ((*stack_a)->size > 3)
//         {
//             int min_pos = find_min_position(*stack_a);
//             int size = (*stack_a)->size;        
//             // More efficient rotation
//             if (min_pos <= size / 2)
//             {
//                 for (int i = 0; i < min_pos; i++)
//                     ra(&(*stack_a)->head);
//             }
//             else
//             {
//                 for (int i = 0; i < size - min_pos; i++)
//                     rra(&(*stack_a)->head);
//             }
//             pb(&(*stack_a)->head, &(*stack_b)->head);
//             (*stack_a)->size--;
//             (*stack_b)->size++;
//         }
//         sort_small_stack(*stack_a);
//         while ((*stack_b)->size > 0)
//         {
//             pa(&(*stack_a)->head, &(*stack_b)->head);
//             (*stack_a)->size++;
//             (*stack_b)->size--;
//         }
//         return;
//     }
//     // Get sorted array for reference
//     int *sorted = copy_and_sort_stack(*stack_a);
//     if (!sorted)
//         return;
//     // Calculate optimal number of chunks based on stack size
//     int size = (*stack_a)->size;
//     int num_chunks;
//     if (size <= 100)
//         num_chunks = 5;
//     else
//         num_chunks = 11;  // Optimized for 500 numbers
//     int chunk_size = size / num_chunks;  
//     // Push numbers to B in chunks, from smallest to largest
//     for (int i = 0; i < num_chunks; i++)
//     {
//         int chunk_max = sorted[((i + 1) * chunk_size) - 1];
//         if (i == num_chunks - 1)
//             chunk_max = sorted[size - 1];  // Last chunk takes remaining numbers
//         // Count how many numbers should go to chunk_b
//         int numbers_to_push = 0;
//         t_list *tmp = (*stack_a)->head;
//         while (tmp)
//         {
//             if (tmp->number <= chunk_max)
//                 numbers_to_push++;
//             tmp = tmp->next;
//         }
//         // Process current chunk efficiently
//         int pushed = 0;
//         while (pushed < numbers_to_push)
//         {
//             if ((*stack_a)->head->number <= chunk_max)
//             {
//                 pb(&(*stack_a)->head, &(*stack_b)->head);
//                 (*stack_a)->size--;
//                 (*stack_b)->size++;
//                 pushed++;
//             }
//             else
//             {
//                 // Find the closest number that should be pushed
//                 int closest_pos = size;
//                 tmp = (*stack_a)->head;
//                 int pos = 0;
//                 while (tmp)
//                 {
//                     if (tmp->number <= chunk_max)
//                     {
//                         closest_pos = pos;
//                         break;
//                     }
//                     pos++;
//                     tmp = tmp->next;
//                 }              
//                 // Rotate in the most efficient direction
//                 if (closest_pos <= (*stack_a)->size / 2)
//                     ra(&(*stack_a)->head);
//                 else
//                     rra(&(*stack_a)->head);
//             }
//         }
//     }
//     // Push back to A in descending order
//     while ((*stack_b)->size > 0)
//     {
//         // Find max in B
//         t_list *tmp = (*stack_b)->head;
//         int max = tmp->number;
//         int max_pos = 0;
//         int pos = 0;     
//         while (tmp)
//         {
//             if (tmp->number > max)
//             {
//                 max = tmp->number;
//                 max_pos = pos;
//             }
//             pos++;
//             tmp = tmp->next;
//         }
//         // Rotate B to bring max to top
//         while (max_pos > 0)
//         {
//             if (max_pos <= (*stack_b)->size / 2)
//             {
//                 rb(&(*stack_b)->head);
//                 max_pos--;
//             }
//             else
//             {
//                 rrb(&(*stack_b)->head);
//                 max_pos = (max_pos + 1) % (*stack_b)->size;
//             }
//         }
//         // Push max to A
//         pa(&(*stack_a)->head, &(*stack_b)->head);
//         (*stack_a)->size++;
//         (*stack_b)->size--;
//     }
//     free(sorted);
// }

// V3

// static void smart_rotate(t_stack **stack, int pos, char stack_name)
// {
//     int size = (*stack)->size;
    
//     if (pos <= size / 2)
//     {
//         while (pos-- > 0)
//             (stack_name == 'a') ? ra(&(*stack)->head) : rb(&(*stack)->head);
//     }
//     else
//     {
//         pos = size - pos;
//         while (pos-- > 0)
//             (stack_name == 'a') ? rra(&(*stack)->head) : rrb(&(*stack)->head);
//     }
// }

/* static void push_efficient_chunks(t_stack **stack_a, t_stack **stack_b)
{
    int size = (*stack_a)->size;
    int num_chunks = (size <= 100) ? 5 : 11;
    
    int min = INT_MAX;
    int max = INT_MIN;
    t_list *current = (*stack_a)->head;
    
    // Find min and max values
    while (current)
    {
        if (current->number < min)
            min = current->number;
        if (current->number > max)
            max = current->number;
        current = current->next;
    }
    
    int range = max - min;
    int chunk_size = (range / num_chunks) + 1; // Add 1 to handle division rounding
    int current_max = min + chunk_size;
    int rotations = 0;
    
    while ((*stack_a)->size > 0)
    {
        // Reset rotation counter when we start looking at a new chunk
        if (rotations >= (*stack_a)->size)
        {
            current_max += chunk_size;
            if (current_max > max)
                current_max = max + 1;  // Ensure we catch the maximum value
            rotations = 0;
        }

        if ((*stack_a)->head->number <= current_max)
        {
            pb(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size--;
            (*stack_b)->size++;
            // Only rotate in stack B if we have more than one element
            if ((*stack_b)->size > 1 && (*stack_b)->head->number < min + chunk_size/2)
                rb(&(*stack_b)->head);
            rotations = 0;  // Reset rotation counter after successful push
        }
        else
        {
            ra(&(*stack_a)->head);
            rotations++;
        }
    }
} */


/*
static void optimize_push_back(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_b)->size > 0)
    {
        int pos_b = find_max_position(*stack_b);
        smart_rotate(stack_b, pos_b, 'b');
        
        pa(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size++;
        (*stack_b)->size--;
    }
}
*/

static void push_efficient_chunks(t_stack **stack_a, t_stack **stack_b)
{
    int size = (*stack_a)->size;
    // Reduce number of chunks for better efficiency
    int num_chunks = (size <= 100) ? 5 : 11;
    
    int min = INT_MAX;
    int max = INT_MIN;
    t_list *current = (*stack_a)->head;
    
    while (current)
    {
        if (current->number < min)
            min = current->number;
        if (current->number > max)
            max = current->number;
        current = current->next;
    }
    
    int range = max - min;
    int chunk_size = (range / num_chunks) + 1; // TODO - Pourquoi + 1 ?
    int current_max = min + chunk_size;
    
    while ((*stack_a)->size > 0)
    {
        t_list *tmp = (*stack_a)->head;
        int closest_pos = -1;
        int pos = 0;
        
        while (tmp)
        {
            if (tmp->number <= current_max)
            {
                if (closest_pos == -1 || 
                    (pos <= (*stack_a)->size / 2 && pos < closest_pos) ||
                    (pos > (*stack_a)->size / 2 && ((*stack_a)->size - pos) < ((*stack_a)->size - closest_pos)))
                {
                    closest_pos = pos;
                }
            }
            pos++;
            tmp = tmp->next;
        }
        
        if (closest_pos == -1)
        {
            current_max += chunk_size;
            continue;
        }
        
        // Smart rotation to closest number
        if (closest_pos <= (*stack_a)->size / 2)
        {
            while (closest_pos-- > 0)
                ra(&(*stack_a)->head);
        }
        else
        {
            closest_pos = (*stack_a)->size - closest_pos;
            while (closest_pos-- > 0)
                rra(&(*stack_a)->head);
        }
        
        pb(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size--;
        (*stack_b)->size++;
        
        // Optimize B stack position for final sorting
        if ((*stack_b)->size > 1)
        {
            if ((*stack_b)->head->number < min + (range / 2))
                rb(&(*stack_b)->head);
        }
    }
}

static void optimize_push_back(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_b)->size > 0)
    {
        // Find the maximum number and its position
        t_list *tmp = (*stack_b)->head;
        int max = tmp->number;
        int max_pos = 0;
        int pos = 0;
        
        while (tmp)
        {
            if (tmp->number > max)
            {
                max = tmp->number;
                max_pos = pos;
            }
            pos++;
            tmp = tmp->next;
        }
        
        // Optimize rotation for maximum number
        if (max_pos <= (*stack_b)->size / 2)
        {
            while (max_pos-- > 0)
                rb(&(*stack_b)->head);
        }
        else
        {
            max_pos = (*stack_b)->size - max_pos;
            while (max_pos-- > 0)
                rrb(&(*stack_b)->head);
        }
        
        pa(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size++;
        (*stack_b)->size--;
    }
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
        if (!stack_a || !*stack_a || (*stack_a)->size <= 1 || is_sorted(*stack_a))
        return;

    if ((*stack_a)->size <= 3)
    {
        sort_small_stack(*stack_a);
        return;
    }
    
    if ((*stack_a)->size <= 5)
    {
        handle_small_stack(stack_a, stack_b);
        while ((*stack_b)->size > 0)
        {
            pa(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size++;
            (*stack_b)->size--;
        }
        return;
    }

    push_efficient_chunks(stack_a, stack_b);
    optimize_push_back(stack_a, stack_b);
}