// Овалы, вписанные в прямоугольники, начальный угол - точка положения курсора мыши в 
// момент нажатия клавиши, рисование происходит при перемещении мыши с нажатой клавишей,
// конечный угол прямоугольника - положение курсора в момент отпускания клавиши.
// Граница «две точки - тире» фиолетового цвета, закраска желтыми наклонными
// диагональными слева-направо и справа-налево линиями. 
// Клавиша «мыши» для рисования - правая.


#include <windows.h>

LRESULT CALLBACK WinFun(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[]=L"Мое окно";						// Имя класса окна
int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
{
	HWND hwnd;										// Дескриптор окна
	MSG msg;										// Содержит инф. о сообщении, посылаемом Windows
	WNDCLASSEX wcl;									// Определяет класс окна
// Определение класса окна
	wcl.hInstance=hIns;								// Дескриптор данного экземпляра
	wcl.lpszClassName=WinName;						// Имя класса
	wcl.lpfnWndProc=WinFun;							// Функция окна
	wcl.style=0;									// стиль по умолчанию
	wcl.cbSize=sizeof(WNDCLASSEX);					// Размер структуры 
	wcl.hIcon=LoadIcon(NULL, IDI_APPLICATION);		// Большая пиктограмма
	wcl.hIconSm=LoadIcon(NULL, IDI_WINLOGO);		// Малая пиктограмма
	wcl.hCursor=LoadCursor(NULL, IDC_ARROW);		// Форма курсора
	wcl.lpszMenuName=NULL;							// Меню не используется
	wcl.cbClsExtra=0;								// Дополнительная информация отсутствует
	wcl.cbWndExtra=0;
// Фон окна задается белым
	wcl.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
// Регистрация класса окна
	if (!RegisterClassEx(&wcl)) return 0;
// Создание окна
	TCHAR title[]=L"Мое простое окно";							
											 
	hwnd=CreateWindow(
		WinName,									// Имя класса окна
		title,										// Заголовок
		WS_OVERLAPPEDWINDOW,						// Стандартное окно
		CW_USEDEFAULT,								// Координата X - определяется Windows 
		CW_USEDEFAULT,								// Координата Y - определяется Windows 
		CW_USEDEFAULT,								// ширина - определяется Windows 
		CW_USEDEFAULT,								// высота - определяется Windows 
		HWND_DESKTOP,								// Родительского окна нет
		NULL,										// Меню нет
        hIns,										// дескриптор данного экземпляра приложения
		NULL);										// дополнительных аргументов нет
// Отображение окна
	ShowWindow(hwnd, WinMode);
	UpdateWindow(hwnd);
// Цикл сообщений
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);						// Разрешает использование клавиатуры
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
// Эта функция вызывается Windows, которая передает ей сообщение из очереди сообщений

struct Ellips
{
	int x1, x2, y1, y2;
};

struct EllipsList // Список
{
	Ellips L;
	EllipsList *pNext;
};

EllipsList *pFirst=0, *p;

void add(EllipsList *&pF, EllipsList *p)
{ // Добавляем элемент в начало списка
	p->pNext=pF;
	pF=p;
}

int x1, x2, y1, y2;

LRESULT CALLBACK WinFun(HWND hwnd, UINT message, 
						WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HPEN Pen=CreatePen(PS_DASHDOTDOT, 1, RGB(130,10,130));		// Стиль и цвет границы
	HBRUSH br=CreateHatchBrush(HS_DIAGCROSS, RGB(255,255,0));	// Стиль и цвет штриховки
			
	switch(message)
	{
	case WM_RBUTTONDOWN:
		x2=x1=LOWORD(lParam);
		y2=y1=HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		if (wParam & MK_RBUTTON)								// Определяем нажатие правой кнопки мыши
		{
			x2=LOWORD(lParam);
			y2=HIWORD(lParam);
		}
		break;
	case WM_RBUTTONUP:											// Отпускаем правую кнопку мыши
		hdc=GetDC(hwnd);
		SelectObject(hdc, Pen);									// Делаем перо активным
		Ellipse(hdc, x1, y1, x2, y2);							// Определяем размеры эллипса
		SelectObject(hdc, br);									// Делаем кисть активной
		Ellipse(hdc, x1, y1, x2, y2);							// Определяем размеры заштрихованной части
		DeleteObject(Pen);										// Удаляем перо
		DeleteObject(br);										// Удаляем кисть
		ReleaseDC(hwnd, hdc);
		
		p=new EllipsList;
		p->L.x1=x1; p->L.x2=x2;
		p->L.y1=y1; p->L.y2=y2;
		add(pFirst, p);
		break;

	//case WM_ERASEBKGND:										// Не стирает рисунок
	case WM_PAINT:												// Перерисовка
		hdc=BeginPaint(hwnd, &ps);
		p=pFirst;
		while(p)												// Просматриваем список и рисуем эллипс
		{
		SelectObject(hdc, Pen);									// Делаем перо активным
		Ellipse(hdc, p->L.x1, p->L.y1, p->L.x2, p->L.y2);		// Определяем размеры эллипса
		SelectObject(hdc, br);									// Делаем кисть активной
		Ellipse(hdc, p->L.x1, p->L.y1, p->L.x2, p->L.y2);		// Определяем размеры заштрихованной части
		p=p->pNext;
		}
		
		EndPaint(hwnd, &ps);
		break;
	
	case WM_DESTROY:											// Завершение программы
		PostQuitMessage(0);
		break;


	default:
// Позволяет Windows обрабатывать любые сообщения, неуказанные в предыдущем случае
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
