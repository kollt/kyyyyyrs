// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
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


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
