#include <stdio.h>

#define MAX_NODE 10000
#define MAX_TABLE 2048

typedef struct listNode
{
	int data;
	struct listNode* prev;
	struct listNode* next;
	struct listNode* child;
	struct listNode* parent;
} ListNode;

typedef struct hashNode
{
	int key;
	ListNode* listnode;
	struct hashNode* next;
} HashNode;

typedef struct
{
	int use;
	ListNode node;
} ListNodeHeap;

typedef struct
{
	int use;
	HashNode node;
} HashNodeHeap;

ListNodeHeap heap[MAX_NODE];
HashNodeHeap hashheap[MAX_NODE];
HashNode* table[MAX_TABLE];

void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;
		hashheap[i].use = 0;
	}
	for (i=0; i<MAX_TABLE; i++) table[i] = 0;
}

void initListNode(ListNode* node)
{
	node->data = 0;
	node->prev = node;
	node->next = node;
	node->child = 0;
	node->parent = 0;
}

void initHashNode(HashNode* node)
{
	node->key = 0;
	node->listnode = 0;
	node->next = 0;
}

ListNode* getListNode(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)
		{
			heap[i].use = 1;
			initListNode(&heap[i].node);
			return &heap[i].node;
		}
	}
	return 0;
}

HashNode* getHashNode(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!hashheap[i].use)
		{
			hashheap[i].use = 1;
			initHashNode(&hashheap[i].node);
			return &hashheap[i].node;
		}
	}
	return 0;
}

void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}

void destroyHashNode(HashNode* node)
{
	HashNodeHeap* heap_node = (HashNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}

int hash_calc(int key) {
	return key % (MAX_TABLE-1);
}

ListNode* hash_find(int key) {
	int h = hash_calc(key);
	HashNode* cur = table[h];
	while(cur != 0) {
		if (cur->key == key) return cur->listnode;
		cur = cur->next;
	}
	return 0;
}

void hash_add(int key, ListNode* node) {
	int h = hash_calc(key);
	HashNode* cur = table[h];
	HashNode* ni = getHashNode();
	ni->key = key;
	ni->listnode = node;
	if (cur == 0) {
		table[h] = ni;
		return;
	}
	while (cur != 0) {
		if (cur->next == 0) {
			cur->next = ni;
			return;
		}
		cur = cur->next;
	}
	return;
}

void hash_delete(int key) {
	int h = hash_calc(key);
	HashNode* cur = table[h];
	HashNode* prev = table[h];
	if (cur->key == key) {
		table[h] = cur->next;
		destroyHashNode(cur);
		return;
	}
	cur = cur->next;
	while(cur != 0) {
		if (cur->key == key) {
			prev->next = cur->next;
			destroyHashNode(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	return;
}

ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();
	node->data = data;
	hash_add(data, node);
	if (list == 0)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev;
		last->next = node;
		list->prev = node;
		node->prev = last;
		node->next = list;
		node->parent = last->parent;
		return list;
	}
}

ListNode* removeListNode(ListNode* list, ListNode* node)
{
	hash_delete(node->data);
	if (list == list->next)
	{
		destroyListNode(node);
		return NULL;
	}
	else
	{
		ListNode* prev = node->prev;
		ListNode* next = node->next;
		prev->next = next;
		next->prev = prev;
		destroyListNode(node);
		return (list == node) ? next : list;
	}
}

void node_add(int cid, int pid) {
	ListNode* pptr = hash_find(pid);
	pptr->child = appendListNode(pptr->child,cid);
	pptr->child->parent = pptr;
}

ListNode* node_detach(ListNode* list, ListNode* node) {

	if (list == list->next)
	{
		return 0;
	}
	else
	{
		ListNode* prev = node->prev;
		ListNode* next = node->next;
		prev->next = next;
		next->prev = prev;
		node->next = node;
		node->prev = node;
		return (list == node) ? next : list;
	}
}

ListNode* node_attach(ListNode* list, ListNode* node) {

	if (list == 0)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev;
		last->next = node;
		list->prev = node;
		node->prev = last;
		node->next = list;
		node->parent = last->parent;
		return list;
	}
}

void node_move(int cid, int pid) {
	ListNode* cptr = hash_find(cid);
	ListNode* pptr = hash_find(pid);
	cptr->parent->child = node_detach(cptr->parent->child,cptr);
	pptr->child = node_attach(pptr->child,cptr);
	pptr->child->parent = pptr;
}

void node_free(ListNode* node, int top) {
	if (node->child != 0) {
		node_free(node->child,0);
		node->child = 0;
	}
	if (top != 1 && node->parent != 0 && node->parent->child == node) {
		ListNode* cur = node->next;
		while (cur != node) {
			node_free(cur,0);
			cur = cur->next;
		}
	}
	if(node->child == 0) {
		node->parent->child = removeListNode(node->parent->child, node);
	}
}

void node_remove(int cid) {
	ListNode* cptr = hash_find(cid);
	node_free(cptr,1);
}

void printList(ListNode* node) {
	printf("%d ",node->data);
	if (node->child != 0) printList(node->child);
	if (node->parent != 0 && node->parent->child == node) {
		ListNode* cur = node->next;
		while(cur != node) {
			printList(cur);
			cur = cur->next;
		}
	}
}

int main(void) {
	freopen("input.txt","r",stdin);
	int command, pid, cid;
	initHeap();
	ListNode* root = 0;
	root = appendListNode(root,1);
	while(1) {
		scanf("%d",&command);
		switch(command) {
		case 1:
			scanf("%d %d",&cid, &pid);
			node_add(cid, pid);
			break;
		case 2:
			scanf("%d %d",&cid, &pid);
			node_move(cid, pid);
			break;
		case 3:
			printList(root);
			printf("\n");
			break;
		case 4:
			scanf("%d", &cid);
			node_remove(cid);
			break;
		}
		if (command == 5) break;
	}
	return 0;
}
