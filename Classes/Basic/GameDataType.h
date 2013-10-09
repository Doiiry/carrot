#ifndef __GAMEDATATYPE_H__
#define __GAMEDATATYPE_H__

#include "CCStdC.h"
#include "string.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

//�ؿ��½�
typedef struct{
	int idChapter;		//�½�id
	string name;		//�½���
	string nameAni;		//����ani
	int nStageCnt;		//�ؿ�����
	string bgAni;		//�½�ͼƬ
}TPL_CHAPTER;

//�ؿ�
typedef struct{
	int idStage;		//�ؿ�id
	string name;		//�ؿ���
	int idChapter;		//�����½�id
	int nStageNum;		//�ڼ���
	string ani;			//�ؿ�ani
	int	nWave;			//����
	int nWeaponSetId;	//��������id
	int idMap;			//��Ӧ��ͼid
}TPL_STAGE;

//�������ߵĵ�ͼ·��
typedef struct{
	string name;
	int x;
	int y;
	int idx;
}PATH_POINT;

//��ͼ�Ͽɷ��ø���
typedef struct{
	string name;
	int x;
	int y;
	int width;
	int height;
	int idObj;
}MAP_CELL;

//��ͼ���
typedef struct{
	int idMap;			//��ͼid
	string map;			//��ͼ�ļ�
	string startPos;	//��ʼλ�ã���Ӧtmx�ļ���·����
	string mapBg;		//��ͼ����ͼ
	string mapFore;		//��ͼǰ��ͼ
	string endPos;		//�������꣬���ܲ�����λ��
}TPL_MAP;

//��ͼ������
typedef struct  
{
	int	idObj;			//��ͼ���id
	int idMap;			//�������id
	string pos;			//��������
	string objAni;		//���ani
	int width;			//������,�������Ӵ�С
	int height;		//����߶�,���Ӵ�С
	int action;		//�Ƿ��ж�����0�� 1 �����ƶ� 2�����ƶ�
	int data1;		//�ƶ�ƫ����
	int lifeMax;	//�������ֵ

	//�����Ϸ����������
	int life;		//�����������Ϊ0ʱ�����������
}TPL_MAP_OBJ;

//�û��������
typedef struct
{
	int curStage;
}USER;
#endif

