// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define LENGTH(x)(sizeof(x)/sizeof(*x))
#include "targetver.h"
#include "iostream"
#include <stdio.h>
#include <tchar.h>
#include <clocale>
#include "Log.h"
#include "Parm.h"
#include "Error.h"
#include <fstream>
#include "In.h"
#include "LexicalAnalysis.h"
bool PolishNotation(int i, LeX::LEX& lex);


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
