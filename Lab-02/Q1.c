#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 50000
#define START 1000
#define STEP 1000
#define END 50000
#define REPEAT 1000

/*
        DATA STRUCTURES
*/

/* Unsorted Array */
typedef struct
{
    int arr[MAXSIZE];
    int size;
} UnsortedArray;

/* Sorted Array */
typedef struct
{
    int arr[MAXSIZE];
    int size;
} SortedArray;

/* Singly Linked List */
typedef struct SNode
{
    int key;
    struct SNode *next;
} SNode;

/* Doubly Linked List */
typedef struct DNode
{
    int key;
    struct DNode *prev;
    struct DNode *next;
} DNode;

/*
        RANDOM DATA GENERATION
*/

void fillUnsortedArray(UnsortedArray *A, int n)
{
    A->size = n;

    for(int i=0;i<n;i++)
        A->arr[i]=rand();
}

void fillSortedArray(SortedArray *A,int n)
{
    A->size=n;

    int value=0;

    for(int i=0;i<n;i++)
    {
        value+=rand()%10+1;
        A->arr[i]=value;
    }
}

/*
        LINKED LIST CREATION
*/

SNode* createSNode(int key)
{
    SNode *temp=(SNode*)malloc(sizeof(SNode));

    temp->key=key;
    temp->next=NULL;

    return temp;
}

DNode* createDNode(int key)
{
    DNode *temp=(DNode*)malloc(sizeof(DNode));

    temp->key=key;
    temp->prev=NULL;
    temp->next=NULL;

    return temp;
}

SNode* buildUnsortedSLL(int n)
{
    SNode *head=NULL;

    for(int i=0;i<n;i++)
    {
        SNode *temp=createSNode(rand());

        temp->next=head;
        head=temp;
    }

    return head;
}

SNode* buildSortedSLL(int n)
{
    SNode *head=NULL;
    SNode *tail=NULL;

    int value=0;

    for(int i=0;i<n;i++)
    {
        value+=rand()%10+1;

        SNode *temp=createSNode(value);

        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    return head;
}
/*
        DOUBLY LINKED LIST CREATION
*/

DNode* buildUnsortedDLL(int n)
{
    DNode *head = NULL;

    for(int i = 0; i < n; i++)
    {
        DNode *temp = createDNode(rand());

        temp->next = head;

        if(head != NULL)
            head->prev = temp;

        head = temp;
    }

    return head;
}

DNode* buildSortedDLL(int n)
{
    DNode *head = NULL;
    DNode *tail = NULL;

    int value = 0;

    for(int i = 0; i < n; i++)
    {
        value += rand()%10 + 1;

        DNode *temp = createDNode(value);

        if(head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    return head;
}

/*
        MEMORY CLEANUP
*/

void freeSLL(SNode *head)
{
    while(head != NULL)
    {
        SNode *temp = head;
        head = head->next;
        free(temp);
    }
}

void freeDLL(DNode *head)
{
    while(head != NULL)
    {
        DNode *temp = head;
        head = head->next;
        free(temp);
    }
}

/*
        SEARCH OPERATIONS
        (First operation to benchmark)
*/

/* Unsorted Array : Linear Search */
int searchUnsortedArray(UnsortedArray *A, int key)
{
    for(int i = 0; i < A->size; i++)
    {
        if(A->arr[i] == key)
            return i;
    }

    return -1;
}

/* Sorted Array : Binary Search */
int searchSortedArray(SortedArray *A, int key)
{
    int low = 0;
    int high = A->size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(A->arr[mid] == key)
            return mid;

        if(A->arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/* Unsorted Singly Linked List : Linear Search */

SNode* searchUnsortedSLL(SNode *head, int key)
{
    while(head != NULL)
    {
        if(head->key == key)
            return head;

        head = head->next;
    }

    return NULL;
}
/*
        SEARCH IN SORTED SINGLY LINKED LIST
*/

SNode* searchSortedSLL(SNode *head, int key)
{
    while(head != NULL && head->key <= key)
    {
        if(head->key == key)
            return head;

        head = head->next;
    }

    return NULL;
}

/*
        SEARCH IN UNSORTED DOUBLY LINKED LIST
*/

DNode* searchUnsortedDLL(DNode *head, int key)
{
    while(head != NULL)
    {
        if(head->key == key)
            return head;

        head = head->next;
    }

    return NULL;
}

/*
        SEARCH IN SORTED DOUBLY LINKED LIST
*/

DNode* searchSortedDLL(DNode *head, int key)
{
    while(head != NULL && head->key <= key)
    {
        if(head->key == key)
            return head;

        head = head->next;
    }

    return NULL;
}

/*
                    MAIN PROGRAM
*/

int main()
{
    srand(time(NULL));

    FILE *fp = fopen("output.csv","w");

    if(fp == NULL)
    {
        printf("Unable to create output.csv\n");
        return 1;
    }

    fprintf(fp,
    "Size,UnsortedArray,SortedArray,"
    "UnsortedSLL,SortedSLL,"
    "UnsortedDLL,SortedDLL\n");

    for(int n = START; n <= END; n += STEP)
    {
        UnsortedArray ua;
        SortedArray sa;

        fillUnsortedArray(&ua, n);
        fillSortedArray(&sa, n);

        SNode *usll = buildUnsortedSLL(n);
        SNode *ssll = buildSortedSLL(n);

        DNode *udll = buildUnsortedDLL(n);
        DNode *sdll = buildSortedDLL(n);

        /* Worst-case search key */
        int key = -1;

        clock_t start, end;

        double tUA, tSA;
        double tUSLL, tSSLL;
        double tUDLL, tSDLL;

        /*
            Unsorted Array
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchUnsortedArray(&ua, key);

        end = clock();

        tUA = (double)(end-start)/CLOCKS_PER_SEC;

        /*
            Sorted Array
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchSortedArray(&sa, key);

        end = clock();

        tSA = (double)(end-start)/CLOCKS_PER_SEC;

        /*
            Unsorted Singly List
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchUnsortedSLL(usll, key);

        end = clock();

        tUSLL = (double)(end-start)/CLOCKS_PER_SEC;

        /*
            Sorted Singly List
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchSortedSLL(ssll, key);

        end = clock();

        tSSLL = (double)(end-start)/CLOCKS_PER_SEC;
        /*
            Unsorted Doubly List
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchUnsortedDLL(udll, key);

        end = clock();

        tUDLL = (double)(end-start)/CLOCKS_PER_SEC;

        /*
            Sorted Doubly List
        */

        start = clock();

        for(int i = 0; i < REPEAT; i++)
            searchSortedDLL(sdll, key);

        end = clock();

        tSDLL = (double)(end-start)/CLOCKS_PER_SEC;

        /*
            Save result to CSV
        */

        fprintf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf\n",
                n,
                tUA,
                tSA,
                tUSLL,
                tSSLL,
                tUDLL,
                tSDLL);

        printf("Completed for n = %d\n", n);

        freeSLL(usll);
        freeSLL(ssll);

        freeDLL(udll);
        freeDLL(sdll);
    }

    fclose(fp);

    printf("\nTiming data stored in output.csv\n");

    /*
            CREATE GNUPLOT SCRIPT
    */

    FILE *gp = fopen("plot.gp","w");

    if(gp==NULL)
    {
        printf("Unable to create plot.gp\n");
        return 1;
    }

    fprintf(gp,"set datafile separator ','\n");
    fprintf(gp,"set title 'Dictionary Search Operation'\n");
    fprintf(gp,"set xlabel 'Input Size (n)'\n");
    fprintf(gp,"set ylabel 'Execution Time (seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"set key outside\n");
    fprintf(gp,"set style data linespoints\n");

#ifdef _WIN32
    fprintf(gp,"set terminal windows\n");
#else
    fprintf(gp,"set terminal qt\n");
#endif
    // fprintf(gp, "set terminal png size 1000,800\n");
    // fprintf(gp, "set output 'dict.png'\n");
    fprintf(gp,
    "plot "
    "'output.csv' using 1:2 title 'Unsorted Array' lw 2 pt 7,\\\n");

    fprintf(gp,
    "'output.csv' using 1:3 title 'Sorted Array' lw 2 pt 5,\\\n");

    fprintf(gp,
    "'output.csv' using 1:4 title 'Unsorted SLL' lw 2 pt 9,\\\n");

    fprintf(gp,
    "'output.csv' using 1:5 title 'Sorted SLL' lw 2 pt 11,\\\n");

    fprintf(gp,
    "'output.csv' using 1:6 title 'Unsorted DLL' lw 2 pt 13,\\\n");

    fprintf(gp,
    "'output.csv' using 1:7 title 'Sorted DLL' lw 2 pt 15\n");

    fprintf(gp,"pause -1\n");

    fclose(gp);

    printf("Launching Gnuplot...\n");

    system("gnuplot plot.gp");

    printf("Done.\n");

    return 0;
}
