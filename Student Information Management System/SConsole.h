
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "windows.h"	// HANDLE
#include <cstdio>		// sprintf

class Console
{
private://˽�г�Ա
	COORD coord;
	HANDLE HConsole;

public://�ⲿ�ӿ�
	Console();	//���캯��
	~Console();//��������

	void SetCoord(int x, int y);		//���������λ��
	void HideCursor(bool hide);			//��꿪����ر�
	void SetTitle(const char* title);	//���ñ�������
	void SetSize(int width, int height);//���ÿ���̨��С
	void SetColor(const char* cl);		//������ɫ
	void CleanScreen(void);				//����
	void PauseScreen(void);				//������Ļ

	//��Ԫ��������
	//friend void Introduction();			//������Ϣ����
};

#endif  //__CONSOLE_H__