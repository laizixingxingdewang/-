#define _CRT_SECURE_NO_WARNINGS
#define _TEST_VERSER0

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct SInf
{
	int nNumb;
	char sName[20];
	float fChinese;
	float fMath;
	float fEnglish;
};

typedef SInf DATA;

void AddHead(DATA data);
void AddTail(DATA data);
void Delete();
void Modify();
void Find();
void Add(int nDir);
void Save();
void Load();
int SortMenu();
int AddMenu();
int Menu();
void Sort(int nIndex);
void Print();
void SetColor();

struct SNode
{
	DATA data;
	SNode* pNext;
};
SNode* pHead = NULL;

void AddHead(DATA data)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = pHead;
	pHead = p;
}

void AddTail(DATA data)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = NULL;
	if (!pHead)
	{
		pHead = p;
		return;
	}
	SNode* p1=pHead;
	while (p1 ->pNext!= NULL) //֮ǰ��while (p1 != NULL)�Ǵ���ģ���Ϊ����ζ��p1�ƶ�����β������һ���ڵ㣨����ָ�붼Ϊ�գ�������
	{
		 p1=p1->pNext;
	}
	p1->pNext = p;
}

void Delete()
{
	Print();
	int nNumb;
	printf("������Ҫɾ����ѧ�ţ�");
	scanf_s("%d", &nNumb);
	SNode* p =pHead;
	SNode* p1= NULL;
	if (!p)
	{
		puts("���ݿ�Ϊ�գ����򷵻أ�");
		return;
	}
	if (p->data.nNumb == nNumb)  //��if (pHead->data.nNumb == nNumb)��˼һ��
	{
		pHead = p->pNext;
		free(p);
		puts("ɾ���ɹ������򷵻�");
		return;
	}
	while (p)
	{
		if (p->data.nNumb == nNumb)
		{
			p1->pNext = p->pNext;
			free(p);
			puts("ɾ���ɹ������򷵻�");
			return;
		}
		p1 = p;
		p = p->pNext;
	}
	puts("δ�ҵ�Ҫɾ����ѧ�ţ����򷵻�");
	return;
}

void Modify()
{
	Print();
	int nNumb;
	printf("������Ҫ�޸ĵ�ѧ�ţ�");
	scanf_s("%d", &nNumb);
	SNode* p = pHead;
	while (p)
	{
		if (p->data.nNumb == nNumb)
		{
			puts("ѧ��\t����\t����\t��ѧ\tӢ��\t");
			printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
			int i;
			puts("Ҫ�޸�ѧ���𣿰�1�޸ģ���2���޸�");
			scanf_s("%d", &i);
			if(i==1)
			{
			  puts("��������ѧ�ţ�");
			  scanf_s("%d", &p->data.nNumb);
            }

			puts("Ҫ�޸������𣿰�1�޸ģ���2���޸�");
			scanf_s("%d", &i);
			if (i == 1)
			{
				puts("������������");
				scanf_s("%s", &p->data.sName,sizeof(p->data.sName));
			}
			puts("�������ĳɼ�");
			scanf_s("%f", &p->data.fChinese);
			puts("������ѧ�ɼ�");
			scanf_s("%f", &p->data.fMath);
			puts("����Ӣ��ɼ�");
			scanf_s("%f", &p->data.fEnglish);
			puts("ѧ��\t����\t����\t��ѧ\tӢ��\t");
			printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
			Save();
			return;
		}
		p = p->pNext;
	}
	puts("δ�ҵ�ѧ�ţ����򽫷������˵�.");
}

void Find()
{
	int nNumb;
	printf("������Ҫ��ѯ��ѧ�ţ�");
	scanf_s("%d", &nNumb);
	int i = 1;
	SNode* p = pHead;
	while (p)
	{
		if (p->data.nNumb ==nNumb)
		{
			puts("ѧ��\t����\t����\t��ѧ\tӢ��\t");
			printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
			return;
		}
		i++;
		p=p->pNext;
	}
       return;
}

void Print()
{
	SNode* p = pHead;
	puts("ѧ��\t����\t����\t��ѧ\tӢ��\t");
	int i = 0;
	while (p)              //while (p->pNext != NULL)Ҳ���ԣ�����û��while (p)���!
	{
		printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
		p = p->pNext;
		i++;
	}
	printf("����ӡ��%d������\n", i);
}

void Add(int nDir)
{
	int nNumb;
	printf("������ѧ�ţ�");
	scanf_s("%d", &nNumb);
	DATA data;
	data.nNumb = nNumb;
	printf("������������");
	scanf_s("%s", data.sName, sizeof(data.sName));
	printf("���������ĳɼ���");
	scanf_s("%f", &data.fChinese);
	printf("��������ѧ�ɼ���");
	scanf_s("%f", &data.fMath);
	printf("������Ӣ��ɼ���");
	scanf_s("%f", &data.fEnglish);
	if(nDir==1)
	AddHead(data);
	else
	{
		AddTail(data);
	}
	Save();
	Print();
}

void Save()
{
	FILE* pf = fopen("stud.wang","w");
	if (!pf)
	{
		puts("�����ļ�ʧ��.");
		return;
	}
	SNode* p = pHead;
	while(p)
	{
		fwrite(p, 1, sizeof(p->data), pf);
		p = p->pNext;
	}
	fclose(pf);
}

void Load()
{
	FILE* pf=fopen("stud.wang", "r");
	if (!pf)
	{
		puts("�����޷��򿪣�");
		return;
	}
	DATA data;
	while (fread(&data, 1, sizeof(data), pf) == sizeof(data))
		AddTail(data);

	fclose(pf);
}

int judge(SNode* q, SNode* m, int nIndex)
{
	switch (nIndex)
	{
	case 1:
		return q->data.nNumb < m->data.nNumb;
	case 2:
		return strcmp(q->data.sName, m->data.sName) < 0;
	case 3:
		return q->data.fChinese > m->data.fChinese;
	case 4:
		return q->data.fMath > m->data.fMath;
	case 5:
		return q->data.fEnglish > m->data.fEnglish;
	}
	return 0;
}

void Sort(int nIndex)  //����ѡ�����򷽷�
{
	SNode* p = pHead;
	while (p)
	{
		SNode* q = p->pNext;
		SNode* m = p;   //m��ʼλ���Ǹ�p��һ�� 
		while (q)
		{
			if (judge(q,m,nIndex))
				m = q;


			q = q->pNext;
		}
		if (m != p)
		 {
			DATA t = p->data;
			p->data = m->data;
			m->data = t;
		 }
		p=p->pNext;
	}
	Print();
	system("pause");
}

void SetColor()
{
	puts("0 = ��ɫ    8 = ��ɫ");
	puts("1 = ��ɫ    9 = ����ɫ");
	puts("2 = ��ɫ    A = ����ɫ");
	puts("3 = ����ɫ  B = ��ǳ��ɫ");
	puts("4 = ��ɫ    C = ����ɫ");
	puts("5 = ��ɫ    D = ����ɫ");
	puts("6 = ��ɫ    E = ����ɫ");
	puts("7 = ��ɫ    F = ����ɫ");
	char s[20] = "color ";
	puts("�����뱳��ɫ����0-F��");
	rewind(stdin);             //���������Ϻ���vs2015�Ժ�fflush(stdin)�Ѿ�ʧЧ�ˣ��� 
	s[6] = getchar();
	printf("������ǰ��ɫ����0-F��");
	rewind(stdin);
	s[7] = getchar();
	system(s);
}

int SortMenu()
{
	system("cls");
	puts("1.��ѧ������");
	puts("2.����������");
	puts("3.�����ĳɼ�����");
	puts("4.����ѧ�ɼ�����");
	puts("5.��Ӣ�ĳɼ�����");
	puts("0.�������˵�");
	int num;
	scanf_s("%d", &num);
	switch(num)
	{ 
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			Sort(num);
		default:
			return num;
    }
	return num;
}

int AddMenu()
{
	puts("1.��ͷ������");
	puts("2.��β������");
	puts("0.�������˵�");
	puts("��ѡ��");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
	case 2:
		Add(i);
		break;
	}
	return i;
}

int Menu()
{
	system("cls");
	puts("\t1�����������Ϣ");
	puts("\t2�������Ϣ");
	puts("\t3��ɾ����Ϣ");
	puts("\t4���޸���Ϣ");
	puts("\t5��������Ϣ");
	puts("\t6����ɫ����");
	puts("\t0���˳�");
	puts("\t��ѡ��");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		while (SortMenu());
		break;
	case 2:
		while (AddMenu());
		break;
	case 3:
		Delete();
		system("pause");
		break;
	case 4:
		Modify();
		system("pause");
		break;
	case 5:
		Find();
		system("pause");
		break;
	case 6:
		SetColor();
		break;
	}
	return i;
}

void main()
{
	system("color 72");
	system("cls");   //����(clear screen)
#ifdef _TEST_VERSER
	puts("��ǰΪ���԰�");
#else
	printf("     \t�q------------------------------------------------------�r\n");
	printf("     \t| ******************************************************|\n");
	printf("     \t|**�q-------------------------------------------------�r**|\n");
	printf("     \t|**|*************************************************|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**           ��ӭʹ����Ϣ����ϵͳ              **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**               ���ߣ�������                  **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**                2020.10.26                   **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|*************************************************|**|\n");
	printf("     \t|**�t-------------------------------------------------�s**|\n");
	printf("    \t|*******************************************************|\n");
	printf("     \t�t---------------------�����������---------------------�s\n");

	_getch();  //system("pause");
#endif
	Load();
	while (Menu())
	{

	}
}