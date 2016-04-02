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
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *current1, *current2,*start,*prev,*temp;
	int len = 0;
	if (*head1 == NULL || *head2 == NULL)
	{
		return -1;
	}
	current1 = *head1;
	current2 = *head2;
	start = *head1;
	while (current1->next != *head1 &&current2->next != *head2)
	{
		if (current1->data <= current2->data)
		{
			if (current1->next->data >= current2->data)
			{
				prev = current1->next;
				current1->next = current2;
				temp = current2->next;
				current2->next = prev;
				current1 = current2;
				current2 = temp;
				len++;
			}
			else
			{
				current1 = current1->next;
				len++;
			}
	
		}
		else
		{
			temp = current2->next;
			current2->next = current1;
			current1 = current2;
			current2 = temp;
			start = current1;
			len++;
		}

	}
	while (current2->next != *head2)
	{
		current1->next = current2;
		current1 = current1->next;
		current2 = current2->next;
		if (current2->next == *head2)
			current1->next = start;
		len++;
	}


	*head1 = start;
	return len;
}