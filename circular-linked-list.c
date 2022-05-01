#include <stdio.h>
#include <stdlib.h>

typedef struct Node	// ����ü Node ����
{
	int key;			// int�� ���� key
	struct Node *llink;	// ����ü Node�� ���� ������ llink
	struct Node *rlink;	// ����ü Node�� ���� ������ rlink
} listNode;				// ������ ����ü Node�� listNode�� ����

int initialize(listNode **h);			// ����Ʈ �ʱ�ȭ
int freeList(listNode *h);				// ����Ʈ ����
int insertLast(listNode *h, int key);	// ����Ʈ�� �� �ڿ� �Է¹��� key�� ���� ��� �ϳ� �߰�
int deleteLast(listNode *h);			// ����Ʈ�� �� �ڿ� �ִ� ��� �ϳ� ����
int insertFirst(listNode *h, int key);	// ����Ʈ�� �� �տ� �Է¹��� key�� ���� ��� �ϳ� �߰�
int deleteFirst(listNode *h);			// ����Ʈ�� �� �տ� �ִ� ��� �ϳ� ����
int invertList(listNode *h);			// ����Ʈ�� �������� ���ġ
int insertNode(listNode *h, int key);	// �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ����
int deleteNode(listNode *h, int key);	// �Է¹��� key�� ���� ��� ����
void printList(listNode *h);			// ����Ʈ�� ���� ���

int main()
{
	char command;	// ��ɾ �Է¹��� char�� ���� command
	int key;		// int�� ���� key
	listNode *headnode = NULL;
	int flag = 0; // initialize �Լ��� ����ߴٴ� ���� ��Ÿ���� ����

	printf("[------------------- [����â] [2021040021] -------------------]\n");

	do
	{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	// ��ɾ �Է¹޴´�.

		switch (command)
		{
		case 'z': case 'Z':
			initialize(&headnode);
			flag=1;	// initialize �Լ� ���
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			if(flag==0)	// initialize �Լ��� ������� �ʾҴٸ�
			{
				printf("Please initialize.\n");	// initialize �Լ��� ����϶�� ���� ���
				break;
			}
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

int initialize(listNode **h) // ��� �ʱ�ȭ
{
	if (*h != NULL)	  // h�� ����Ű�� ���� NULL�� ������� �ʴٸ�
		freeList(*h); // freeList�� ȣ���� h�� ����Ű�� ���� ����Ű�� ���� �����Ѵ�.

	*h = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� h�� ����Ű�� ���� �ִ´�.
	(*h)->rlink = *h;
	// h�� ����Ű�� ���� ����Ű�� ���� rlink�� h�� ����Ű�� ���� ����ִ� �ּҸ� �ִ´�.
	(*h)->llink = *h;
	// h�� ����Ű�� ���� ����Ű�� ���� llink�� h�� ����Ű�� ���� ����ִ� �ּҸ� �ִ´�.
	(*h)->key = -9999;
	// h�� ����Ű�� ���� ����Ű�� ���� key�� -9999�� �ʱ�ȭ�Ѵ�.
	return 1;
}

int freeList(listNode *h) // �Ҵ�� �޸� ����
{
	if(h->rlink == h)	// h�� ����Ű�� ���� rlink�� h�� ���ٸ�
	{
		free(h);	// h�� �����Ѵ�.
		return 1;
	}

	listNode *p = h->rlink;
	// �޸��� Stack ������ p�� �����, h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.

	listNode *prev = NULL;
	// �޸��� Stack ������ prev�� �����, NULL�� �ִ´�.
	while (p != NULL && p != h) // p�� NULL�� �ƴϸ鼭 p�� h�� �ƴ� ������ �ݺ�
	{
		prev = p;	  // p�� ����ִ� �ּҸ� prev�� �ִ´�.
		p = p->rlink; // p�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� p�� �ִ´�.
		free(prev);	  // prev�� �����Ѵ�.
	}
	free(h); // h�� �����Ѵ�.

	return 0;
}

void printList(listNode *h) // ����Ʈ ���
{
	int i = 0;
	listNode *p;
	// �޸��� Stack ������ p�� �����.

	printf("\n---PRINT\n");

	if (h == NULL) // h�� NULL�� ����Ų�ٸ�
	{
		printf("Nothing to print....\n"); // ����� ���� ���ٴ� ���� ���
		return;
	}

	p = h->rlink; // h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� p�� �ִ´�.

	while (p != NULL && p != h) // p�� NULL�� �ƴϸ鼭 p�� h�� �ƴ� ������ �ݺ�
	{
		printf("[ [%d]=%d ] ", i, p->key); // i��° ��忡 �ִ� key �� ���
		p = p->rlink;					   // p�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� p�� �ִ´�.
		i++;							   // i 1 ����
	}
	printf("  items = %d\n", i);

	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);
	// h�� ����Ű�� ���� llink, rlink�� ����ִ� �ּ� ���

	i = 0;						// i 0���� �ʱ�ȭ
	p = h->rlink;				// h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� p�� �ִ´�.
	while (p != NULL && p != h) // p�� NULL�� �ƴϸ鼭 p�� h�� �ƴ� ������ �ݺ�
	{
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		// i��° ����� �ּҿ� �� ����� llink�� rlink�� ����ִ� �ּ� ���
		p = p->rlink; // p�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� p�� �ִ´�.
		i++;		  // i 1����
	}
}

int insertLast(listNode *h, int key) // list�� key�� ���� ��� �ϳ� �߰�
{

	if (h == NULL) // h�� NULL�̶��
		return -1;

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ũ�� ��ŭ�� ������ �����,
	// �װ��� �ּҸ� �޸��� Stack ������ �ִ� node�� �ִ´�.
	node->key = key;	// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->rlink = NULL; // node�� ����Ű�� ���� rlink�� NULL�� �ִ´�.
	node->llink = NULL; // node�� �����ϴ� ���� llink�� NULL�� �ִ´�.

	if (h->rlink == h) // h�� ����Ű�� ���� rlink�� h�� ����Ű�� ���.
	// ��, �ڱ� �ڽ��� ����Ű�� ���. ��尡 ���� ����.
	{
		h->rlink = node; // h�� ����Ű�� ���� rlink�� node�� ����ִ� �ּҸ� �ִ´�.
		h->llink = node; // h�� ����Ű�� ���� llink�� node�� ����ִ� �ּҸ� �ִ´�.
		node->rlink = h; // node�� ����Ű�� ���� rlink�� h�� ����ִ� �ּҸ� �ִ´�.
		node->llink = h; // node�� ����Ű�� ���� llink�� h�� ����ִ� �ּҸ� �ִ´�.
	}
	else // h�� ����Ű�� ���� rlink�� h�� ����Ű�� �ʴ� ���,
	// ��, �ٸ� ������ �����ϴ� ���
	{
		h->llink->rlink = node;
		// h�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� node�� ����ִ� �ּҸ� �ִ´�.
		node->llink = h->llink;
		// node�� ����Ű�� ���� llink�� h�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
		h->llink = node;
		// h�� ����Ű�� ���� llink�� node�� ����ִ� �ּҸ� �ִ´�.
		node->rlink = h;
		// node�� ����Ű�� ���� rlink�� h�� ����ִ� �ּҸ� �ִ´�.
	}
	return 1;
}

int deleteLast(listNode *h) // list�� ������ ��� ����
{
	if (h->llink == h || h == NULL) // h�� ����Ű�� ���� llink�� h�� ���ų� h�� NULL�̶��
	{
		printf("nothing to delete.\n"); // ������ ���� ���ٴ� ���� ���
		return 1;
	}

	listNode *nodetoremove = h->llink;
	// �޸��� Stack ������ nodetoremove�� �����, h�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
	nodetoremove->llink->rlink = h;
	// nodetoremove�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� h�� ����ִ� �ּҸ� �ִ´�.
	h->llink = nodetoremove->llink;
	// h�� ����Ű�� ���� llink�� nodetoremove�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
	free(nodetoremove); // nodetoremove�� �����Ѵ�.

	return 1;
}

int insertFirst(listNode *h, int key) // list ó���� key�� ���� ����ϳ��� �߰�
{
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ũ�� ��ŭ�� ������ �����,
	// �װ��� �ּҸ� �޸��� Stack ������ �ִ� node�� �ִ´�.
	node->key = key;	// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->rlink = NULL; // node�� ����Ű�� ���� rlink�� NULL�� �ִ´�.
	node->llink = NULL; // node�� ����Ű�� ���� llink�� NULL�� �ִ´�.

	node->rlink = h->rlink;
	// node�� ����Ű�� ���� rlink�� h�� ����Ű�°��� rlink�� ����ִ� �ּҸ� �ִ´�.
	h->rlink->llink = node;
	// h�� ����Ű�� ���� rlink�� ����Ű�� ���� llink�� node�� ����ִ� �ּҸ� �ִ´�.
	node->llink = h; // node�� ����Ű�� ���� llink�� h�� ����ִ� �ּҸ� �ִ´�.
	h->rlink = node; // h�� ����Ű�� ���� rlink�� node�� ����ִ� �ּҸ� �ִ´�.

	return 1;
}

int deleteFirst(listNode *h) // list�� ù��° ��� ����
{
	if (h == NULL || h->rlink == h) // h�� NULL�̰ų� h�� ����Ű�� ���� rlink�� h���
	{
		printf("nothing to delete.\n"); // ������ ���� ���ٴ� ���� ���
		return 0;
	}

	listNode *nodetoremove = h->rlink;
	// �޸��� Stack ������ nodetoremove�� h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.

	nodetoremove->rlink->llink = h;
	// nodetoremove�� ����Ű�� ���� rlink�� ����Ű�� ���� llink�� h�� ����ִ� �ּҸ� �ִ´�.
	h->rlink = nodetoremove->rlink;
	// h�� ����Ű�� ���� rlink�� nodetoremove�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	free(nodetoremove); // nodetoremove�� �����Ѵ�.

	return 1;
}

int invertList(listNode *h) // ����Ʈ�� ��ũ�� �������� ���ġ
{
	if (h->rlink == h || h == NULL) // h�� ����Ű�� ���� rlink�� h�ų� h�� NULL�̶��
	{
		printf("nothing to invert...\n"); // ���ġ�� ���� ���ٴ� ���� ���
	}
	listNode *n = h->rlink;
	// �޸��� Stack ������ n�� ����� h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	listNode *trail = h;  // �޸��� Stack ������ trail�� ����� h�� ����ִ� �ּҸ� �ִ´�.
	listNode *middle = h; // �޸��� Stack ������ middle�� ����� h�� ����ִ� �ּҸ� �ִ´�.

	h->llink = h->rlink; // h�� ����Ű�� ���� llink�� h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.

	while (n != NULL && n != h) // n�� NULL�� �ƴϸ鼭 n�� h�� �ƴ� ������ �ݺ�
	{
		trail = middle; // trail�� middle�� ����ִ� �ּҸ� �ִ´�.
		middle = n;		// middle�� n�� ����ִ� �ּҸ� �ִ´�.
		n = n->rlink;	// n�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
		middle->rlink = trail;	// middle�� ����Ű�� ���� rlink�� trail�� ����ִ� �ּҸ� �ִ´�.
		middle->llink = n;		// middle�� ����Ű�� ���� llink�� n�� ����ִ� �ּҸ� �ִ´�.
	}
	h->rlink = middle; // h�� ����Ű�� ���� rlink�� middle�� ����ִ� �ּҸ� �ִ´�.

	return 0;
}

int insertNode(listNode *h, int key) // Ž�� ��, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ����
{
	if (h == NULL)	// h�� NULL�̶��
		return -1;
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ũ�� ��ŭ�� ������ �����,
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �ִ´�.
	node->key = key;	// node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->llink = node->rlink = NULL;	// node�� ����Ű�� ���� llink�� rlink�� NULL�� �ִ´�.

	if (h->rlink == h)	// h�� ����Ű�� ���� rlink�� h�� ���ٸ�
	{
		insertFirst(h, key);	// insertFirst �Լ� ȣ��
		return 1;
	}

	listNode *n = h->rlink;
	// �޸��� Stack ������ n�� h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.

	while (n != NULL && n != h)	// n�� NULL�� �ƴϰ� n�� h�� �ƴ� ������ �ݺ�
	{
		if (n->key >= key)	// n�� ����Ű�� ���� key�� �Է¹��� key �̻��̶��
		{
			if (n == h->rlink)			// n�� h�� ����Ű�� ���� rlink�� ���ٸ�
			{
				insertFirst(h, key);	// insertFirst �Լ� ȣ��
			}
			else	// n�� h�� ����Ű�� ���� rlink�� ���� �ʴٸ�
			{
				node->rlink = n;		// node�� ����Ű�� ���� rlink�� n�� ����ִ� �ּҸ� �ִ´�.
				node->llink = n->llink;	// node�� ����Ű�� ���� llink�� n�� ����Ű�� ���� llink�� �ִ´�.
				n->llink->rlink = node;	
				// n�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� node�� ����ִ� �ּҸ� �ִ´�.
				n->llink = node;	// n�� ����Ű�� ���� llink�� node�� ����ִ� �ּҸ� �ִ´�.
			}
			return 0;
		}
		n = n->rlink;	// n�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	}

	// ������ ������ ��ã�� ��� �������� �����Ѵ�.
	insertLast(h, key);	// insertLast �Լ� ȣ��
	
	return 0;
}

int deleteNode(listNode *h, int key) // list���� key�� ���� ��� ����
{
	if (h->rlink == h || h == NULL)	// h�� ����Ű�� ���� rlink�� h�� ���ų� h�� NULL�̶��
	{
		printf("nothing to delete.\n");	// ������ ���� ���ٴ� ���� ���
		return 0;
	}

	listNode *n = h->rlink; 
	// �޸��� Stack ������ n�� h�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	while (n != NULL && n != h)	// n�� NULL�� �ƴϰ� n�� h�� �ƴ� ������ �ݺ�
	{
		if (n->key == key)	// n�� ����Ű�� ���� key�� �Է��� key�� ���ٸ�
		{
			if (n == h->rlink)	// n�� h�� ����Ű�� ���� rlink�� ���ٸ�
			{
				deleteFirst(h);	// deleteFirst �Լ� ȣ��
			}
			else if (n->rlink == h)	// n�� ����Ű�� ���� rlink�� h�� ���ٸ�
			{
				deleteLast(h);	// delteLast �Լ� ȣ��
			}
			else	// �߰��� �ִ� ����߿� ������ ��尡 �ִ� ���
			{
				n->llink->rlink = n->rlink;	
				// n�� ����Ű�� ���� llink�� ����Ű�� ���� rlink�� 
				// n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
				n->rlink->llink = n->llink;
				// n�� ����Ű�� ���� rlink�� ����Ű�� ���� llink��
				// n�� ����Ű�� ���� llink�� ����ִ� �ּҸ� �ִ´�.
				free(n); // n�� �����Ѵ�.
			}
			return 0;
		}
		n = n->rlink; // n�� n�� ����Ű�� ���� rlink�� ����ִ� �ּҸ� �ִ´�.
	}

	printf("cannot find the node for key = %d\n", key);
	// �Է¹��� key�� ���� ��带 ã�� �� ���ٴ� ���� ���
	return 0;
}