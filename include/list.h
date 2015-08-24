#ifndef LIST_H
#define LIST_H

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                  \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct _IList IList;
typedef struct _ArrayList ArrayList;
typedef struct _LinkedList LinkedList;
typedef struct _Node Node;

struct _IList
{
	void (*push)(struct _IList *list, int elem);
	int (*pop)(struct _IList *list);
};

struct _ArrayList
{
	int *_data;
	size_t _capacity;
	size_t _size;
	IList list;
};

struct _Node
{
	int value;
	struct _Node *next;
};

struct _LinkedList
{
	struct _Node *head;
	IList list;
};

extern ArrayList* newArrayList(size_t size);
extern void deleteArrayList(ArrayList *arrayList);
extern LinkedList* newLinkedList();
extern void deleteLinkedList(LinkedList *linkedList);

#endif