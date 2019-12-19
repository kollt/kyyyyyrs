#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	Log::LOG log = Log::INITLOG;
	try
	{																	
		Parm::PARM parm = Parm::getparm(argc, argv);					
		log = Log::getlog(parm.log);									
		Log::LOG out = Log::INITLOG;									
		out = Log::getlog(parm.out);									
		Log::writeLog(log);												
		Log::writeParm(log, parm);										
		In::IN in = In::getin(parm.in, parm.out);						
		Log::Close(log);												
		Log::Close(out);												
	}																	
	catch (Error::ERROR e)
	{
		Log::writeError(log, e);
	}
	return 0;
}

