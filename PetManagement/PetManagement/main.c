#include "management.h"

void menu()
{
	printf("================�˵�================\n");
	printf("==== 1.�ҺŵǼ�  2.�����¼���� ====\n");
	printf("==== 3.��ѯ      4.����ҩ������ ==\n");
	printf("==== 0.�˳�����������ϵͳ ========\n");
	printf("====================================\n");
}
int main()
{
	int input = 0;
	printf("��ӭʹ�ó��������Ϣ����ϵͳ��\n");
	do {
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:
			registration();
			break;
		case 2:
			visit_record_management();
			break;
		case 3:
			query();
			break;
		case 4:
			drug_management();
			break;
		case 0:
			printf("���ѳɹ��˳����������Ϣ����ϵͳ����ӭ�´�ʹ�ã�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	
	return 0;
}