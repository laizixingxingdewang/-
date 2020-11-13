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
	while (p1 ->pNext!= NULL) //之前用while (p1 != NULL)是错误的！因为这意味着p1移动到了尾结点的下一个节点（数据指针都为空！！！）
	{
		 p1=p1->pNext;
	}
	p1->pNext = p;
}

void Delete()
{
	Print();
	int nNumb;
	printf("请输入要删除的学号：");
	scanf_s("%d", &nNumb);
	SNode* p =pHead;
	SNode* p1= NULL;
	if (!p)
	{
		puts("数据库为空，程序返回！");
		return;
	}
	if (p->data.nNumb == nNumb)  //用if (pHead->data.nNumb == nNumb)意思一样
	{
		pHead = p->pNext;
		free(p);
		puts("删除成功！程序返回");
		return;
	}
	while (p)
	{
		if (p->data.nNumb == nNumb)
		{
			p1->pNext = p->pNext;
			free(p);
			puts("删除成功！程序返回");
			return;
		}
		p1 = p;
		p = p->pNext;
	}
	puts("未找到要删除的学号，程序返回");
	return;
}

void Modify()
{
	Print();
	int nNumb;
	printf("请输入要修改的学号：");
	scanf_s("%d", &nNumb);
	SNode* p = pHead;
	while (p)
	{
		if (p->data.nNumb == nNumb)
		{
			puts("学号\t姓名\t语文\t数学\t英语\t");
			printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
			int i;
			puts("要修改学号吗？按1修改，按2不修改");
			scanf_s("%d", &i);
			if(i==1)
			{
			  puts("请输入新学号：");
			  scanf_s("%d", &p->data.nNumb);
            }

			puts("要修改姓名吗？按1修改，按2不修改");
			scanf_s("%d", &i);
			if (i == 1)
			{
				puts("请输入姓名：");
				scanf_s("%s", &p->data.sName,sizeof(p->data.sName));
			}
			puts("输入语文成绩");
			scanf_s("%f", &p->data.fChinese);
			puts("输入数学成绩");
			scanf_s("%f", &p->data.fMath);
			puts("输入英语成绩");
			scanf_s("%f", &p->data.fEnglish);
			puts("学号\t姓名\t语文\t数学\t英语\t");
			printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
			Save();
			return;
		}
		p = p->pNext;
	}
	puts("未找到学号！程序将返回主菜单.");
}

void Find()
{
	int nNumb;
	printf("请输入要查询的学号：");
	scanf_s("%d", &nNumb);
	int i = 1;
	SNode* p = pHead;
	while (p)
	{
		if (p->data.nNumb ==nNumb)
		{
			puts("学号\t姓名\t语文\t数学\t英语\t");
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
	puts("学号\t姓名\t语文\t数学\t英语\t");
	int i = 0;
	while (p)              //while (p->pNext != NULL)也可以，但是没有while (p)简洁!
	{
		printf("%d\t%s\t%0.1f\t%0.1f\t%0.1f\t\n", p->data.nNumb, p->data.sName, p->data.fChinese, p->data.fMath, p->data.fEnglish);
		p = p->pNext;
		i++;
	}
	printf("共打印了%d个数据\n", i);
}

void Add(int nDir)
{
	int nNumb;
	printf("请输入学号：");
	scanf_s("%d", &nNumb);
	DATA data;
	data.nNumb = nNumb;
	printf("请输入姓名：");
	scanf_s("%s", data.sName, sizeof(data.sName));
	printf("请输入语文成绩：");
	scanf_s("%f", &data.fChinese);
	printf("请输入数学成绩：");
	scanf_s("%f", &data.fMath);
	printf("请输入英语成绩：");
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
		puts("保存文件失败.");
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
		puts("程序无法打开！");
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

void Sort(int nIndex)  //采用选择排序方法
{
	SNode* p = pHead;
	while (p)
	{
		SNode* q = p->pNext;
		SNode* m = p;   //m初始位置是跟p在一起 
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
	puts("0 = 黑色    8 = 灰色");
	puts("1 = 蓝色    9 = 淡蓝色");
	puts("2 = 绿色    A = 淡绿色");
	puts("3 = 湖蓝色  B = 淡浅绿色");
	puts("4 = 红色    C = 淡红色");
	puts("5 = 紫色    D = 淡紫色");
	puts("6 = 黄色    E = 淡黄色");
	puts("7 = 白色    F = 亮白色");
	char s[20] = "color ";
	puts("请输入背景色：【0-F】");
	rewind(stdin);             //经查阅资料后发现vs2015以后fflush(stdin)已经失效了！！ 
	s[6] = getchar();
	printf("请输入前景色：【0-F】");
	rewind(stdin);
	s[7] = getchar();
	system(s);
}

int SortMenu()
{
	system("cls");
	puts("1.按学号排序");
	puts("2.按姓名排序");
	puts("3.按语文成绩排序");
	puts("4.按数学成绩排序");
	puts("5.按英文成绩排序");
	puts("0.返回主菜单");
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
	puts("1.向头部插入");
	puts("2.向尾部插入");
	puts("0.返回主菜单");
	puts("请选择：");
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
	puts("\t1、浏览所有信息");
	puts("\t2、添加信息");
	puts("\t3、删除信息");
	puts("\t4、修改信息");
	puts("\t5、查找信息");
	puts("\t6、颜色设置");
	puts("\t0、退出");
	puts("\t请选择：");
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
	system("cls");   //清屏(clear screen)
#ifdef _TEST_VERSER
	puts("当前为测试版");
#else
	printf("     \t╭------------------------------------------------------╮\n");
	printf("     \t| ******************************************************|\n");
	printf("     \t|**╭-------------------------------------------------╮**|\n");
	printf("     \t|**|*************************************************|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**           欢迎使用信息管理系统              **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**               作者：王兴旺                  **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|**                2020.10.26                   **|**|\n");
	printf("     \t|**|**                                             **|**|\n");
	printf("     \t|**|*************************************************|**|\n");
	printf("     \t|**╰-------------------------------------------------╯**|\n");
	printf("    \t|*******************************************************|\n");
	printf("     \t╰---------------------按任意键继续---------------------╯\n");

	_getch();  //system("pause");
#endif
	Load();
	while (Menu())
	{

	}
}