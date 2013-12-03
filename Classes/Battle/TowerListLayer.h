#ifndef __TOWER_LIST_LAYER_H__
#define __TOWER_LIST_LAYER_H__

#include "cocos2d.h"
#include "GameDataType.h"

USING_NS_CC;

typedef struct  
{
	int idTower;		//防御塔的id
	CCSprite* pSprite;	//防御塔菜单项的图片
	CCRect rc;			//防御塔菜单项矩形框
}ST_TOWER_MENU_ITEM;


class CTowerListLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    CREATE_FUNC(CTowerListLayer);

	void start(CCPoint ptStart, int idMap);

	void showList(CCPoint ptStart);

	void onBtnTowerClick(CCObject* pSrcObj);

private:
	CCSprite* m_pSelectSprite;

	int m_idMap;

	CCPoint m_ptCenter;
	
};

#endif  // __HELLOWORLD_SCENE_H__