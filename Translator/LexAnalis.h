#pragma once
#include "stdafx.h"
#include  "FST.h"
#include "IT.h"
#include "LT.h"

namespace Lex
{
	struct LEX
	{
		LT::LexTable LEXTAB;
		IT::IdTable	IDTAB;
	};
	struct Graph
	{
		char lexema;
		FST::FST graph;
	};

	LEX INITLEX(In::IN, Log::LOG &log);
}