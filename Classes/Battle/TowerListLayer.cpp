#include "TowerListLayer.h"
#include "GameDefine.h"
#include "BattleScene.h"
#include "DataManager.h"


using namespace cocos2d;
using namespace std;

#define kTagSelectSprite 1000
#define kTagTowerMenu 1001

// on "init" you need to initialize your instance
bool CTowerListLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		CCSpriteFrameCache *pCache =  CCSpriteFrameCache::sharedSpriteFrameCache();
		pCache->addSpriteFrame(CCSpriteFrame::create("select_01.png",CCRectMake(0, 0, 72, 72)),"select_01.png");
		pCache->addSpriteFrame(CCSpriteFrame::create("select_02.png",CCRectMake(0, 0, 72, 72)),"select_02.png");
		pCache->addSpriteFrame(CCSpriteFrame::create("select_03.png",CCRectMake(0, 0, 70, 70)),"select_03.png");
		pCache->addSpriteFrame(CCSpriteFrame::create("select_04.png",CCRectMake(0, 0, 70, 70)),"select_04.png");

		pCache->addSpriteFrame(CCSpriteFrame::create("Bottle00.png",CCRectMake(0, 0, 78, 83)),"Bottle00.png");
		pCache->addSpriteFrame(CCSpriteFrame::create("Bottle01.png",CCRectMake(0, 0, 78, 83)),"Bottle01.png");

		m_pSelectSprite = NULL;

        bRet = true;
    } while (0);

    return bRet;
}

void CTowerListLayer::start( CCPoint ptStart, int idMap )
{
	if (!m_pSelectSprite)
	{
		m_pSelectSprite = CCSprite::createWithSpriteFrameName("select_01.png");

		addChild(m_pSelectSprite, 0, kTagSelectSprite);
		
		CCSpriteFrameCache *pCache =  CCSpriteFrameCache::sharedSpriteFrameCache();
		CCAnimation* pAni = CCAnimation::create();
		CCSpriteFrame* pFrame = pCache->sharedSpriteFrameCache()->spriteFrameByName("select_01.png");
		pAni->addSpriteFrame(pFrame);
		pFrame = pCache->sharedSpriteFrameCache()->spriteFrameByName("select_02.png");
		pAni->addSpriteFrame(pFrame);
		pFrame = pCache->sharedSpriteFrameCache()->spriteFrameByName("select_03.png");
		pAni->addSpriteFrame(pFrame);
		pFrame = pCache->sharedSpriteFrameCache()->spriteFrameByName("select_04.png");
		pAni->addSpriteFrame(pFrame);
		pAni->setDelayPerUnit(0.1f);
		CCActionInterval* pAnimate = CCAnimate::create(pAni);

		CCActionInterval* pRepForever = CCRepeatForever::create((CCActionInterval*)pAnimate);
		
		m_pSelectSprite->runAction(pRepForever);
	}
	m_pSelectSprite->setPosition(ptStart);
	
	m_idMap = idMap;
	m_ptCenter = ptStart;
	showList(ptStart);
}

void CTowerListLayer::showList(CCPoint ptStart)
{
	removeChildByTag(kTagTowerMenu);

	CCMenuItemImage* pTower = CCMenuItemImage::create("Bottle01.png", "Bottle01.png", this, menu_selector(CTowerListLayer::onBtnTowerClick));
	CCMenu* menuHome = CCMenu::create(pTower, NULL);

	menuHome->setPosition(ptStart.x, ptStart.y + pTower->getNormalImage()->getContentSize().height);
	addChild(menuHome, 1, kTagTowerMenu);
	pTower->setScale(0.1f);
	CCActionInterval* pScaleAction = CCScaleTo::create(0.2f, 1.0f);
	pTower->runAction(pScaleAction);
}

void CTowerListLayer::onBtnTowerClick( CCObject* pSrcObj )
{
	((CBattleScene*)getParent())->BuildTower(0, m_ptCenter);
	setVisible(false);
}





















