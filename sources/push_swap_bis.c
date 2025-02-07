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