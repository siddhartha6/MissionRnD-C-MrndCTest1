/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

struct node *insert(struct node* head_ref, int new_data)
{
	/* 1. allocate node */
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	struct node *last = head_ref;  /* used in step 5*/

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so make next
	of it as NULL*/
	new_node->next = head_ref;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (head_ref == NULL)
	{
		head_ref = new_node;
		return head_ref;
	}

	/* 5. Else traverse till the last node */
	while (last->next != head_ref)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return head_ref;
}
int merge_circularlists(struct node **head1, struct node **head2) {

	if (*head1 == NULL && *head2 == NULL)
		return -1;
	struct node *result = NULL;
	struct node *x = *head1;
	struct node *y = *head2;
	int len = 0;
	while (x->next != *head1 && y->next != *head2) {
		if (x->data < x->data)
		{
			result = insert(result, x->data);
			x = x->next;
		}
		else if (x->data > x->data)
		{
			result = insert(result, y->data);
			y = y->next;
		}
		else
		{
			result = insert(result, x->data);
			result = insert(result, y->data);
			x = x->next;
			y = y->next;
		}
	}
	while (x != *head1)
	{
		result = insert(result, x->data);
		x = x->next;
	}
	while (y != *head2)
	{
		result = insert(result, y->data);
		y = y->next;
	}
	*head1 = result;
	struct node *temp = result;
	while (temp->next != result){
		temp = temp->next;
		len++;
	}
	return len + 1;
}