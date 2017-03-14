#pragma once

#define MAX 1000//���洢����

//������Ϣ
typedef struct student
{
	char num[10];//���
	char name[15];//����
	char tele[12];//�ֻ�����
	char QQ[15];//QQ����
}Stu;
typedef struct TelephoneBook
{
	Stu stu[1000];
	int count;
}Tele, *ptele;
void initiate(ptele ptele);//����
void Input(ptele ptele);//����ѧ���������������1000��
void Search(ptele ptele);//����ѧ������������������
void Display(ptele ptele);//��ʾѧ��ͨѶ¼��������
void Modify(ptele ptele);//�޸�ѧ��ĳһ�˵���Ϣ
void Delete(ptele ptele);//ɾ��ĳһ�˵���Ϣ
void Insert(ptele ptele);//����ѧ����Ϣ
void Sort(ptele ptele);//����ѧ���������ˣ������������
void Save(ptele ptele);//����ѧ����Ϣ���ļ���
void menu();//�˵�
void initiate(ptele ptele)
{
	ptele->count = 0;
}
static int hanshu(ptele ptele, const char * name)
{
	int i = 0;
	for (i = 0; i < ptele->count; i++)
	{
		if (strcmp(name, ptele->stu[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Input(ptele ptele)
{
	if (ptele->count == MAX)
	{
		printf("telephone of full!\n");
		return;
	}
	printf("num:");
	scanf("%s", ptele->stu[ptele->count].num);
	printf("name:");
	scanf("%s", ptele->stu[ptele->count].name);
	printf("tele:");
	scanf("%s", &ptele->stu[ptele->count].tele);
	printf("QQ:");
	scanf("%s", ptele->stu[ptele->count].QQ);
	ptele->count++;
	printf("input success!\n");
}
void Display(ptele ptele)
{
	int i = 0;
	printf("num\tname\ttele\t\tQQ\n");
	for (i = 0; i < ptele->count; i++)
	{
		printf("%s\t%s\t%s\t%2s\n", ptele->stu[i].num, ptele->stu[i].name, ptele->stu[i].tele, ptele->stu[i].QQ);
	}
}
void Delete(ptele ptele)
{
	int ret = 0;
	int j = 0;
	char name[10];
	printf("please enter name:");
	scanf("%s", name);
	ret = hanshu(ptele, name);
	if (ret == -1)
	{
		printf("No exist!\n");
		return;
	}
	else
	{
		for (j = ret; j < ptele->count - 1; j++)
		{
			ptele->stu[j] = ptele->stu[j + 1];
		}
	}
	ptele->count--;
	printf("delete success!\n");
}
void Search(ptele ptele)
{
	int ret = 0;
	char name[10];
	printf("please enter name:");
	scanf("%s", name);
	ret = hanshu(ptele, name);
	if (ret == -1)
	{
		printf("No exist!\n");
		return;
	}
	else
	{
		printf("num\tname\ttele\t\tQQ\n");
		printf("%s\t%s\t%s\t%2s\n", ptele->stu[ret].num, ptele->stu[ret].name, ptele->stu[ret].tele, ptele->stu[ret].QQ);
	}
}
void Modify(ptele ptele)
{
	int ret = 0;
	char name[10];
	printf("please modify name:");
	scanf("%s", name);
	ret = hanshu(ptele, name);
	if (ret == -1)
	{
		printf("No exist!\n");
		return;
	}
	else
	{
		printf("num:");
		scanf("%s", ptele->stu[ret].num);
		printf("name:");
		scanf("%s", ptele->stu[ret].name);
		printf("tele:");
		scanf("%s", ptele->stu[ret].tele);
		printf("QQ:");
		scanf("%s", ptele->stu[ret].QQ);
	}
}
void Insert(ptele ptele)
{
	if (ptele->count == MAX)
	{
		printf("telephone of full!\n");
		return;
	}
	printf("num:");
	scanf("%s", ptele->stu[ptele->count].num);
	printf("name:");
	scanf("%s", ptele->stu[ptele->count].name);
	printf("tele:");
	scanf("%s", &ptele->stu[ptele->count].tele);
	printf("QQ:");
	scanf("%s", ptele->stu[ptele->count].QQ);
	ptele->count++;
	printf("insert success!\n");
}
void Sort(ptele ptele)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ptele->count; i++)
	{
		for (j = 0; j < ptele->count; j++)
		{
			if (strcmp(ptele->stu[j].name, ptele->stu[j + 1].name)>0)
			{
				Stu temp = ptele->stu[j];
				ptele->stu[j] = ptele->stu[j + 1];
				ptele->stu[j + 1] = temp;
			}
		}
	}
	printf("sort success!\n");
}
void Save(ptele ptele)
{
	FILE *fout;
	int i = 0;
	if ((fout = fopen("telephonebook.txt", "ab+")) == NULL)
	{
		printf("No open!\n");
		exit(EXIT_SUCCESS);
	}
	fprintf(fout, "num\tname\ttele\t\tQQ\n");
	fprintf(fout, "\r\n");
	for (i = 0; i < ptele->count; i++)
	{
		fprintf(fout, "%s\t%s\t%s\t%2s\n", ptele->stu[i].num, ptele->stu[i].name, ptele->stu[i].tele, ptele->stu[i].QQ);
		fprintf(fout, "\r\n");
	}
	fclose(fout);
	printf("save success!\n");
}
void menu()
{
	printf("              The telephone-book Management System             \n\n");
	printf("*         1 input    record              2 display  record    *\n");
	printf("*         3 delete  record               4 search record      *\n");
	printf("*         5 modify   record              6 insert   record    *\n");
	printf("*         7 sort      record             8 save     record    *\n");
	printf("*         8 quit      system                                  *\n");
	printf("***************************************************************\n\n");
}
