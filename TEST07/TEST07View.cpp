
// TEST07View.cpp: CTEST07View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TEST07.h"
#endif

#include "TEST07Doc.h"
#include "TEST07View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTEST07View

IMPLEMENT_DYNCREATE(CTEST07View, CView)

BEGIN_MESSAGE_MAP(CTEST07View, CView)
	// 标准打印命令
	ON_COMMAND(ID_32771, OnMDrawCircle)
	ON_COMMAND(ID_APP_ABOUT, Clean)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTEST07View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32772, &CTEST07View::OnDrawRec)
END_MESSAGE_MAP()

// CTEST07View 构造/析构

CTEST07View::CTEST07View() noexcept
{
	// TODO: 在此处添加构造代码

}

CTEST07View::~CTEST07View()
{
}

BOOL CTEST07View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTEST07View 绘图

void CTEST07View::OnDraw(CDC* pDC/*pDC*/)
{
	CTEST07Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(), rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(), -rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//客户区中心为坐标系原点
	//绘制坐标轴
	CPen NewPen, * pOldPen;
	NewPen.CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(-rect.right / 2, 0);//绘制x轴
	pDC->LineTo(rect.right / 2, 0);
	pDC->MoveTo(rect.right / 2 - 10, 5);//绘制右箭头　
	pDC->LineTo(rect.right / 2, 0);
	pDC->LineTo(rect.right / 2 - 10, -5);
	pDC->LineTo(rect.right / 2, 0);
	pDC->TextOut(rect.right / 2 - 20, 30, (CString)"x");
	pDC->MoveTo(0, -rect.bottom / 2);//绘制y轴
	pDC->LineTo(0, rect.bottom / 2);
	pDC->MoveTo(-5, rect.bottom / 2 - 10);//绘制上箭头
	pDC->LineTo(0, rect.bottom / 2);
	pDC->LineTo(5, rect.bottom / 2 - 10);
	pDC->LineTo(0, rect.bottom / 2);
	pDC->TextOut(-30, rect.bottom / 2 - 20, (CString)"y");
	pDC->TextOut(-20, -10, (CString)"O");
	// TODO: 在此处为本机数据添加绘制代码
}


// CTEST07View 打印
void CTEST07View::OnMDrawCircle()
{
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(), rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(), -rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//客户区中心为坐标系原点
	DrawCircle(pDC, 100, 100, 100);
}

void CTEST07View::Clean()
{
	RedrawWindow();
}

void CTEST07View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTEST07View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTEST07View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTEST07View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CTEST07View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTEST07View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

void CTEST07View::DrawCircle(CDC* pDC, int x, int y, int r) {
	CPen pen, * oldpen;
	oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(x - r, y - r, x + r, y + r);
	pDC->SelectObject(oldpen);
}

// CTEST07View 诊断

#ifdef _DEBUG
void CTEST07View::AssertValid() const
{
	CView::AssertValid();
}

void CTEST07View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTEST07Doc* CTEST07View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTEST07Doc)));
	return (CTEST07Doc*)m_pDocument;
}
#endif //_DEBUG



// CTEST07View 消息处理程序


void CTEST07View::OnDrawRec()
{

	// TODO: 在此添加命令处理程序代码

}
