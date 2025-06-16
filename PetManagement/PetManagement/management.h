#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PETS 10000
#define MAX_VISITS 10000

#define MAX_ID 10000
#define MAX_NAME 30
#define MAX_TELE 20
#define MAX_SPECIES 110
#define MAX_WORDS 110
#define MAX_DRUGS 110
#define PASSPORD "admin"
static int pet_num = 0;
static int visit_num = 0;
static int drug_kinds = 0;
int check_pet_id(int id);
int check_visit_id(int id);
int check_drug_id(int id);
//id为i的宠物的就诊次数
static int my_visit_times[MAX_PETS] = { 0 };
//id为i的宠物 第j次问诊对应的就诊id
static int my_visit_id[MAX_PETS][MAX_VISITS] = {0};

//挂号登记
void registration();

//就诊记录管理
void visit_record_management();
//1.添加记录
void add_record();
//2.修改记录
void change_record();
//3.删除记录
void delete_record();

//查询病例
void query();

//按宠物查询
void accord_pet();
//按时间查询
void accord_time();
//按就诊状态查询
void accord_state();

int time_find_visit_id(int year, int month, int day);

//处方药库存管理
void drug_management();
//添加新的药品
void add_drug();
//修改药品库存
void change_drug();
//查询药品名称对应的编号
int find_drug_id(char* target);
//检查药品库存的函数
int check_drug(char* name, int need);

//宠物类型 存储宠物的相关信息
typedef struct {
    //int pet_id[MAX_ID];
    char name[MAX_NAME];
    char species[MAX_SPECIES];
    int age;
    char owner_name[MAX_NAME];
    char telephone_number[MAX_TELE];
    int state;
} Pet;

//就诊类型 存储就诊相关信息
typedef struct {
    int pet_id;
    char symptom[MAX_WORDS];
    char result[MAX_WORDS];
    char prescription[MAX_WORDS];
    char doctor[MAX_NAME];
    int year;
    int month;
    int day;
} Visit;

//处方药结构体
typedef struct {
    int num;
    char name[MAX_NAME];
    //int drug_id;
}Drug;



