#include "management.h"

void menu()
{
	printf("================菜单================\n");
	printf("==== 1.挂号登记  2.就诊记录管理 ====\n");
	printf("==== 3.查询      4.处方药库存管理 ==\n");
	printf("==== 0.退出宠物就诊管理系统 ========\n");
	printf("====================================\n");
}
int main()
{
	int input = 0;
	printf("欢迎使用宠物就诊信息管理系统！\n");
	do {
		menu();
		printf("请选择:> ");
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
			printf("您已成功退出宠物就诊信息管理系统，欢迎下次使用！\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	
	return 0;
}