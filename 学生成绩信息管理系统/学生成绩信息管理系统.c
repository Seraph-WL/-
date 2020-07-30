#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<windows.h>
void interface();//���˵���������
void student_interface();//ѧ�����
void teacher_interface();//��ʦ���
void administratorsr_interface();//����Ա���
void super_administrators_interface();//��������Ա���
char PASS[]="abc123";//��������ԱԤ������
struct Admin//����Ա
{
   int number;//����
   char name[20];//����
   char code[20];//����
   int year;//������
   char sex;//�Ա�
   char state;//0���� 1 ���� 2 ��ְ
   struct Admin *link;
};
struct Teacher//��ʦ
{
   int number;//����
   char name[20];//����
   char sex;//�Ա�
   int year;//������
   char code[20];//����
   char state;//0���� 1 ���� 2 ��ѧ
   struct Teacher *link;
};
struct Student//ѧ��
{
   char code[20];//����
   char name[20];//����
   int number;//ѧ��
   int year;//������
   int month;//������
   int C_language;//c���Գɼ�
   int English;//Ӣ��ɼ�
   int Physical;//����ɼ�
   int Math;//��ѧ�ɼ�
   char sex;//�Ա�
   char state;//0���� 1 ���� 2 ��ְ
   struct Student *link;
};



void interface()
{
	system("cls");//�������� 
	printf("********************************************************\n");
	printf("------------------ѧ���ɼ���Ϣ����ϵͳ------------------\n");	
	printf("********************************************************\n");
	printf("\n					1��ѧ����¼���						\n");
	printf("\n					2����ʦ��¼���						\n");
	printf("\n					3������Ա��¼���					\n");
	printf("\n					4����������Ա��¼���				\n");
	printf("\n					5���˳�ϵͳ 						\n");
	printf("\n					�밴��ѡ��,�س�ȷ��					\n"); 
	printf("********************************************************\n");
	switch(getch())
	{
		case 49: student_interface(); break;
		case 50: teacher_interface(); break;
		case 51: administratorsr_interface(); break;
		case 52: super_administrators_interface(); break;
		case 53: exist(0); break;//�˳�ϵͳ 
	}
}
void student_interface()
{
	char stu_num[20];//ѧ�� 
	char stu_code[20];//���� 
	int i=0;
	system("cls");//�������� 
	printf("********************************************************\n");
	printf("------------------------ѧ����¼------------------------\n");	
	printf("********************************************************\n");
	printf("\n				1����¼ѧ���ɼ���ѯϵͳ					\n");
	printf("\n				2������������							\n");
	printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
	printf("********************************************************\n");//getch��������һ���ַ�����Ļ�ϲ���ʾ ,����ֵ��ASIIֵ 
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//�������� 
				printf("********************************************************\n");
				printf("------------------����ѧ���ɼ���ѯϵͳ------------------\n");	
				printf("********************************************************\n");
				printf("\n					1������ѧ�ź�����					\n");
				printf("\n					2��������һ����						\n");
				printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
				printf("********************************************************\n");
					switch(getch())
				{
					case 49:printf("������ѧ�ţ�");
							scanf("%s",stu_num);
							printf("\n���������룺");
							scanf("%s",stu_code);
							password_input(stu_code);//����������ܺ��� 
							i=cmp_stu_num(stu_num);//���ļ��ڴ洢��ѧ�Ž��бȽ�
							if(i==0)
							{
								printf("���˺Ų�����!\n");
								printf("�����������");
								getch();
								continue;
							}
							if(cmp_stu_code(i,stu_code))
							{
								system("cls");
								sleep(2000);
								student_interface_son(i);//ѧ���Ӳ˵� 
							};break;
					case 50:return;//�˳�
				}
			};break;//1.ѧ�����
		case 50:return;break;//�˳�
	}

}
void teacher_interface(void)
{
	system("cls");
	printf("********************************************************\n");
	printf("------------------------��ʦ��¼------------------------\n");	
	printf("********************************************************\n");
	printf("\n				1����¼��ʦ����ϵͳ						\n");
	printf("\n				2������������							\n");
	printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
	printf("********************************************************\n");
	int tea_num=[20];
	char tea_code[20];
	int i=0;
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//�������� 
				printf("********************************************************\n");
				printf("--------------------�����ʦ����ϵͳ--------------------\n");	
				printf("********************************************************\n");
				printf("\n					1�������˺ź�����					\n");
				printf("\n					2��������һ����						\n");
				printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
				printf("********************************************************\n");
				switch(getch())
				{
					case 49:printf("�������ʦ���ţ�");
							scanf("%s",tea_num);
							printf("\n���������룺");
							getch();
							password_input(tea_code);//��ʦ������ܺ���
							i=cmp_tea_num(tea_num);//���ļ��ڴ洢�Ľ�ʦ���Ž��жԱ�
							if(i==0)
							{
								printf("���˺Ų�����!\n");
								printf("�����������");
								getch();
								continue;
							}
							if(cmp_tea_code(i,tea_code))
							{
								system("cls");//�����������ĳĳ��ӭ����,�ĸ��˵�ͬ��
								sleep(2000);
								teacher_interface_son(i);//��ʦ�Ӳ˵�
							};break;
					case 50:return;
				}
			};break;
		case 50:return;break;
	}
}
void administratorsr_interface()
{
	int adm_num=[20];
	char adm_code[20];
	int i=0;
	system("cls");
	printf("********************************************************\n");
	printf("-----------------------����Ա��¼-----------------------\n");	
	printf("********************************************************\n");
	printf("\n				1����¼����Ա����ϵͳ					\n");
	printf("\n				2������������							\n");
	printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
	printf("********************************************************\n");
	
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//�������� 
				printf("********************************************************\n");
				printf("-------------------�������Ա����ϵͳ-------------------\n");	
				printf("********************************************************\n");
				printf("\n					1�������˺ź�����					\n");
				printf("\n					2��������һ����						\n");
				printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
				printf("********************************************************\n");
				switch(getch())
				{
					case 49:printf("���������Ա���ţ�");
							scanf("%s",adm_num);
							printf("���������룺");
							getch();
							password_input(adm_code);//������ܺ���
							i=cmp_adm_num(adm_num);//���ļ��ڹ��Ž���ƥ��
							if(i==0)
							{
								printf("���˺Ų�����!\n");
								printf("�����������");
								getch();
								continue;
							}
							if(cmp_adm_code(i,adm_code))
							{
								system("cls");
								sleep(2000);
								admin_interface_son(i);
							};break;
					case 50:return;break;
				}	
			};break;
		case 50:return;break;
	}
}
void super_administrators_interface(void)
{
	int i=0,super_adm_num=[20];
	char sup_adm_code[20];
	while(1)
	{
		system("cls");
		printf("********************************************************\n");
		printf("---------------------��������Ա��¼---------------------\n");	
		printf("********************************************************\n");
		printf("\n				1����¼��������Ա����ϵͳ				\n");
		printf("\n				2������������							\n");
		printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
		printf("********************************************************\n");
		switch(getch())
		{
			case 49:system("cls");//�������� 
					printf("********************************************************\n");
					printf("-----------------���볬������Ա����ϵͳ-----------------\n");	
					printf("********************************************************\n");
					printf("\n					1���������							\n");
					printf("\n					2���˳�								\n");
					printf("\n\n			�밴��ѡ��,�س�ȷ��						\n"); 
					printf("********************************************************\n");
					switch(getch())
					{
							case 49:printf("���������Ա���ţ�");
							scanf("%d",adm_num);
							printf("���������룺");
							getch();
							password_input(super_adm_code);
							i=cmp_super_adm_num(super_adm_num);
							if(i==0)
							{
								printf("�˺Ų�����!\n");
								printf("�����������");
								getch();
								continue;
							}
							if(cmp_super_adm_code(i,super_adm_code))
							{
								system("cls");
								sleep(2000);
								admin_interface_son(i);
							};break;
					case 50:return;break;
					} 
					password_input(sup_adm_mima);
					
					if(index==0)
					{
						printf("����ɹ�!!");
						super_administrators_interface_son();
					}
					else
					{
						anykey_continue();
						return;
					};break;
			case 50:return;
		}
	}
}

void password_input(char* str)


















