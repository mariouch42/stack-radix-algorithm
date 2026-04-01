#include <stdio.h>
#include <stdlib.h>

// Definition dyal node
typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

// Function bach tkhlq node jadid
t_node *create_node(int data)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function bach tzid node f l'beginning
t_node *add_front(t_node *head, int data)
{
    t_node *new_node = create_node(data);
    if (!new_node)
        return head;
    new_node->next = head;
    return new_node;
}

// Function bach tzid node f la fin
void add_back(t_node **head, int data)
{
    t_node *new_node = create_node(data);
    if (!new_node)
        return;
    
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    t_node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

// Function bach tprint ga3 list
void print_list(t_node *head)
{
    printf("List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function bach t7aseb size dyal list
int list_size(t_node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Function bach t9leb 3la value
t_node *find_node(t_node *head, int value)
{
    while (head != NULL)
    {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

// Function bach tmsa7 node b value
t_node *delete_node(t_node *head, int value)
{
    if (head == NULL)
        return NULL;
    
    // Ila awl node hwa li bghina nmsa7oh
    if (head->data == value)
    {
        t_node *temp = head->next;
        free(head);
        return temp;
    }
    
    t_node *current = head;
    while (current->next != NULL && current->next->data != value)
        current = current->next;
    
    if (current->next != NULL)
    {
        t_node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    
    return head;
}

// Function bach tmsa7 ga3 list
void free_list(t_node *head)
{
    t_node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function - test ga3 functions
int main()
{
    t_node *head = NULL;
    
    printf("=== Linked List Test ===\n");
    
    // Zid nodes
    head = add_front(head, 10);
    head = add_front(head, 20);
    add_back(&head, 30);
    add_back(&head, 40);
    
    print_list(head);
    printf("Size: %d\n\n", list_size(head));
    
    // 9leb 3la value
    t_node *found = find_node(head, 30);
    if (found)
        printf("Found value 30!\n");
    else
        printf("Value 30 not found\n");
    
    // Msa7 node
    printf("\nDeleting value 20...\n");
    head = delete_node(head, 20);
    print_list(head);
    printf("Size: %d\n", list_size(head));
    
    // Msa7 ga3 list
    free_list(head);
    printf("\nList freed successfully!\n");
    
    return 0;
}
