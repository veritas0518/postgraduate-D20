#include<stdio.h>
#include<stdlib.h>

#define  datatype  int              //�洢����Ԫ��Ϊ���ͱ���
#define  MAXLEN  10            //�ӳ�Ϊ10

typedef  struct
{
    datatype  Q[MAXLEN];        //����洢����Ԫ�ص�����
    int  front;          //�����ͷ�Ͷ�βָ��
    int  count;                            //��¼ѭ��˳�������Ԫ�صĸ���
}  CycleSeqQueue;                //ѭ��˳����е�������

void  InitSeqQueue(CycleSeqQueue* q)
{

    
    q->front = 0;//��ʼ����ͷ  ��Ϊû��βָ��ֻ����ͷָ����ָ���һ���ڵ�������һ���ڵ�
    q->count = 0;//��ʼ������Ԫ�ظ���
}

int  Is_Empty(CycleSeqQueue* q)
{
      
    if (q->count == 0) { //���ͷָ�����Ԫ��ָ��count��ָ���0Ԫ�صĻ�
        return 1;
    }
    else {
        return 0;
    }
    //�ӿգ�����1�����򣬷���0
}

int  Is_Full(CycleSeqQueue* q)
{
    if (q->count == MAXLEN - 1)
    {
        return  1;              //����������1
    }
    else
    {
        return  0;              //���򣬷���0
    }
}

int  InQueue(CycleSeqQueue* q, datatype  x)
{
    if (Is_Full(q))
    {
        printf("Queue is Full!\n");
        return 0;
        //���ʧ�ܣ������ʾ������0
    }
    else
    {
        int flag;
        q->count++;
        flag = (q->front + q->count) % MAXLEN;
        q->Q[flag] = x;
        return 1;
        //������ӣ��ɹ�����1
    }
}

int  OutQueue(CycleSeqQueue* q)
{
    if (Is_Empty(q))
    {
        printf("Queue is Empty!\n");
        return 0;
        //����ʧ�ܣ������ʾ������0
    }
    else
    {
        q->front = (q->front+1)%MAXLEN;
        q->count--;
        return 1;
        //�������ӣ��ɹ�����1
    }
}

int  ReadFront(CycleSeqQueue* q, datatype* x)
{
    if (Is_Empty(q))
        
    {

        printf("Queue is Empty!\n");
        return 0;
        //����ͷԪ��ʧ�ܣ������ʾ������0
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
        //����ͷԪ�سɹ�������1
    }
}

void  Show(CycleSeqQueue* q)//����Ϊ�գ������ʾ�����������������
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