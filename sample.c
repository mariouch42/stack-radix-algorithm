#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

// دالة لطباعة المكدس
void print_stack(t_stack *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// دالة إضافة عنصر للمكدس
void push(t_stack **stack, int value)
{
    t_stack *new = malloc(sizeof(t_stack));
    new->value = value;
    new->next = *stack;
    *stack = new;
}

// دالة حساب حجم المكدس
int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

// عملية ra: دوّر a (العنصر العلوي يصبح في الأسفل)
void ra(t_stack **a)
{
    if (!*a || !(*a)->next)
        return;
    
    t_stack *first = *a;
    t_stack *last = *a;
    
    // ابحث عن آخر عنصر
    while (last->next)
        last = last->next;
    
    *a = first->next;     // الثاني يصبح الأول
    first->next = NULL;
    last->next = first;   // الأول يصبح الأخير
    
    printf("ra\n");
}

// عملية pb: انقل من a إلى b
void pb(t_stack **a, t_stack **b)
{
    if (!*a)
        return;
    
    t_stack *temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    
    printf("pb\n");
}

// عملية pa: انقل من b إلى a
void pa(t_stack **a, t_stack **b)
{
    if (!*b)
        return;
    
    t_stack *temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    
    printf("pa\n");
}

// خوارزمية Radix Sort
void radix_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max_num = size - 1;
    int max_bits = 0;
    
    // احسب عدد البتات
    while ((max_num >> max_bits) != 0)
        max_bits++;
    
    printf("Size: %d, Max bits: %d\n\n", size, max_bits);
    
    // لكل بت
    int i = 0;
    while (i < max_bits)
    {
        printf("=== Bit %d ===\n", i);
        
        int j = 0;
        while (j < size)
        {
            int num = (*a)->value;
            
            // افحص البت رقم i
            if (((num >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            
            j++;
        }
        
        print_stack(*a, 'A');
        print_stack(*b, 'B');
        
        // أعد كل شيء من b إلى a
        while (*b)
            pa(a, b);
        
        printf("After moving back:\n");
        print_stack(*a, 'A');
        printf("\n");
        
        i++;
    }
}

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    
    // أضف الأرقام (من 0 إلى 7) بترتيب عشوائي
    push(&a, 0);
    push(&a, 2);
    push(&a, 1);
    push(&a, 3);
    
    printf("Initial stack:\n");
    print_stack(a, 'A');
    printf("\n");
    
    radix_sort(&a, &b);
    
    printf("Final sorted stack:\n");
    print_stack(a, 'A');
    
    return 0;
}
/*
## 7) تشغيل المثال



Initial stack:
Stack A: 3 1 2 0 

Size: 4, Max bits: 2

=== Bit 0 ===
pb
ra
pb
ra
Stack A: 3 1 
Stack B: 2 0 
After moving back:
Stack A: 2 0 3 1 

=== Bit 1 ===
ra
pb
ra
pb
Stack A: 2 3 
Stack B: 0 1 
After moving back:
Stack A: 0 1 2 3 

Final sorted stack:
Stack A: 0 1 2 3
*/
