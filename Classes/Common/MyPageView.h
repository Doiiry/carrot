#ifndef __MY_PAGE_VIEW_H__
#define __MY_PAGE_VIEW_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CMyPageView;

class CMyPageViewDelegate
{
public:
    virtual ~CMyPageViewDelegate() {}
   
    virtual void onPageChange(CMyPageView *table, int oldPage, int newPage) = 0;

};

class CMyPageView : public CCTableView
{
public:
	static CMyPageView* create(CCTableViewDataSource* dataSource, CCSize size, CCNode *container);

	 bool init();

	//����ÿҳҳ����С
    void setPageSize(CCSize& size);

	CCSize getPageSize();

	//����ҳ��
	void setPageCnt(int nPageCnt);

	int getPageCnt();

	//���õ�ǰҳ��
	void setCurPage(int nCurPage);

	//��ȡ��ǰҳ��
	int getCurPage();

	//���÷�ҳ��������
	void setTurnPageOffset(int offset);

	//���õ�һ��������ƫ����
	void setViewOffsetSize(const CCSize& size);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	void setPageDelegate(CMyPageViewDelegate* pDelegate);

protected:
	void adjustScrollView(int offset);

	CCSize m_pageSize;

	int m_nPageCnt;

	int m_nCurPage;

	CCPoint m_touchPoint;

	int m_nPageOffset;

	//���ó�ʼ������
	CCSize m_viewOffsetSize;

	CMyPageViewDelegate* m_pageDelegate;
};

#endif  // __HELLOWORLD_SCENE_H__