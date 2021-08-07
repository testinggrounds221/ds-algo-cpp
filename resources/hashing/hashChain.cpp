// https://www.log2base2.com/algorithms/searching/open-hashing.html
#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node
{
	int data;
	struct node* next;
};

struct node* chain[size];

void init()
{
	int i;
	for (i = 0; i < size; i++)
		chain[i] = NULL;
}

void insert(int value)
{
	//create a newnode with value
	struct node* newNode = new struct node;
	newNode->data = value;
	newNode->next = NULL;

	//calculate hash key
	int key = value % size;

	//check if chain[key] is empty
	if (chain[key] == NULL)
		chain[key] = newNode;
	//collision
	else
	{
		//add the node at the end of chain[key].
		struct node* temp = chain[key];
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

/*
 * return 1, successful delete
 * return 0, value not found
 */
int del(int value)
{
	int key = value % size;
	struct node* temp = chain[key], * dealloc;
	if (temp != NULL)
	{
		if (temp->data == value)
		{
			dealloc = temp;
			temp = temp->next;
			free(dealloc);
			return 1;
		}
		else
		{
			while (temp->next)
			{
				if (temp->next->data == value)
				{
					dealloc = temp->next;
					temp->next = temp->next->next;
					free(dealloc);
					return 1;
				}
				temp = temp->next;
			}
		}
	}

	return 0;
}

void print()
{
	int i;

	for (i = 0; i < size; i++)
	{
		struct node* temp = chain[i];
		printf("chain[%d]-->", i);
		while (temp)
		{
			printf("%d -->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	//init array of list to NULL
	init();

	// insert(7);
	// insert(0);
	// insert(3);
	// insert(10);
	// insert(4);
	// insert(5);
	// insert(20);
	// insert(33);
	for (int i = 0;i < 10;i++) {
		insert(i);
	}
	del(1);
	print();
	// print();

	// if (del(33))
	// {
	// 	printf("After Deletion of 33\n");
	// 	print();
	// }
	// else
	// 	printf("Value Not Present\n");
	// printf("%d", del(33));
	// return 0;
}