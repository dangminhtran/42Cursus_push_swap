#include "push_swap.h"

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

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || (*stack_a)->size <= 1)
        return;

    if ((*stack_a)->size <= 3)
    {
        sort_small_stack(*stack_a);
        return;
    }

    while ((*stack_a)->size > 3)
    {
        int min_pos = find_min_position(*stack_a);
        
        // Rotate until minimum is at top
        while (min_pos > 0)
        {
            if (min_pos <= (*stack_a)->size / 2)
                ra(&(*stack_a)->head);
            else
                rra(&(*stack_a)->head);
            min_pos = find_min_position(*stack_a);
        }
        // Push minimum to stack B
        pb(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size--;
        (*stack_b)->size++;
    }

    sort_small_stack(*stack_a);

    // Push everything back to stack A
    while ((*stack_b)->size > 0)
    {
        pa(&(*stack_a)->head, &(*stack_b)->head);
        (*stack_a)->size++;
        (*stack_b)->size--;
    }
}

// AJOUT SE FONCTIONS
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
    int size = stack->size;
    int *arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;

    // Copy elements from stack to array
    t_list *current = stack->head;
    for (int i = 0; i < size; i++)
    {
        arr[i] = current->number;
        current = current->next;
    }

    // Sort the array using QuickSort or another efficient method
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

void sort_chunks(t_stack **stack_a, t_stack **stack_b, int num_chunks)
{
    int size = (*stack_a)->size;
    int *sorted_array = copy_and_sort_stack(*stack_a);
    int chunk_size = size / num_chunks;
    
    for (int i = 1; i <= num_chunks; i++)
    {
        int chunk_limit = sorted_array[i * chunk_size - 1];

        for (int j = 0; j < size; j++)
        {
            int num = (*stack_a)->head->number;
            if (num <= chunk_limit)
            {
                pb(&(*stack_a)->head, &(*stack_b)->head);
                (*stack_a)->size--;
                (*stack_b)->size++;
            }
            else
            {
                ra(&(*stack_a)->head);
            }
        }
    }

    while ((*stack_b)->size > 0)
        pa(&(*stack_a)->head, &(*stack_b)->head);
    
    free(sorted_array);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_num = get_max(*stack_a);
    int max_bits = 0;
    
    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        int size = (*stack_a)->size;
        for (int j = 0; j < size; j++)
        {
            int num = (*stack_a)->head->number;
            if ((num >> i) & 1)
                ra(&(*stack_a)->head);
            else
                pb(&(*stack_a)->head, &(*stack_b)->head);
        }
        while ((*stack_b)->size > 0)
            pa(&(*stack_a)->head, &(*stack_b)->head);
    }
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || (*stack_a)->size <= 1)
        return;

    if ((*stack_a)->size <= 3)
    {
        sort_small_stack(*stack_a);
        return;
    }

    if ((*stack_a)->size <= 5)
    {
        while ((*stack_a)->size > 3)
        {
            int min_pos = find_min_position(*stack_a);

            while (min_pos > 0)
            {
                if (min_pos <= (*stack_a)->size / 2)
                    ra(&(*stack_a)->head);
                else
                    rra(&(*stack_a)->head);
                min_pos = find_min_position(*stack_a);
            }
            
            pb(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size--;
            (*stack_b)->size++;
        }

        sort_small_stack(*stack_a);

        while ((*stack_b)->size > 0)
        {
            pa(&(*stack_a)->head, &(*stack_b)->head);
            (*stack_a)->size++;
            (*stack_b)->size--;
        }
        return;
    }

    if ((*stack_a)->size <= 100)
    {
        sort_chunks(stack_a, stack_b, 5);
        return;
    }
    
    radix_sort(stack_a, stack_b);
}
