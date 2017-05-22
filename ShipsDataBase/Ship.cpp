#include "pch.h"
#include "Ship.h"
#include <sstream>

namespace ShipsDataBase
{
	Platform::String ^ Ship::oneLineSummary()
	{
		std::wstringstream wstringstream;
		wstringstream << this->nosaukums->Data();

		wstringstream << L" Valsts: " << this->valsts->Data();
		wstringstream << L", tonnâþa: " << this->tonnaaza;

		return ref new Platform::String(wstringstream.str().c_str());	// TODO: insert return statement here
	}
	Ship::Ship(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, int id)
		{
		this->nosaukums = nosaukums;
		this->valsts = valsts;
		this->tonnaaza = tonnaazza;
		this->id = id;
	
	}
}