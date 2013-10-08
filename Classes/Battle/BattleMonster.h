#ifndef __BATTLEMONSTER_H__
#define __BATTLEMONSTER_H__

#include "GameDataType.h"
#include "cocos2d.h"

USING_NS_CC;

class CBattleMonster: public CCSprite
{
public:
	static CBattleMonster* create();

	virtual bool initWithSpriteFrame(CCSpriteFrame *pSpriteFrame);

	virtual bool initWithSpriteFrameName(const char *pszSpriteFrameName);

	//���ù�����Ϣ

	virtual bool init(void);

	void MoveToNext(int idxCur);

	//�ƶ�һ������
	void OnMoveStepOver(CCNode* pObj, void* pParam);
	
	//�ƶ����
	void OnMoveOver();

	void ShowHp(float nHp);

protected:
	CCProgressTimer* m_pProHp;
	CCSprite* m_pProHpBg;
};


#endif

