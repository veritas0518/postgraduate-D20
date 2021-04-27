#include<stdio.h>
#include<stdlib.h>

#define  datatype  int              //存储数据元素为整型变量
#define  MAXLEN  10            //队长为10

typedef  struct
{
    datatype  Q[MAXLEN];        //定义存储数据元素的数组
    int  front;          //定义队头和队尾指向
    int  count;                            //记录循环顺序队列中元素的个数
}  CycleSeqQueue;                //循环顺序队列的类型名

void  InitSeqQueue(CycleSeqQueue* q)
{

    
    q->front = 0;//初始化队头  因为没有尾指针只能用头指针来指向第一个节点或者最后一个节点
    q->count = 0;//初始化队内元素个数
}

int  Is_Empty(CycleSeqQueue* q)
{
      
    if (q->count == 0) { //如果头指针里的元素指向count所指向的0元素的话
        return 1;
    }
    else {
        return 0;
    }
    //队空，返回1；否则，返回0
}

int  Is_Full(CycleSeqQueue* q)
{
    if (q->count == MAXLEN - 1)
    {
        return  1;              //队满，返回1
    }
    else
    {
        return  0;              //否则，返回0
    }
}

int  InQueue(CycleSeqQueue* q, datatype  x)
{
    if (Is_Full(q))
    {
        printf("Queue is Full!\n");
        return 0;
        //入队失败，输出提示，返回0
    }
    else
    {
        int flag;
        q->count++;
        flag = (q->front + q->count) % MAXLEN;
        q->Q[flag] = x;
        return 1;
        //正常入队，成功返回1
    }
}

int  OutQueue(CycleSeqQueue* q)
{
    if (Is_Empty(q))
    {
        printf("Queue is Empty!\n");
        return 0;
        //出队失败，输出提示，返回0
    }
    else
    {
        q->front = (q->front+1)%MAXLEN;
        q->count--;
        return 1;
        //正常出队，成功返回1
    }
}

int  ReadFront(CycleSeqQueue* q, datatype* x)
{
    if (Is_Empty(q))
        
    {

        printf("Queue is Empty!\n");
        return 0;
        //读队头元素失败，输出提示，返回0
    }
    else
    { 
        
        q->front =(q->front+1)%MAXLEN;
        *x = q->Q[q->front];
        if (Is_Empty(q)) {//q->front==q->Q[MAXLEN]
            printf("Queue is Empty!\n");
            return 0;
        }
        else
        return 1;
        //读队头元素成功，返回1
    }
}

void  Show(CycleSeqQueue* q)//队列为空，输出提示；否则，输出整个队列
{
    int  i;
    if (Is_Empty(q))
    {
        printf("Queue  is  Empty!\n");
        return;
    }
    else
    {
        for (i = 1; i <= q->count; i++)
        {
            printf("%d  ", q->Q[(q->front + i) % MAXLEN]);
        }
        printf("\n");
    }
}

int  main(void)
{
    CycleSeqQueue* q;
    int  T, n;
    datatype  x;
    q = (CycleSeqQueue*)malloc(sizeof(CycleSeqQueue));
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        switch (n)
        {
        case  1:
            InitSeqQueue(q);
            Show(q);
            break;
        case  2:
            if (Is_Empty(q))
            {
                printf("Queue  is  Empty!\n");
            }
            else
            {
                printf("Queue  is  not  Empty!\n");
            }
            break;
        case  3:
            if (ReadFront(q, &x))
            {
                printf("%d\n", x);
            }
            break;
        case  4:
            scanf("%d", &x);
            if (InQueue(q, x))
            {
                Show(q);
            }
            break;
        case  5:
            if (OutQueue(q))
            {
                Show(q);
            }
            break;
        default:
            exit(1);

        }
    }
    return  0;
}