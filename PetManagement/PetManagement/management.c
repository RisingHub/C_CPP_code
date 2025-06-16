#include "management.h"

static Pet p[MAX_PETS];
static Visit v[MAX_VISITS];
static Drug d[MAX_DRUGS];

int check_pet_id(int id)
{
	if (id > pet_num || id <= 0)
		return 0;
	return 1;
}
int check_visit_id(int id)
{
	if (id > visit_num || id <= 0)
		return 0;
	return 1;
}
int check_drug_id(int id)
{
	if (id > drug_kinds || id <= 0)
		return 0;
	return 1;
}

//�ҺŵǼ�
void registration()
{
	int i = ++pet_num;
	printf("���ҺŵǼǡ�\n");
	printf("�������������: ");
	scanf("%s", p[i].name);
	printf("����: ");
	scanf("%s", p[i].species);
	printf("����: ");
	scanf("%d", &p[i].age);
	printf("��������: ");
	scanf("%s", p[i].owner_name);
	printf("��ϵ��ʽ: ");
	scanf("%s", p[i].telephone_number);
	printf("�Һųɹ�������ID��%04d\n", pet_num);
	p[i].state = 0;
}

//�����¼����
void visit_record_management()
{
	int input;
	int flag = 0;//�ж��Ƿ�ɹ��������ݻ��˳� 1ʱ�ɹ� ����ѭ��
	do {
		printf("�������¼����\n");
		printf("1.��Ӽ�¼\n");
		printf("2.�޸ļ�¼\n");
		printf("3.ɾ����¼\n");
		printf("0.�˳���ǰ����\n");
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			add_record();
			flag = 1;
			break;
		case 2:
			change_record();
			flag = 1;
			break;
		case 3:
			delete_record();
			flag = 1;
			break;
		case 0:
				printf("���ѳɹ��˳���ǰ������\n");
				flag = 1;
				break;
		default:
			flag = 0;
			printf("����������������룡\n");
			break;
		}
	} while (!flag);

}

//���ҩƷ���
int check_drug(char* name, int need) 
{
	int id = find_drug_id(name);
	if (!check_drug_id(id)) return 0;
	if (d[id].num < need)
	{
		return 0;
	}
	return 1;
}
//1.��Ӽ�¼
void add_record()
{
	int i = ++visit_num;
	printf("����������ID��");
	int pi;//����id
	scanf("%d", &pi);
	if (!check_pet_id(pi))
	{
		printf("����ID�����ڣ�����ʧ��\n");
		return;
	}
	p[pi].state = 1;
	int j = ++my_visit_times[pi];
	printf("֢״��");
	scanf("%s", v[i].symptom);
	printf("��Ͻ����");
	scanf("%s", v[i].result);
	printf("����ҩƷ��");
	int need;
	printf("���봦��ҩ���Ƽ��������磺��Ī���� 3����");
	scanf("%s", v[i].prescription);
	getchar();
	scanf("%d", &need);
	//���ҩƷ���ĺ���
	if (!check_drug(v[i].prescription, need))
	{
		printf("ҩƷ����������㣡\n");
		//��ԭ����
		strcpy(v[i].symptom, "");
		strcpy(v[i].result, "");
		strcpy(v[i].prescription, "");
		--my_visit_times[pi];
		--visit_num;
		return;
	}
	int drug_id = find_drug_id(v[i].prescription);
	//printf("----------%d------------\n", d[drug_id].num);
	//printf("----------%d------------\n", need);
	d[drug_id].num -= need;
	printf("��ǰҩƷ�������Ϊ%d\n", d[drug_id].num);
	printf("����ҽ����");
	scanf("%s", v[i].doctor);
	printf("�����뵱ǰ���ڣ���:2025-6-15����\n");
	scanf("%d-%d-%d", &v[i].year, &v[i].month, &v[i].day);
	printf("��¼����ɹ�������ID: %04d\n", i);
	my_visit_id[pi][j] = i;
}
//2.�޸ļ�¼
void change_record()
{
	//������޸���Ϻʹ���
	int vi;//����id
	printf("���������ID��");
	scanf("%d", &vi);
	if (!check_visit_id)
	{
		printf("�����ID������\n");
		return;
	}
	int input;
	do {
		printf("1.�޸������Ϣ\n");
		printf("2.�޸Ĵ�����Ϣ\n");
		printf("0.�˳���ǰ����\n");
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������º�������Ϣ\n(�磺ȳ�� ����)��");
			scanf("%s", v[vi].symptom);
			scanf("%s", v[vi].result);
			printf("�����Ϣ���޸ĳɹ���\n");
			break;
		case 2:
			printf("��������º�Ĵ�����Ϣ(�磺��˾ƥ�� 6)��");
			scanf("%s", v[vi].prescription);
			int di = find_drug_id(v[vi].prescription);
			scanf("%d", &d[di].num);
			printf("������Ϣ���޸ĳɹ���\n");
			printf("--------%s %d---------", v[vi].prescription, d[di].num);
			break;
		case 0:
			printf("���ѳɹ��˳���ǰ������\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}
//3.ɾ����¼
void delete_record()
{
	printf("��ǰȨ�޽��Թ���Ա���ţ����������Ա���룺\n");
	char input[20] = { 0 };
	scanf("%s", input);
	if (strcmp(input, PASSPORD) == 0)
	{
		printf("��¼�ɹ���\n");
		int vi;
		while (1)
		{
			printf("����������ɾ�������ID��\n");
			scanf("%d", &vi);
			if (!check_visit_id(vi))
			{
				printf("�����ID������,���������룡\n");
			}
			else
			{
				int pi = v[vi].pet_id;
				int i = 0;
				for (i = 1; i <= my_visit_times[pi]; i++)
				{
					if (my_visit_id[pi][i] == vi)
					{
						my_visit_id[pi][i] = 0;
						break;
					}
				}
				while (i < my_visit_times[pi])
				{
					my_visit_id[pi][i] = my_visit_id[pi][i + 1];
				}
				--my_visit_times[pi];
				printf("ɾ���ɹ���\n");
				break;
			}
		}
	}
	else
	{
		printf("�������\n");
	}

}

//�������ѯ
void accord_pet()
{
	printf("���������ID��");
	int id;
	scanf("%d", &id);
	if (!check_pet_id(id))
	{
		printf("����ID�����ڣ�");
		return;
	}
	int i = 0;
	for (i = 1; i <= my_visit_times[id]; i++)
	{
		//�ó����i�ξ����Ӧ�ľ���id
		int j = my_visit_id[id][i];
		printf("%d. %04d-%02d-%02d | ��ϣ�%s | ҽ����%s\n", i, v[j].year, v[j].month, v[j].day, v[j].symptom, v[j].doctor);
	}
}

//��ʱ���ѯ
void accord_time()
{
	printf("�����������գ��磺2025 10 23����");
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);
	int i = 0;
	int cnt = 0;
	int flag = 0;
	for (i = 1; i <= visit_num; i++)
	{
		if (v[i].year == y && v[i].month == m && v[i].day == d)
		{
			++cnt;
			flag = 1;
			printf("%d. ����ID��%d | ����ID��%d | ֢״��%s | ��Ͻ����%s | ����ҩƷ��%s | ҽ����%s\n", cnt, i, v[i].pet_id, v[i].symptom, v[i].result, v[i].prescription, v[i].doctor);
		}
	}
	if (!flag) printf("��ǰ�����޾����¼��\n");
}

//������״̬��ѯ
void accord_state()
{
	printf("�����뵱ǰ���ڣ��磺2015 10 23����");
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);
	int i = 0;
	int cnt = 0;
	for (i = 1; i <= visit_num; i++)
	{
		if (v[i].year == y && v[i].month == m && v[i].day == d)
		{
			++cnt;
			int pi = v[i].pet_id;
			printf("%d. ����ID��%d | �������ƣ�%s | ���֣�%s | ���䣺%d | ����������%s | ���˵绰��%s | ", cnt,pi,p[pi].name,p[pi].species,p[pi].age,p[pi].owner_name,p[pi].telephone_number);
			if (p[pi].state) 
			{
				printf("״̬������\n");
			}
			else
			{
				printf("״̬������\n");
			}
		}
	}

}

//��ѯ
void query()
{
	int input;
	int flag = 0;
	do
	{
		printf("����ѯ��\n");
		printf("1.�������ѯ\n");
		printf("2.�����ڲ�ѯ\n");
		printf("3.���վ����ѯ\n");
		printf("0.�˳���ǰ����\n");
		printf("��ѡ���ѯ����:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			accord_pet();
			flag = 1;
			break;
		case 2:
			accord_time();
			flag = 1;
			break;
		case 3:
			accord_state();
			flag = 1;
			break;
		case 0:
			printf("���ѳɹ��˳���ǰ������\n");
			flag = 1;
			break;
		default:
			printf("����������������룡\n");
			flag = 0;
			break;
		}
	} while (!flag);
	
}


//����ҩ������
void drug_management()
{
	int input;
	do {
		printf("������ҩ������\n");
		printf("1.����ҩ��\n");
		printf("2.�޸�ҩ����\n");
		printf("0.�˳���ǰ����\n");
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			add_drug();
			break;
		case 2:
			change_drug();
			break;
		case 0:
			printf("���ѳɹ��˳���ǰ������\n");
		default:
			printf("��ǰ����������������룡\n");
			break;
		}

	} while (input);
}
//����µ�ҩƷ
void add_drug()
{
	printf("������Ҫ��ӵ�ҩƷ����(����\"0\"��ֹ��ǰ����):> ");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "0") == 0) return;
	int i = ++drug_kinds;
	strcpy(d[i].name, name);
	printf("�������ҩƷ�Ŀ��:> ");
	scanf("%d", &d[i].num);
	printf("%d. %s��ӳɹ������Ϊ %d\n", i, d[i].name, d[i].num);
}
//��ѯҩƷ���ƶ�Ӧ��ҩƷ���
int find_drug_id(char* target)
{
	int i = 0;
	for (i = 1; i <= drug_kinds; i++)
	{
		if (strcmp(target, d[i].name) == 0) return i;
	}
	return 0;
}
//�޸�ҩƷ���
void change_drug()
{
	while (1) 
	{
		printf("������Ҫ�޸Ŀ���ҩƷ���ƣ�");
		char name[MAX_NAME];
		scanf("%s", name);
		int id = find_drug_id(name);
		if (!id)
		{
			printf("ҩƷ������!\n");
			break;
		}
		else
		{
			printf("�������ҩƷ���¿�棺");
			scanf("%d", &d[id].num);
			break;
		}
	}
}