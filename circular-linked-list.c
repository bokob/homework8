#include <stdio.h>
#include <stdlib.h>

typedef struct Node	// 구조체 Node 선언
{
	int key;			// int형 변수 key
	struct Node *llink;	// 구조체 Node에 대한 포인터 llink
	struct Node *rlink;	// 구조체 Node에 대한 포인터 rlink
} listNode;				// 선언한 구조체 Node를 listNode라 정의

int initialize(listNode **h);			// 리스트 초기화
int freeList(listNode *h);				// 리스트 해제
int insertLast(listNode *h, int key);	// 리스트의 맨 뒤에 입력받은 key를 지닌 노드 하나 추가
int deleteLast(listNode *h);			// 리스트의 맨 뒤에 있는 노드 하나 삭제
int insertFirst(listNode *h, int key);	// 리스트의 맨 앞에 입력받은 key를 지닌 노드 하나 추가
int deleteFirst(listNode *h);			// 리스트의 맨 앞에 있는 노드 하나 삭제
int invertList(listNode *h);			// 리스트를 역순으로 재배치
int insertNode(listNode *h, int key);	// 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int deleteNode(listNode *h, int key);	// 입력받은 key를 지닌 노드 삭제
void printList(listNode *h);			// 리스트의 내용 출력

int main()
{
	char command;	// 명령어를 입력받을 char형 변수 command
	int key;		// int형 변수 key
	listNode *headnode = NULL;
	int flag = 0; // initialize 함수를 사용했다는 것을 나타내줄 변수

	printf("[------------------- [복무창] [2021040021] -------------------]\n");

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
		scanf(" %c", &command);	// 명령어를 입력받는다.

		switch (command)
		{
		case 'z': case 'Z':
			initialize(&headnode);
			flag=1;	// initialize 함수 사용
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
				break;
			}
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			if(flag==0)	// initialize 함수를 사용하지 않았다면
			{
				printf("Please initialize.\n");	// initialize 함수를 사용하라는 문구 출력
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

int initialize(listNode **h) // 헤더 초기화
{
	if (*h != NULL)	  // h가 가리키는 곳에 NULL이 들어있지 않다면
		freeList(*h); // freeList를 호출해 h가 가리키는 곳이 가리키는 곳을 해제한다.

	*h = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 h가 가리키는 곳에 넣는다.
	(*h)->rlink = *h;
	// h가 가리키는 곳이 가리키는 곳의 rlink에 h가 가리키는 곳에 들어있는 주소를 넣는다.
	(*h)->llink = *h;
	// h가 가리키는 곳이 가리키는 곳의 llink에 h가 가리키는 곳에 들어있는 주소를 넣는다.
	(*h)->key = -9999;
	// h가 가리키는 곳이 가리키는 곳의 key를 -9999로 초기화한다.
	return 1;
}

int freeList(listNode *h) // 할당된 메모리 해제
{
	if(h->rlink == h)	// h가 가리키는 곳의 rlink가 h와 같다면
	{
		free(h);	// h를 해제한다.
		return 1;
	}

	listNode *p = h->rlink;
	// 메모리의 Stack 영역에 p를 만들고, h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.

	listNode *prev = NULL;
	// 메모리의 Stack 영역에 prev를 만들고, NULL을 넣는다.
	while (p != NULL && p != h) // p가 NULL이 아니면서 p가 h가 아닐 때까지 반복
	{
		prev = p;	  // p에 들어있는 주소를 prev에 넣는다.
		p = p->rlink; // p가 가리키는 곳의 rlink에 들어있는 주소를 p에 넣는다.
		free(prev);	  // prev를 해제한다.
	}
	free(h); // h를 해제한다.

	return 0;
}

void printList(listNode *h) // 리스트 출력
{
	int i = 0;
	listNode *p;
	// 메모리의 Stack 영역에 p를 만든다.

	printf("\n---PRINT\n");

	if (h == NULL) // h가 NULL을 가리킨다면
	{
		printf("Nothing to print....\n"); // 출력할 것이 없다는 문구 출력
		return;
	}

	p = h->rlink; // h가 가리키는 곳의 rlink에 들어있는 주소를 p에 넣는다.

	while (p != NULL && p != h) // p가 NULL이 아니면서 p가 h가 아닐 때까지 반복
	{
		printf("[ [%d]=%d ] ", i, p->key); // i번째 노드에 있는 key 값 출력
		p = p->rlink;					   // p가 가리키는 곳의 rlink에 들어있는 주소를 p에 넣는다.
		i++;							   // i 1 증가
	}
	printf("  items = %d\n", i);

	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);
	// h가 가리키는 곳의 llink, rlink에 들어있는 주소 출력

	i = 0;						// i 0으로 초기화
	p = h->rlink;				// h가 가리키는 곳의 rlink에 들어있는 주소를 p에 넣는다.
	while (p != NULL && p != h) // p가 NULL이 아니면서 p가 h가 아닐 때까지 반복
	{
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		// i번째 노드의 주소와 그 노드의 llink와 rlink에 들어있는 주소 출력
		p = p->rlink; // p가 가리키는 곳의 rlink에 들어있는 주소를 p에 넣는다.
		i++;		  // i 1증가
	}
}

int insertLast(listNode *h, int key) // list에 key에 대한 노드 하나 추가
{

	if (h == NULL) // h가 NULL이라면
		return -1;

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 크기 만큼의 공간을 만들고,
	// 그곳의 주소를 메모리의 Stack 영역에 있는 node에 넣는다.
	node->key = key;	// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->rlink = NULL; // node가 가리키는 곳의 rlink에 NULL을 넣는다.
	node->llink = NULL; // node가 가리니는 곳의 llink에 NULL을 넣는다.

	if (h->rlink == h) // h가 가리키는 곳의 rlink가 h를 가리키는 경우.
	// 즉, 자기 자신을 가리키는 경우. 노드가 없는 경우다.
	{
		h->rlink = node; // h가 가리키는 곳의 rlink에 node에 들어있는 주소를 넣는다.
		h->llink = node; // h가 가리키는 곳의 llink에 node에 들어있는 주소를 넣는다.
		node->rlink = h; // node가 가리키는 곳의 rlink에 h에 들어있는 주소를 넣는다.
		node->llink = h; // node가 가리키는 곳의 llink에 h에 들어있는 주소를 넣는다.
	}
	else // h가 가리키는 곳의 rlink가 h를 가리키지 않는 경우,
	// 즉, 다른 노드들이 존재하는 경우
	{
		h->llink->rlink = node;
		// h가 가리키는 곳의 llink가 가리키는 곳의 rlink에 node에 들어있는 주소르 넣는다.
		node->llink = h->llink;
		// node가 가리키는 곳의 llink에 h가 가리키는 곳의 llink에 들어있는 주소를 넣는다.
		h->llink = node;
		// h가 가리키는 곳의 llink에 node에 들어있는 주소를 넣는다.
		node->rlink = h;
		// node가 가리키는 곳의 rlink에 h에 들어있는 주소를 넣는다.
	}
	return 1;
}

int deleteLast(listNode *h) // list의 마지막 노드 삭제
{
	if (h->llink == h || h == NULL) // h가 가리키는 곳의 llink가 h와 같거나 h가 NULL이라면
	{
		printf("nothing to delete.\n"); // 삭제할 것이 없다는 문구 출력
		return 1;
	}

	listNode *nodetoremove = h->llink;
	// 메모리의 Stack 영역에 nodetoremove를 만들고, h가 가리키는 곳의 llink에 들어있는 주소를 넣는다.
	nodetoremove->llink->rlink = h;
	// nodetoremove가 가리키는 곳의 llink가 가리키는 곳의 rlink에 h에 들어있는 주소를 넣는다.
	h->llink = nodetoremove->llink;
	// h가 가리키는 곳의 llink에 nodetoremove가 가리키는 곳의 llink에 들어있는 주소를 넣는다.
	free(nodetoremove); // nodetoremove를 해제한다.

	return 1;
}

int insertFirst(listNode *h, int key) // list 처음에 key에 대한 노드하나를 추가
{
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 크기 만큼의 공간을 만들고,
	// 그곳의 주소를 메모리의 Stack 영역에 있는 node에 넣는다.
	node->key = key;	// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->rlink = NULL; // node가 가리키는 곳의 rlink에 NULL을 넣는다.
	node->llink = NULL; // node가 가리키는 곳의 llink에 NULL을 넣는다.

	node->rlink = h->rlink;
	// node가 가리키는 곳의 rlink에 h가 가리키는곳의 rlink에 들어있는 주소를 넣는다.
	h->rlink->llink = node;
	// h가 가리키는 곳의 rlink가 가리키는 곳의 llink에 node에 들어있는 주소를 넣는다.
	node->llink = h; // node가 가리키는 곳의 llink에 h에 들어있는 주소를 넣는다.
	h->rlink = node; // h가 가리키는 곳의 rlink에 node에 들어있는 주소를 넣는다.

	return 1;
}

int deleteFirst(listNode *h) // list의 첫번째 노드 삭제
{
	if (h == NULL || h->rlink == h) // h가 NULL이거나 h가 가리키는 곳의 rlink가 h라면
	{
		printf("nothing to delete.\n"); // 삭제할 것이 없다는 문구 출력
		return 0;
	}

	listNode *nodetoremove = h->rlink;
	// 메모리의 Stack 영역의 nodetoremove에 h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.

	nodetoremove->rlink->llink = h;
	// nodetoremove가 가리키는 곳의 rlink가 가리키는 곳의 llink에 h에 들어있는 주소를 넣는다.
	h->rlink = nodetoremove->rlink;
	// h가 가리키는 곳의 rlink에 nodetoremove가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	free(nodetoremove); // nodetoremove를 해제한다.

	return 1;
}

int invertList(listNode *h) // 리스트의 링크를 역순으로 재배치
{
	if (h->rlink == h || h == NULL) // h가 가리키는 곳의 rlink가 h거나 h가 NULL이라면
	{
		printf("nothing to invert...\n"); // 재배치할 것이 없다는 문구 출력
	}
	listNode *n = h->rlink;
	// 메모리의 Stack 영역에 n을 만들고 h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	listNode *trail = h;  // 메모리의 Stack 영역에 trail을 만들고 h에 들어있는 주소를 넣는다.
	listNode *middle = h; // 메모리의 Stack 영역에 middle을 만들고 h에 들어있는 주소를 넣는다.

	h->llink = h->rlink; // h가 가리키는 곳의 llink에 h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.

	while (n != NULL && n != h) // n이 NULL이 아니면서 n이 h가 아닐 때까지 반복
	{
		trail = middle; // trail에 middle에 들어있는 주소를 넣는다.
		middle = n;		// middle에 n에 들어있는 주소를 넣는다.
		n = n->rlink;	// n에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
		middle->rlink = trail;	// middle이 가리키는 곳의 rlink에 trail에 들어있는 주소를 넣는다.
		middle->llink = n;		// middle이 가리키는 곳의 llink에 n에 들어있는 주소를 넣는다.
	}
	h->rlink = middle; // h가 가리키는 곳의 rlink에 middle에 들어있는 주소를 넣는다.

	return 0;
}

int insertNode(listNode *h, int key) // 탐색 후, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
{
	if (h == NULL)	// h가 NULL이라면
		return -1;
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 크기 만큼의 공간을 만들고,
	// 그곳의 주소를 메모리의 Stack 영역의 node에 넣는다.
	node->key = key;	// node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->llink = node->rlink = NULL;	// node가 가리키는 곳의 llink와 rlink에 NULL을 넣는다.

	if (h->rlink == h)	// h가 가리키는 곳의 rlink가 h와 같다면
	{
		insertFirst(h, key);	// insertFirst 함수 호출
		return 1;
	}

	listNode *n = h->rlink;
	// 메모리의 Stack 영역에 n에 h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.

	while (n != NULL && n != h)	// n이 NULL이 아니고 n이 h가 아닐 때까지 반복
	{
		if (n->key >= key)	// n이 가리키는 곳의 key가 입력받은 key 이상이라면
		{
			if (n == h->rlink)			// n과 h가 가리키는 곳의 rlink가 같다면
			{
				insertFirst(h, key);	// insertFirst 함수 호출
			}
			else	// n과 h가 가리키는 곳의 rlink가 같디 않다면
			{
				node->rlink = n;		// node가 가리키는 곳의 rlink에 n에 들어있는 주소를 넣는다.
				node->llink = n->llink;	// node가 가리키는 곳의 llink에 n이 가리키는 곳의 llink를 넣는다.
				n->llink->rlink = node;	
				// n이 가리키는 곳의 llink가 가리키는 곳의 rlink에 node에 들어있는 주소를 넣는다.
				n->llink = node;	// n이 가리키는 곳의 llink에 node에 들어있는 주소를 넣는다.
			}
			return 0;
		}
		n = n->rlink;	// n에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	}

	// 마지막 노드까지 못찾은 경우 마지막에 삽입한다.
	insertLast(h, key);	// insertLast 함수 호출
	
	return 0;
}

int deleteNode(listNode *h, int key) // list에서 key에 대한 노드 삭제
{
	if (h->rlink == h || h == NULL)	// h가 가리키는 곳의 rlink가 h와 같거나 h가 NULL이라면
	{
		printf("nothing to delete.\n");	// 삭제할 것이 없다는 문구 출력
		return 0;
	}

	listNode *n = h->rlink; 
	// 메모리의 Stack 영역의 n에 h가 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	while (n != NULL && n != h)	// n이 NULL이 아니고 n이 h가 아닐 때까지 반복
	{
		if (n->key == key)	// n이 가리키는 곳의 key가 입력한 key와 같다면
		{
			if (n == h->rlink)	// n이 h가 가리키는 곳의 rlink와 같다면
			{
				deleteFirst(h);	// deleteFirst 함수 호출
			}
			else if (n->rlink == h)	// n이 가리키는 곳의 rlink가 h와 같다면
			{
				deleteLast(h);	// delteLast 함수 호출
			}
			else	// 중간에 있는 노드중에 삭제할 노드가 있는 경우
			{
				n->llink->rlink = n->rlink;	
				// n이 가리키는 곳의 llink가 가리키는 곳의 rlink에 
				// n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
				n->rlink->llink = n->llink;
				// n이 가리키는 곳의 rlink가 가리키는 곳의 llink에
				// n이 가리키는 곳의 llink에 들어있는 주소를 넣는다.
				free(n); // n을 해제한다.
			}
			return 0;
		}
		n = n->rlink; // n에 n이 가리키는 곳의 rlink에 들어있는 주소를 넣는다.
	}

	printf("cannot find the node for key = %d\n", key);
	// 입력받은 key를 지닌 노드를 찾을 수 없다는 문구 출력
	return 0;
}