// Овалы, вписанные в прямоугольники, начальный угол - точка положения курсора мыши в 
// момент нажатия клавиши, рисование происходит при перемещении мыши с нажатой клавишей,
// конечный угол прямоугольника - положение курсора в момент отпускания клавиши.
// Граница «две точки - тире» фиолетового цвета, закраска желтыми наклонными
// диагональными слева-направо и справа-налево линиями. 
// Клавиша «мыши» для рисования - правая.

/*
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

LRESULT CALLBACK WinFun(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int x,y;
	HDC hdc;
	PAINTSTRUCT ps;

	switch(message)
	{
		case WM_MOUSEMOVE:
		if (wParam & MK_RBUTTON)					// Определяем нажатие правой кнопкой мыши
		{
			x=LOWORD(lParam);
			y=HIWORD(lParam);
			hdc=GetDC(hwnd);
			HPEN Pen=CreatePen(PS_DASHDOTDOT, 1, RGB(130,10,130));		// Стиль и цвет границы
			HBRUSH br=CreateHatchBrush(HS_DIAGCROSS, RGB(255,255,0));	// Стиль и цвет штриховки
			SelectObject(hdc, Pen);										// Делаем перо активным
			Ellipse(hdc, x-50, y-20, x+50, y+20);						// Определяем размеры эллипса
			SelectObject(hdc, br);										// Делаем кисть активной
			Ellipse(hdc, x-50, y-20, x+50, y+20);						// Определяем размеры заштрихованной части
			DeleteObject(Pen);											// Удаляем перо
			DeleteObject(br);											// Удаляем кисть
			ReleaseDC(hwnd, hdc);
		}
		break;
		

		EndPaint(hwnd, &ps);						// Заканчиваем рисовать
		break;

		case WM_DESTROY:							// Завершение программы
		PostQuitMessage(0);
		break;
	
	
	default: 
// Позволяет Windows обрабатывать любые сообщения, не указанные в предыдущем случае
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
/*
if (wParam & MK_RBUTTON) // Определяем нажатие правой кнопки мыши
		{
			hdc=GetDC(hwnd);
			x2=LOWORD(lParam);
			y2=HIWORD(lParam);
			SelectObject(hdc, Pen);										// Делаем перо активным
			Ellipse(hdc, x1, y1, x2, y2);								// Определяем размеры эллипса
			
			SelectObject(hdc, br);										// Делаем кисть активной
			Ellipse(hdc, x1, y1, x2, y2);								// Определяем размеры заштрихованной части
			DeleteObject(Pen);											// Удаляем перо
			DeleteObject(br);											// Удаляем кисть
			ReleaseDC(hwnd, hdc);
		}
*/