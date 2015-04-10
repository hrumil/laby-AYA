// Win32Project3.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "stdafx.h"
#include "Win32Project3.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "resource.h"
#include <math.h>
#define _USE_MATH_DEFINES
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);




//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT3);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: добавьте любой код отрисовки...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
BOOL CALLBACK DialogFun(HWND hwnd, UINT message, 
						WPARAM wParam, LPARAM lParam)
{
	char Text[64];
	double x, y;
	switch(message)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hwnd, LOWORD(wParam));
			return TRUE;

		case IDC_BUTTON1: // Обработка сообщения от кнопки вычисления арктангенса
		case IDC_BUTTON2: // Обработка сообщения от кнопки вычисления арккотангенса
		
			
			SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)Text); // Получить текст из текстового поля и записать в массив Text
			if (sscanf_s(Text, "%lf", &x)<1)		
			{
				MessageBox(hwnd, "Неверный формат операнда", 
"Ошибка формата", MB_OK | MB_ICONHAND);
				return TRUE;
			}
	
			sscanf_s(Text, "%lf", &x);			
			if (LOWORD(wParam)==IDC_BUTTON2) 
			{ 
				y=(atan(x))*180/M_PI; 
				sprintf_s(Text, "%f", y);
				SendDlgItemMessage(hwnd, IDC_EDIT2, WM_SETTEXT, 0, (LPARAM)Text); // Помещаем текст из массива в текстовое поле
				sprintf_s(Text, "arctn(%f) = %f", x, y);
				SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)Text);
				return TRUE;
			}
			if (LOWORD(wParam)==IDC_BUTTON1) 
			{ 
				y=(M_PI_2 - (atan(x)))*180/M_PI;
				sprintf_s(Text, "%f", y);
				SendDlgItemMessage(hwnd, IDC_EDIT2, WM_SETTEXT, 0, (LPARAM)Text); // Помещаем текст из массива в текстовое поле
				sprintf_s(Text, "arcctn(%f) = %f", x, y);
				SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)Text);
				return TRUE;
			}
	
		case IDC_BUTTON3: // Обработка сообщения от кнопки "Очистить список"
			SendDlgItemMessage(hwnd, IDC_LIST1, LB_RESETCONTENT, 0, 0);
			return TRUE;

		}
		
	}
	return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogFun);
	
	return 0;
}
