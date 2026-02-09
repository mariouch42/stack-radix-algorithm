


// Structure
typedef struct s_stack
{
    int             value;   // القيمة الأصلية
    int             index;   // الترتيب (0 إلى n-1)
    struct s_stack  *next;
}   t_stack;

// Main sorting function
void push_swap(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
    {
        index_stack(a);      // ← مهم!
        radix_sort(a, b);
    }
}


void push_swap(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    
    if (is_sorted(*a))
        return;
    
    // حالات خاصة للأعداد الصغيرة
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        radix_sort(a, b);  
		// للأعداد الكبيرة
}



// تحويل الأرقام لـ indices من 0 إلى n-1
void index_stack(t_stack **stack)
{
    t_stack *temp = *stack;
    int size = stack_size(*stack);
    
    while (temp)
    {
        int rank = 0;
        t_stack *compare = *stack;
        
        // احسب كم رقم أصغر من temp->value
        while (compare)
        {
            if (compare->value < temp->value)
                rank++;
            compare = compare->next;
        }
        
        temp->index = rank;  // هذا هو الترتيب
        temp = temp->next;
    }
}

/*


**مثال:**

Input:  [42, 7, 99, -3]
Indices: [2,  1,  3,  0]

الآن radix تشتغل على: [2, 1, 3, 0]
*/

void radix_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max_num = size - 1;
    int max_bits = 0;
    
    // Index الأرقام أولاً!
    index_stack(a);
    
    // احسب البتات
    while ((max_num >> max_bits) != 0)
        max_bits++;
    
    // لكل بت
    int i = 0;
    while (i < max_bits)
    {
        int j = 0;
        while (j < size)
        {
            int num = (*a)->index;  // ← استعمل index مش value!
            
            if (((num >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        
        // رجع من b لـ a
        while (*b)
            pa(a, b);
        
        i++;
    }
}