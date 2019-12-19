#include "stdafx.h"
#include "Error.h"
namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Недопустимый код ошибки"),
		ERROR_ENTRY(1, "Системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом(-in)"),
		ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола(-log)"),
		ERROR_ENTRY(113, "Обнаружена вторая главная функция"),
		ERROR_ENTRY(114, "Несоответствие типов"),
		ERROR_ENTRY(115, "Запрещено присваивать значение функции"),
		ERROR_ENTRY(116, "Неверное значение"),
		ERROR_ENTRY(117, "Превышен размер таблицы лексем"),
		ERROR_ENTRY(118, "Дополнительная функция распологается ниже главной"), 
		ERROR_ENTRY(119, "Использовваине не инициализированной переменной или идентификатора"),
		ERROR_ENTRY(120, "Правило не найдено"),
		ERROR_ENTRY(121, "Цепочка не найдена"),
		ERROR_ENTRY(122, "Ошибка семантического анализа"),
		ERROR_ENTRY(123, "Неизвестная ошибка"),
		ERROR_ENTRY(124, "Не удалось разобрать слово"),
		ERROR_ENTRY(125, "Переопределение стандартной функции запрещено"),
		ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY(602, "Ошибка в параметрах функции"),
		ERROR_ENTRY(603, "Ошибка в теле функции"),
		ERROR_ENTRY(604, "Ошибка в выражении"),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800)
	};
	ERROR geterror(int id)
	{
		if (id < 0 || id >= ERROR_MAX_ENTRY)	throw ERROR_THROW(0);
		return errors[id];
	};
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		ERROR a = geterror(id);
		a.inext.line = line;
		a.inext.col = col;
		return a;
	};
}