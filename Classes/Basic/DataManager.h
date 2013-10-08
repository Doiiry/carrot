#ifndef __DATAMANAGER_H__
#define __DATAMANAGER_H__

#include "CppSQLite3.h"
#include "GameDataType.h"
#include "CCStdC.h"
#include "cocos2d.h"
#include <map>
#include <vector>

USING_NS_CC;
using namespace std;

class CDataManager
{
public:
	static CDataManager* sharedDataManager(void);

	void init();

	//���
	const map<int, TPL_CHAPTER>* getChapterList();
	//��ȡ��ͼ��������·����ǰ������Ϣ
	const PATH_POINT* GetCurStepInfo(int curIdx);
	//��ȡ�¸�������Ϣ
	const PATH_POINT* GetNextStep(int curIdx = 0);
	//��ȡ��ͼ�Ͽ����ߵ�·��
	const map<int, PATH_POINT>* getMapPath();
	//ͨ��·������ȡ��·����ϸ��Ϣ
	const PATH_POINT* GetPointByName(const char* szName);


	//����
	void findStageByChapterId(int nId, map<int, TPL_STAGE>& mapReturn);
	//�����½�
	const TPL_STAGE* findStage(int idStage);
	//���ҵ�ͼ
	const TPL_MAP* findMap(int idMap);
	//���ҵ�ͼ���
	void findMapObj(int idMap, vector<TPL_MAP_OBJ>& vecObj);
	//���ҵ�ͼ�ɷ��ø���
	const MAP_CELL* findMapCell(string cellName);


	//��ȡ��ͼ����
	void ReadMapInfo(CCArray* pArray);

	

	

protected:
	CDataManager(void);
	~CDataManager(void);

	CppSQLite3DB m_db;			//���ݿ�

	//
	void initChapter();
	void initStage();
	void initMap();
	void initMapObj();

	//�½��б�
	map<int, TPL_CHAPTER> m_mapChapter;

	//�����б�
	map<int, TPL_STAGE> m_mapStage;


	map<int, PATH_POINT> m_Path;

	map<string, MAP_CELL> m_mapCell;

	//��ͼ
	map<int, TPL_MAP> m_mapMap;

	//��ͼ���
	map<int, TPL_MAP_OBJ> m_mapObj;
};


#endif

