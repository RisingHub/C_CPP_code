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

//挂号登记
void registration()
{
	int i = ++pet_num;
	printf("【挂号登记】\n");
	printf("请输入宠物名字: ");
	scanf("%s", p[i].name);
	printf("物种: ");
	scanf("%s", p[i].species);
	printf("年龄: ");
	scanf("%d", &p[i].age);
	printf("主人姓名: ");
	scanf("%s", p[i].owner_name);
	printf("联系方式: ");
	scanf("%s", p[i].telephone_number);
	printf("挂号成功！宠物ID：%04d\n", pet_num);
	p[i].state = 0;
}

//就诊记录管理
void visit_record_management()
{
	int input;
	int flag = 0;//判断是否成功调整数据或退出 1时成功 跳出循环
	do {
		printf("【就诊记录管理】\n");
		printf("1.添加记录\n");
		printf("2.修改记录\n");
		printf("3.删除记录\n");
		printf("0.退出当前操作\n");
		printf("请选择:> ");
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
				printf("您已成功退出当前操作！\n");
				flag = 1;
				break;
		default:
			flag = 0;
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (!flag);

}

//检查药品库存
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
//1.添加记录
void add_record()
{
	int i = ++visit_num;
	printf("请输入宠物的ID：");
	int pi;//宠物id
	scanf("%d", &pi);
	if (!check_pet_id(pi))
	{
		printf("宠物ID不存在，操作失败\n");
		return;
	}
	p[pi].state = 1;
	int j = ++my_visit_times[pi];
	printf("症状：");
	scanf("%s", v[i].symptom);
	printf("诊断结果：");
	scanf("%s", v[i].result);
	printf("处方药品：");
	int need;
	printf("输入处方药名称及数量（如：阿莫西林 3）：");
	scanf("%s", v[i].prescription);
	getchar();
	scanf("%d", &need);
	//检查药品库存的函数
	if (!check_drug(v[i].prescription, need))
	{
		printf("药品库存数量不足！\n");
		//还原数据
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
	printf("当前药品库存余量为%d\n", d[drug_id].num);
	printf("接诊医生：");
	scanf("%s", v[i].doctor);
	printf("请输入当前日期（如:2025-6-15）：\n");
	scanf("%d-%d-%d", &v[i].year, &v[i].month, &v[i].day);
	printf("记录保存成功！就诊ID: %04d\n", i);
	my_visit_id[pi][j] = i;
}
//2.修改记录
void change_record()
{
	//补充或修改诊断和处方
	int vi;//就诊id
	printf("请输入就诊ID：");
	scanf("%d", &vi);
	if (!check_visit_id)
	{
		printf("该诊断ID不存在\n");
		return;
	}
	int input;
	do {
		printf("1.修改诊断信息\n");
		printf("2.修改处方信息\n");
		printf("0.退出当前操作\n");
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入更新后的诊断信息\n(如：瘸腿 骨折)：");
			scanf("%s", v[vi].symptom);
			scanf("%s", v[vi].result);
			printf("诊断信息已修改成功！\n");
			break;
		case 2:
			printf("请输入更新后的处方信息(如：阿司匹林 6)：");
			scanf("%s", v[vi].prescription);
			int di = find_drug_id(v[vi].prescription);
			scanf("%d", &d[di].num);
			printf("处方信息已修改成功！\n");
			printf("--------%s %d---------", v[vi].prescription, d[di].num);
			break;
		case 0:
			printf("您已成功退出当前操作！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}
//3.删除记录
void delete_record()
{
	printf("当前权限仅对管理员开放，请输入管理员密码：\n");
	char input[20] = { 0 };
	scanf("%s", input);
	if (strcmp(input, PASSPORD) == 0)
	{
		printf("登录成功！\n");
		int vi;
		while (1)
		{
			printf("请输入您想删除的诊断ID：\n");
			scanf("%d", &vi);
			if (!check_visit_id(vi))
			{
				printf("该诊断ID不存在,请重新输入！\n");
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
				printf("删除成功！\n");
				break;
			}
		}
	}
	else
	{
		printf("密码错误！\n");
	}

}

//按宠物查询
void accord_pet()
{
	printf("请输入宠物ID：");
	int id;
	scanf("%d", &id);
	if (!check_pet_id(id))
	{
		printf("宠物ID不存在！");
		return;
	}
	int i = 0;
	for (i = 1; i <= my_visit_times[id]; i++)
	{
		//该宠物第i次就诊对应的就诊id
		int j = my_visit_id[id][i];
		printf("%d. %04d-%02d-%02d | 诊断：%s | 医生：%s\n", i, v[j].year, v[j].month, v[j].day, v[j].symptom, v[j].doctor);
	}
}

//按时间查询
void accord_time()
{
	printf("请输入年月日（如：2025 10 23）：");
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
			printf("%d. 就诊ID：%d | 宠物ID：%d | 症状：%s | 诊断结果：%s | 处方药品：%s | 医生：%s\n", cnt, i, v[i].pet_id, v[i].symptom, v[i].result, v[i].prescription, v[i].doctor);
		}
	}
	if (!flag) printf("当前日期无就诊记录！\n");
}

//按就诊状态查询
void accord_state()
{
	printf("请输入当前日期（如：2015 10 23）：");
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
			printf("%d. 宠物ID：%d | 宠物名称：%s | 物种：%s | 年龄：%d | 主人姓名：%s | 主人电话：%s | ", cnt,pi,p[pi].name,p[pi].species,p[pi].age,p[pi].owner_name,p[pi].telephone_number);
			if (p[pi].state) 
			{
				printf("状态：已诊\n");
			}
			else
			{
				printf("状态：待诊\n");
			}
		}
	}

}

//查询
void query()
{
	int input;
	int flag = 0;
	do
	{
		printf("【查询】\n");
		printf("1.按宠物查询\n");
		printf("2.按日期查询\n");
		printf("3.当日就诊查询\n");
		printf("0.退出当前操作\n");
		printf("请选择查询类型:> ");
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
			printf("您已成功退出当前操作！\n");
			flag = 1;
			break;
		default:
			printf("输入错误，请重新输入！\n");
			flag = 0;
			break;
		}
	} while (!flag);
	
}


//处方药库存管理
void drug_management()
{
	int input;
	do {
		printf("【处方药库存管理】\n");
		printf("1.新增药物\n");
		printf("2.修改药物库存\n");
		printf("0.退出当前操作\n");
		printf("请选择:> ");
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
			printf("您已成功退出当前操作！\n");
		default:
			printf("当前输入错误，请重新输入！\n");
			break;
		}

	} while (input);
}
//添加新的药品
void add_drug()
{
	printf("请输入要添加的药品名称(输入\"0\"终止当前操作):> ");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "0") == 0) return;
	int i = ++drug_kinds;
	strcpy(d[i].name, name);
	printf("请输入该药品的库存:> ");
	scanf("%d", &d[i].num);
	printf("%d. %s添加成功！库存为 %d\n", i, d[i].name, d[i].num);
}
//查询药品名称对应的药品编号
int find_drug_id(char* target)
{
	int i = 0;
	for (i = 1; i <= drug_kinds; i++)
	{
		if (strcmp(target, d[i].name) == 0) return i;
	}
	return 0;
}
//修改药品库存
void change_drug()
{
	while (1) 
	{
		printf("请输入要修改库存的药品名称：");
		char name[MAX_NAME];
		scanf("%s", name);
		int id = find_drug_id(name);
		if (!id)
		{
			printf("药品不存在!\n");
			break;
		}
		else
		{
			printf("请输入该药品的新库存：");
			scanf("%d", &d[id].num);
			break;
		}
	}
}