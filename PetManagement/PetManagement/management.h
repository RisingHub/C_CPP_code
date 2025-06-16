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
//idΪi�ĳ���ľ������
static int my_visit_times[MAX_PETS] = { 0 };
//idΪi�ĳ��� ��j�������Ӧ�ľ���id
static int my_visit_id[MAX_PETS][MAX_VISITS] = {0};

//�ҺŵǼ�
void registration();

//�����¼����
void visit_record_management();
//1.��Ӽ�¼
void add_record();
//2.�޸ļ�¼
void change_record();
//3.ɾ����¼
void delete_record();

//��ѯ����
void query();

//�������ѯ
void accord_pet();
//��ʱ���ѯ
void accord_time();
//������״̬��ѯ
void accord_state();

int time_find_visit_id(int year, int month, int day);

//����ҩ������
void drug_management();
//����µ�ҩƷ
void add_drug();
//�޸�ҩƷ���
void change_drug();
//��ѯҩƷ���ƶ�Ӧ�ı��
int find_drug_id(char* target);
//���ҩƷ���ĺ���
int check_drug(char* name, int need);

//�������� �洢����������Ϣ
typedef struct {
    //int pet_id[MAX_ID];
    char name[MAX_NAME];
    char species[MAX_SPECIES];
    int age;
    char owner_name[MAX_NAME];
    char telephone_number[MAX_TELE];
    int state;
} Pet;

//�������� �洢���������Ϣ
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

//����ҩ�ṹ��
typedef struct {
    int num;
    char name[MAX_NAME];
    //int drug_id;
}Drug;



