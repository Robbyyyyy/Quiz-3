#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
#define MAX_STACK 50

struct STACK
{
    char top;
    char data[50][50];
}tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

int IsFull()
{
    if(tumpuk.top == MAX_STACK) return 1; else return 0;
}

int IsEmpty()
{
    if (tumpuk.top == -1) return 1; else return 0;
}

void Push(char item[MAX_STACK])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top],item);
}


void Pop()
{
    printf("Data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void Clear()
{
    tumpuk.top=-1;
}

void TampilStack()
{
    for(int i=tumpuk.top; i>=0; i--)
    {printf("Data Stack ke %d: %s\n", i, tumpuk.data[i]);}
}

struct antrian{
    int front;
    int rear;
    int data[MAX];
}q;

void inisialisasi2()
{
    q.front = -1;
    q.rear = -1;
}

int IsFull2()
{
    if(q.rear==MAX-1) return 1;
    else return 0;
}

void enqueue(int item)
{
    fflush(stdin);
    if(isEmpty()==1){
        q.front=q.rear=0;
        q.data[q.rear]=item;
        printf("%d masuk\n", q.data[q.rear]);
    }
    else{
        if(IsFull()==0){
            q.rear++;
            q.data[q.rear]=item;
            printf("%d masuk\n", q.data[q.rear]);
        }
    }
}

int isEmpty()
{
    if(q.rear==-1) return 1;
    else
        return 0;
}

void Dequeue()
{
    int i;
    int e = q.data[q.front];
    printf("Data yang keluar : %d", e);
    for(i=q.front; i<=q.rear-1; i++)
    {
        q.data[i] = q.data[i+1];
    }
    q.rear--;
}

void Clear2()
{
    q.front = -1;
    q.rear = -1;
    printf("Data sudah dibersihkan!");
}

void TampilQueue()
{
    if(isEmpty()==0)
    {
        for(int i=q.front; i<=q.rear; i++)
        {
            printf("data ke %d = %d\n", i, q.data[i]);
        }
    }
    else printf("data kosong!\n");
}

void print_menu(char head[100], char menu[10][100], int jumlah, int pilihan)
{
    fflush(stdin);
    printf("\n\n===========================\n");
    printf("%s\n", head);
    printf("===========================\n");
    int i;
    for (i = 1; i <= jumlah; i++)
    {
        if (pilihan == i)
        {
            printf("==> ");
        }
        else
        {
            printf("    ");
        }
        printf("%d. %s \n", i, menu[i - 1]);
    }
    printf("===========================\n");
}

void main()
{
    fflush(stdin);
    system("COLOR F8");
    int pil = 1;
    char menu[3][100] = {"Stack String", "Queue Integer", "Exit Program"};
    int jumlah = 3;
    char j;
    while (1)
    {
        system("cls");
        print_menu("Tugas Quiz Stack and Queue", menu, jumlah, pil);
        j = getch();
        if(j == 72)
        {
            if (pil > 1)
            {
                pil--;
            }
        }
        else if (j == 80)
        {
            if (pil < 5)
            {
                pil++;
            }
        }
        else if (j == 13)
        {
            if (pil == 1)
            {
                stackstring();
            }
            else if (pil == 2)
            {
                quequestring();
            }
            else
            {
                system("cls");
                printf("TERIMA KASIH ~ GOODLUCK");
                exit(0);
                return 1;
            }
        }
    }

    return 0;
}

void stackstring()
{
    fflush(stdin);
    int pil;
    char item[50];
    inisialisasi();
    do{
        system("cls");
        fflush (stdin);
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Print Stack\n");
        printf("4. Delete Stack\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan : ");
        scanf("%d",&pil);
        fflush (stdin);
        switch(pil)
        {
            case 1: { system("cls");
            fflush(stdin);
            if(IsFull()!=1)
            {   printf("Data yang ingin diinput = "); scanf(" %[^\n]%*c", &item);
                Push(item);

            }
            else printf("\nSudah Penuh\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 2: { system("cls");
            fflush(stdin);
            if(IsEmpty()!=1)
            {Pop();}
            else
            printf("Masih kosong!\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 3: { system("cls");
            fflush(stdin);
            if(IsEmpty()!=1)
            {TampilStack();}
            else printf("Masih kosong!\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 4: { system("cls");
            fflush(stdin);
            Clear();
            printf("Data sudah dihapus!\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 5:main();break;

            default: stackstring();break;
        }
        getch();
    } while(pil !=5);
    getch();
}

void quequestring()
{
    fflush(stdin);
    int pil, item;
    inisialisasi2();
    do{
        system("cls");
        fflush(stdin);
        printf("1. Enqueue Int\n");
        printf("2. Dequeue Int\n");
        printf("3. Print Queue\n");
        printf("4. Delete Queue\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan : ");
        scanf("%d", &pil);
        //fflush(stdin);
        switch(pil)
        {
            case 1:
            {system("cls");
            fflush(stdin);
            if(IsFull2()!=1)
            {
                printf("Data = "); scanf("%d", &item);
                enqueue(item);
            }
            else printf("\nSudah Penuh\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 2:
            {system("cls");
            fflush(stdin);
            if(isEmpty()!=1)
            {Dequeue();}
            else
            printf("Data yang keluar: 0");
            printf ("\nPress any key to continue .  .  .");
            break;}

            case 3:
            {system("cls");
            fflush(stdin);
            if(isEmpty()!=1)
            {TampilQueue();}
            else printf("Tidak ada data dalam antrian!\n");
            printf ("Press any key to continue .  .  .");
            break;}

            case 4:
            {system("cls");
            fflush(stdin);
            Clear2();
            printf ("\nPress any key to continue .  .  .");
            break;}

            case 5:main();break;

            default: quequestring();break;
        }
        getch();
    } while(pil != 5);
    getch();
}
