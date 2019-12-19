#include "stdafx.h"
#include "LexicalAnalysis.h"
#include <stack>
#include <queue>

//using namespace std;
//int prior(char l)
//{
//	if (l == '+' || l == '-')
//		return 1;
//	if (l == '*' || l == '/')
//		return 2;
//	return 3;
//}
//
//
//
//bool PolishNotation(int i, LeX::LEX& lex)
//{
//	std::stack<LT::Entry> stack;//операциии
//	std::queue<LT::Entry> queue;//ids & literals
//	short marker = i;
//	for (i; lex.Lextable.table[i].lexema != ';'; i++)
//	{
//		if (lex.Lextable.table[i].lexema < 48)//( ) * + - /
//		{
//			if (stack.size() > 0)
//			{
//				if (prior(lex.Lextable.table[i].lexema) <= prior(stack.top().lexema) && lex.Lextable.table[i].lexema != ')' && stack.top().lexema != '(')
//				{
//					queue.push(stack.top());
//					stack.pop();
//					stack.push(lex.Lextable.table[i]);
//				}
//				else if (prior(lex.Lextable.table[i].lexema) > prior(stack.top().lexema) && lex.Lextable.table[i].lexema != ')' && lex.Lextable.table[i].lexema != '(')
//				{
//					stack.push(lex.Lextable.table[i]);
//				}
//				else if (lex.Lextable.table[i].lexema == ')')
//				{
//					while (stack.top().lexema != '(')
//					{
//						queue.push(stack.top());
//						stack.pop();
//					}
//					stack.pop();//удалю (
//				}
//				else
//				{
//					stack.push(lex.Lextable.table[i]);
//				}
//			}
//			else
//			{
//				stack.push(lex.Lextable.table[i]);
//			}
//		}
//		if (lex.Lextable.table[i].lexema >= 48 && lex.Lextable.table[i].lexema <= 122)
//		{
//			queue.push(lex.Lextable.table[i]);
//		}
//	}
//	while (stack.size() != 0)
//	{
//		queue.push(stack.top());
//		stack.pop();
//	}
//	//измен€ю таблицу лексем
//	for (marker; marker < i; marker++)
//	{
//		if (!queue.empty())
//		{
//			lex.Lextable.table[marker] = queue.front();
//			queue.pop();
//		}
//		else
//
//		{
//			lex.Lextable.table[marker].idxTI = -1;
//			lex.Lextable.table[marker].lexema = '#';
//			lex.Lextable.table[marker].sn = -1;
//			lex.Lextable.table[marker].priority = -3;
//		}
//	}
//	return true;
//}
//using namespace std;

//int prior(char l)
//{
//	if (l == '+' || l == '-')
//		return 1;
//	if (l == '*' || l == '/')
//		return 2;
//	return 3;
//}

//bool PolishNotation(int i, LeX::LEX& lex)
//{
//	std::stack<LT::Entry> stack;//операциии
//	std::queue<LT::Entry> queue;//ids & literals
//	int marker = i;
//	for (i; lex.Lextable.table[i].lexema != LEX_SEPARATOR; i++)
//	{
//		if (lex.Lextable.table[i].lexema < 48)//( ) * + - /
//		{
//			if (stack.size() > 0)
//			{
//				if (prior(lex.Lextable.table[i].lexema) <= prior(stack.top().lexema) && lex.Lextable.table[i].lexema != LEX_RIGHTTHESIS && stack.top().lexema != LEX_LEFTHESIS)
//				{
//					queue.push(stack.top());
//					stack.pop();
//					stack.push(lex.Lextable.table[i]);
//				}
//				else if (prior(lex.Lextable.table[i].lexema) > prior(stack.top().lexema) && lex.Lextable.table[i].lexema != LEX_RIGHTTHESIS && lex.Lextable.table[i].lexema != LEX_LEFTHESIS)
//				{
//					stack.push(lex.Lextable.table[i]);
//				}
//				else if (lex.Lextable.table[i].lexema == LEX_RIGHTTHESIS)
//				{
//					while (stack.top().lexema != LEX_LEFTHESIS)
//					{
//						queue.push(stack.top());
//						stack.pop();
//					}
//					stack.pop();//   удалю (
//				}
//				else
//				{
//					stack.push(lex.Lextable.table[i]);
//				}
//			}
//			else
//			{
//				stack.push(lex.Lextable.table[i]);
//			}
//		}
//		if (lex.Lextable.table[i].lexema == LEX_LITERAL || lex.Lextable.table[i].lexema == LEX_ID)
//		{
//			queue.push(lex.Lextable.table[i]);
//		}
//	}
//	while (stack.size() != 0)
//	{
//		queue.push(stack.top());
//		stack.pop();
//	}
//	//измен€ю таблицу лексем
//	for (marker; marker < i; marker++)
//	{
//		if (!queue.empty())
//		{
//			lex.Lextable.table[marker] = queue.front();
//			queue.pop();
//		}
//		else
//
//		{
//			lex.Lextable.table[marker].idxTI = -1;
//			lex.Lextable.table[marker].lexema = '#';
//			lex.Lextable.table[marker].sn = -1;
//			lex.Lextable.table[marker].priority = -3;
//		}
//	}
//	return true;
//}
int prior(char znak)
{
	switch (znak)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default:
		return 0;
	}
}
bool PolishNotation(int i, LeX::LEX& lex)
{
	
	stack<LT::Entry> stack;		// стек дл€ операций
	queue<LT::Entry> queue;		// очередь дл€ операндов
	LT::Entry temp;		temp.idxTI = -1;	temp.lexema = '#';	temp.sn = -1;	// запрещенна€ лексема, все лишние элементы будут замен€тьс€ на нее
	LT::Entry func;		func.idxTI = -1;	func.lexema = '@';	func.sn = -1;	// лексема дл€ вызова функции
	int countLex = 0;			// количество преобразованных лексем
	int countParm = 0;			// количество параметров функции
	int posLex = i;				// запоминаем номер лексемы перед преобразованием
	bool findFunc = false;		// флаг дл€ функции
	bool findComma = false;		// флаг дл€ зап€той (кол-во параметров +2 сразу) 
	char* buf = new char[2];	// буфер дл€ countParm в строковом представлении
	for (int i = 0; i < lex.Lextable.size; i++)// определ€ем приоритет дл€ каждого оператора
	{
		if (lex.Lextable.table[i].lexema == LEX_LEFTHESIS || lex.Lextable.table[i].lexema == LEX_RIGHTTHESIS)
			lex.Lextable.table[i].priority = 0;
		if (lex.Lextable.table[i].lexema == LEX_COMMA)
			lex.Lextable.table[i].priority = 1;
		if (lex.Lextable.table[i].operation == LEX_PLUS || lex.Lextable.table[i].operation == LEX_MINUS)
			lex.Lextable.table[i].priority = 2;
		if (lex.Lextable.table[i].operation == LEX_STAR || lex.Lextable.table[i].operation == LEX_DIRSLASH)
			lex.Lextable.table[i].priority = 3;
	}
	for (i; lex.Lextable.table[i].lexema != LEX_SEPARATOR; i++, countLex++)
	{
		switch (lex.Lextable.table[i].lexema)
		{
		case LEX_ID:	// если идентификатор
		{
			if (lex.IDtable.table[lex.Lextable.table[i].idxTI].idtype == IT::F)
				findFunc = true;
			queue.push(lex.Lextable.table[i]);
			continue;
		}
		case LEX_LITERAL:		// если литерал
		{
			queue.push(lex.Lextable.table[i]);	// помещаем в очередь
			continue;
		}
		case LEX_LEFTHESIS:		// если (
		{
			stack.push(lex.Lextable.table[i]); // помещаем ее в стек
			continue;
		}
		case LEX_RIGHTTHESIS:	// если )
		{
			if (findFunc)		// если это вызов функции, то лексемы () замен€ютс€ на @ и кол-во параметров
			{
				if (findComma)
				{
					countParm++;
				}
				lex.Lextable.table[i] = func;
				queue.push(lex.Lextable.table[i]);		// добавл€ем в очередь лексему вызова функции
				_itoa_s(countParm, buf, 2, 10);			// преобразование числа countParm в строку
				stack.top().lexema = buf[0];
				stack.top().idxTI = -1; stack.top().sn = -1;	// заполн€ем лексему, указывающую количество параметров функции
				queue.push(stack.top());				// добавл€ем в очередь эту лексему
				findFunc = false;
			}
			else {
				while (stack.top().lexema != LEX_LEFTHESIS)	// пока не встретим (
				{
					queue.push(stack.top());	// выталкиваем со стека в очередь
					stack.pop();

					if (stack.empty())
						return false;
				}
			}
			stack.pop();	// уничтожаем ( или лексему, указывающую количество параметров функции
			continue;
		}
		case LEX_OPERATION:	// если знак оператора
		{
			while (!stack.empty() && lex.Lextable.table[i].priority <= stack.top().priority)	// пока приоритет текущего оператора 
																								//меньше или равен приоритету оператора в вершине стека
			{
				queue.push(stack.top());	// выталкиваем со стека в выходную строку
				stack.pop();
			}
			stack.push(lex.Lextable.table[i]);
			continue;
		}
		case LEX_COMMA:	// если зап€та€
		{
			findComma = true;
			countParm++;
			continue;
		}
		}
	}


	while (!stack.empty())	// если стек не пустой
	{
		if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTTHESIS)
			return false;
		queue.push(stack.top());	// выталкиваем все в очередь
		stack.pop();
	}
	while (countLex != 0)		// замена текущего выражени€ в таблице лексем на выражение в ѕќЋ»«
	{
		if (!queue.empty()) {
			lex.Lextable.table[posLex++] = queue.front();
			queue.pop();
		}
		else
		{
			lex.Lextable.table[posLex++] = temp;
		}
		countLex--;
	}
	for (int i = 0; i < posLex; i++)		// восстановление индексов первого вхождени€ в таблицу лексем у литералов из таблицы идентификаторов
	{
		if (lex.Lextable.table[i].lexema == LEX_LITERAL)
			lex.IDtable.table[lex.Lextable.table[i].idxTI].idxfirstLE = i;
	}
	return true;
}
//#include "stdafx.h"
//#include "LexicalAnalysis.h"
//#include <stack>
//#include <queue>