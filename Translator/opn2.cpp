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
//	std::stack<LT::Entry> stack;//���������
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
//					stack.pop();//����� (
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
//	//������� ������� ������
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
//	std::stack<LT::Entry> stack;//���������
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
//					stack.pop();//   ����� (
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
//	//������� ������� ������
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
	
	stack<LT::Entry> stack;		// ���� ��� ��������
	queue<LT::Entry> queue;		// ������� ��� ���������
	LT::Entry temp;		temp.idxTI = -1;	temp.lexema = '#';	temp.sn = -1;	// ����������� �������, ��� ������ �������� ����� ���������� �� ���
	LT::Entry func;		func.idxTI = -1;	func.lexema = '@';	func.sn = -1;	// ������� ��� ������ �������
	int countLex = 0;			// ���������� ��������������� ������
	int countParm = 0;			// ���������� ���������� �������
	int posLex = i;				// ���������� ����� ������� ����� ���������������
	bool findFunc = false;		// ���� ��� �������
	bool findComma = false;		// ���� ��� ������� (���-�� ���������� +2 �����) 
	char* buf = new char[2];	// ����� ��� countParm � ��������� �������������
	for (int i = 0; i < lex.Lextable.size; i++)// ���������� ��������� ��� ������� ���������
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
		case LEX_ID:	// ���� �������������
		{
			if (lex.IDtable.table[lex.Lextable.table[i].idxTI].idtype == IT::F)
				findFunc = true;
			queue.push(lex.Lextable.table[i]);
			continue;
		}
		case LEX_LITERAL:		// ���� �������
		{
			queue.push(lex.Lextable.table[i]);	// �������� � �������
			continue;
		}
		case LEX_LEFTHESIS:		// ���� (
		{
			stack.push(lex.Lextable.table[i]); // �������� �� � ����
			continue;
		}
		case LEX_RIGHTTHESIS:	// ���� )
		{
			if (findFunc)		// ���� ��� ����� �������, �� ������� () ���������� �� @ � ���-�� ����������
			{
				if (findComma)
				{
					countParm++;
				}
				lex.Lextable.table[i] = func;
				queue.push(lex.Lextable.table[i]);		// ��������� � ������� ������� ������ �������
				_itoa_s(countParm, buf, 2, 10);			// �������������� ����� countParm � ������
				stack.top().lexema = buf[0];
				stack.top().idxTI = -1; stack.top().sn = -1;	// ��������� �������, ����������� ���������� ���������� �������
				queue.push(stack.top());				// ��������� � ������� ��� �������
				findFunc = false;
			}
			else {
				while (stack.top().lexema != LEX_LEFTHESIS)	// ���� �� �������� (
				{
					queue.push(stack.top());	// ����������� �� ����� � �������
					stack.pop();

					if (stack.empty())
						return false;
				}
			}
			stack.pop();	// ���������� ( ��� �������, ����������� ���������� ���������� �������
			continue;
		}
		case LEX_OPERATION:	// ���� ���� ���������
		{
			while (!stack.empty() && lex.Lextable.table[i].priority <= stack.top().priority)	// ���� ��������� �������� ��������� 
																								//������ ��� ����� ���������� ��������� � ������� �����
			{
				queue.push(stack.top());	// ����������� �� ����� � �������� ������
				stack.pop();
			}
			stack.push(lex.Lextable.table[i]);
			continue;
		}
		case LEX_COMMA:	// ���� �������
		{
			findComma = true;
			countParm++;
			continue;
		}
		}
	}


	while (!stack.empty())	// ���� ���� �� ������
	{
		if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTTHESIS)
			return false;
		queue.push(stack.top());	// ����������� ��� � �������
		stack.pop();
	}
	while (countLex != 0)		// ������ �������� ��������� � ������� ������ �� ��������� � �����
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
	for (int i = 0; i < posLex; i++)		// �������������� �������� ������� ��������� � ������� ������ � ��������� �� ������� ���������������
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