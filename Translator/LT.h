#pragma once

#include"Error.h"
#include <string>

#define	LEXEMA_FIXSIZE	1			// ������������� ������ ������� ������
#define	LT_MAXSIZE		65536		// ������������ ������ ������� ������
#define	LT_TI_NULLDX	0xffffffff	// ������� � ������� ������
#define	LEX_INT			't'			// �����
#define	LEX_STRING		't'			// ������
#define LEX_OBJECT      't'			// ������						
#define	LEX_ID			'i'			// ��������������
#define	LEX_LITERAL		'l'			// �������
#define	LEX_FUNCTION	'f'			// �������
#define	LEX_DECLARE		'd'			// Declare
#define LEX_STRLEN      'e'         // ���������������� ��� 1
#define LEX_SUBSTR      's'         // ���������������� ��� 2
#define	LEX_RETURN		'r'			// Return
#define	LEX_PRINT		'p'			// Print
#define	LEX_MAIN		'm'			// Main
#define	LEX_SEPARATOR	';'			// ;
#define	LEX_COMMA		','			// ,
#define	LEX_LEFTBRACE	'{'			// {
#define	LEX_BRACELET	'}'			// }
#define	LEX_LEFTHESIS	'('			// (
#define	LEX_RIGHTTHESIS	')'			// )
#define	LEX_PLUS		'+'			// +
#define	LEX_MINUS		'-'			// -
#define	LEX_STAR		'*'			// *
#define	LEX_DIRSLASH	'/'			// /
#define	LEX_EQUAL		'='			// =
#define	LEX_OPERATION	'v'			// v
#define	LEX_TYPE_INT	    "integer"	
#define	LEX_TYPE_STRING	    "string"	
#define	LEX_TYPE_FUNCTION	"function"	
#define	LEX_TYPE_VARIABLE	"variable"	
#define LEX_TYPE_PARAMETR	"parametr"	
#define LEX_TYPE_LITERAL	"literal"
#define LEX_TYPE_STANDART	"standart"
namespace LT						
{
	struct Entry
	{
		char lexema;			// �������
		int sn;					// ����� ������ � �������� ������
		int idxTI;				// ������ � ������� ��������������� ��� LT_TI_NULLIDX
		
		int tokenId = 0;		
		char operation;			
		std::string value;		
		Entry() {};				
		Entry(char lexema, int snn, int idxti = LT_TI_NULLDX);		
		Entry(char lexema, int snn, char v, int idxti = LT_TI_NULLDX);
		int priority;
	};

	struct LexTable						// ��������� ������� ������
	{
		int maxsize;					// ������� ������� ������
		int size;						// ������� ������ ������� ������
		Entry* table;	                // ������ ����� ������� ������
	};
	LexTable Create(int size);			// ������� < LT_MAXSIZE
	void Add(LexTable &lextable, Entry entry);	// ��������� ������� ������, ������ ������� ������
	Entry GetEntry(LexTable &lextable, int n);	// ��������� ������� ������, ����� ���������� ������
	void Delete(LexTable &lextable);	// ������� ������� ������ (���������� ������)

	struct LIT {
		std::string name[65];
        std::string literals[65];
	    std::string typel[65];
	};
}