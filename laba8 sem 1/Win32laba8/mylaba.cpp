// �����, ��������� � ��������������, ��������� ���� - ����� ��������� ������� ���� � 
// ������ ������� �������, ��������� ���������� ��� ����������� ���� � ������� ��������,
// �������� ���� �������������� - ��������� ������� � ������ ���������� �������.
// ������� ���� ����� - ���� ����������� �����, �������� ������� ����������
// ������������� �����-������� � ������-������ �������. 
// ������� ����� ��� ��������� - ������.


#include <windows.h>

LRESULT CALLBACK WinFun(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[]=L"��� ����";						// ��� ������ ����
int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
{
	HWND hwnd;										// ���������� ����
	MSG msg;										// �������� ���. � ���������, ���������� Windows
	WNDCLASSEX wcl;									// ���������� ����� ����
// ����������� ������ ����
	wcl.hInstance=hIns;								// ���������� ������� ����������
	wcl.lpszClassName=WinName;						// ��� ������
	wcl.lpfnWndProc=WinFun;							// ������� ����
	wcl.style=0;									// ����� �� ���������
	wcl.cbSize=sizeof(WNDCLASSEX);					// ������ ��������� 
	wcl.hIcon=LoadIcon(NULL, IDI_APPLICATION);		// ������� �����������
	wcl.hIconSm=LoadIcon(NULL, IDI_WINLOGO);		// ����� �����������
	wcl.hCursor=LoadCursor(NULL, IDC_ARROW);		// ����� �������
	wcl.lpszMenuName=NULL;							// ���� �� ������������
	wcl.cbClsExtra=0;								// �������������� ���������� �����������
	wcl.cbWndExtra=0;
// ��� ���� �������� �����
	wcl.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
// ����������� ������ ����
	if (!RegisterClassEx(&wcl)) return 0;
// �������� ����
	TCHAR title[]=L"��� ������� ����";							
											 
	hwnd=CreateWindow(
		WinName,									// ��� ������ ����
		title,										// ���������
		WS_OVERLAPPEDWINDOW,						// ����������� ����
		CW_USEDEFAULT,								// ���������� X - ������������ Windows 
		CW_USEDEFAULT,								// ���������� Y - ������������ Windows 
		CW_USEDEFAULT,								// ������ - ������������ Windows 
		CW_USEDEFAULT,								// ������ - ������������ Windows 
		HWND_DESKTOP,								// ������������� ���� ���
		NULL,										// ���� ���
        hIns,										// ���������� ������� ���������� ����������
		NULL);										// �������������� ���������� ���
// ����������� ����
	ShowWindow(hwnd, WinMode);
	UpdateWindow(hwnd);
// ���� ���������
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);						// ��������� ������������� ����������
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
// ��� ������� ���������� Windows, ������� �������� �� ��������� �� ������� ���������

struct Ellips
{
	int x1, x2, y1, y2;
};

struct EllipsList // ������
{
	Ellips L;
	EllipsList *pNext;
};

EllipsList *pFirst=0, *p;

void add(EllipsList *&pF, EllipsList *p)
{ // ��������� ������� � ������ ������
	p->pNext=pF;
	pF=p;
}

int x1, x2, y1, y2;

LRESULT CALLBACK WinFun(HWND hwnd, UINT message, 
						WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HPEN Pen=CreatePen(PS_DASHDOTDOT, 1, RGB(130,10,130));		// ����� � ���� �������
	HBRUSH br=CreateHatchBrush(HS_DIAGCROSS, RGB(255,255,0));	// ����� � ���� ���������
			
	switch(message)
	{
	case WM_RBUTTONDOWN:
		x2=x1=LOWORD(lParam);
		y2=y1=HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		if (wParam & MK_RBUTTON)								// ���������� ������� ������ ������ ����
		{
			x2=LOWORD(lParam);
			y2=HIWORD(lParam);
		}
		break;
	case WM_RBUTTONUP:											// ��������� ������ ������ ����
		hdc=GetDC(hwnd);
		SelectObject(hdc, Pen);									// ������ ���� ��������
		Ellipse(hdc, x1, y1, x2, y2);							// ���������� ������� �������
		SelectObject(hdc, br);									// ������ ����� ��������
		Ellipse(hdc, x1, y1, x2, y2);							// ���������� ������� �������������� �����
		DeleteObject(Pen);										// ������� ����
		DeleteObject(br);										// ������� �����
		ReleaseDC(hwnd, hdc);
		
		p=new EllipsList;
		p->L.x1=x1; p->L.x2=x2;
		p->L.y1=y1; p->L.y2=y2;
		add(pFirst, p);
		break;

	//case WM_ERASEBKGND:										// �� ������� �������
	case WM_PAINT:												// �����������
		hdc=BeginPaint(hwnd, &ps);
		p=pFirst;
		while(p)												// ������������� ������ � ������ ������
		{
		SelectObject(hdc, Pen);									// ������ ���� ��������
		Ellipse(hdc, p->L.x1, p->L.y1, p->L.x2, p->L.y2);		// ���������� ������� �������
		SelectObject(hdc, br);									// ������ ����� ��������
		Ellipse(hdc, p->L.x1, p->L.y1, p->L.x2, p->L.y2);		// ���������� ������� �������������� �����
		p=p->pNext;
		}
		
		EndPaint(hwnd, &ps);
		break;
	
	case WM_DESTROY:											// ���������� ���������
		PostQuitMessage(0);
		break;


	default:
// ��������� Windows ������������ ����� ���������, ����������� � ���������� ������
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
