
// TEST07View.h: CTEST07View 类的接口
//

#pragma once


class CTEST07View : public CView
{
protected: // 仅从序列化创建
	CTEST07View() noexcept;
	DECLARE_DYNCREATE(CTEST07View)

// 特性
public:
	CTEST07Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTEST07View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnMDrawCircle();
	afx_msg void Clean(); 
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	void DrawCircle(CDC* pDC, int x, int y, int r);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawRec();
};

#ifndef _DEBUG  // TEST07View.cpp 中的调试版本
inline CTEST07Doc* CTEST07View::GetDocument() const
   { return reinterpret_cast<CTEST07Doc*>(m_pDocument); }
#endif

