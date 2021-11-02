#include<stdio.h>
#include<stdlib.h>

/* to store a data (consisting of key and value) in hash table hashTable */
struct item
{
	int key;
	int value;
};

/* each hash table item has a flag (status) and data (consisting of key and value) */
struct hashtable_item
{

	int flag;
	/*
	 * flag = 0 : data does not exist
	 * flag = 1 : data exists
	 * flag = 2 : data existed at least once
	*/

	struct item* data;

};

struct hashtable_item* hashTable;
int size = 0;
int max = 10;

/* initializing hash table hashTable */
struct hashtable_item* init_hashTable()
{
	int i;
	struct hashtable_item* hashTable = (struct hashtable_item*)(malloc(max * sizeof(struct hashtable_item*)));
	for (i = 0; i < max; i++)
	{
		hashTable[i].flag = 0;
		hashTable[i].data = NULL;
	}
	return hashTable;
}

/* to every key, it will generate a corresponding index */
int hashcode(int key)
{
	return (key % max);
}

/* to insert an element in the hash table */
void insert(int key, int value)
{
	int index = hashcode(key);
	int i = index;

	/* creating new item to insert in the hash table hashTable */
	struct item* new_item = (struct item*)malloc(sizeof(struct item));
	new_item->key = key;
	new_item->value = value;

	/* probing through the hashTable until we reach an empty space */
	while (hashTable[i].flag == 1)
	{

		if (hashTable[i].data->key == key)
		{

			/* case where already existing key matches the given key */
			printf("\n Key already exists, hence updating its value \n");
			hashTable[i].data->value = value;
			return;

		}

		i = (i + 1) % max;
		if (i == index)
		{
			printf("\n Hash table is full, cannot insert any more item \n");
			return;
		}

	}

	hashTable[i].flag = 1;
	hashTable[i].data = new_item;
	size++;
	printf("\n Key (%d) has been inserted \n", key);

}


/* to remove an element from the hash table */
void remove_element(int key)
{
	int index = hashcode(key);
	int  i = index;

	/* probing through hashTable until we reach an empty space where not even once an element had been present */
	while (hashTable[i].flag != 0)
	{

		if (hashTable[i].flag == 1 && hashTable[i].data->key == key)
		{

			// case when data key matches the given key
			hashTable[i].flag = 2;
			hashTable[i].data = NULL;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;

		}
		i = (i + 1) % max;
		if (i == index)
		{
			break;
		}

	}

	printf("\n This key does not exist \n");

}

/* to display all the elements of hash table */
void display()
{
	int i;
	for (i = 0; i < max; i++)
	{
		struct item* current = (struct item*)hashTable[i].data;

		if (current == NULL)
		{
			printf("\n Array[%d] has no elements \n", i);
		}
		else
		{
			printf("\n Array[%d] has elements -: \n  %d (key) and %d(value) ", i, current->key, current->value);
		}
	}

}

int size_of_hashtable()
{
	return size;
}

int main()
{
	int choice, key, value, n, c;


	struct hashtable_item* hashTable = init_hashTable();

	do {
		printf("Implementation of Hash Table in C with Linear Probing \n\n");
		printf("MENU-: \n1.Inserting item in the Hashtable"
			"\n2.Removing item from the Hashtable"
			"\n3.Check the size of Hashtable"
			"\n4.Display Hashtable"
			"\n\n Please enter your choice-:");

		scanf("%d", &choice);

		switch (choice)
		{

		case 1:

			printf("Inserting element in Hashtable\n");
			printf("Enter key and value-:\t");
			scanf("%d %d", &key, &value);
			insert(key, value);

			break;

		case 2:

			printf("Deleting in Hashtable \n Enter the key to delete-:");
			scanf("%d", &key);
			remove_element(key);

			break;

		case 3:

			n = size_of_hashtable();
			printf("Size of Hashtable is-:%d\n", n);

			break;

		case 4:

			display();

			break;

		default:

			printf("Wrong Input\n");

		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	} while (c == 1);
	return 0;
}
