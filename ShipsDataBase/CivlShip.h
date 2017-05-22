#pragma once
#include "CXclass.h"
#include "ship.h"
namespace ShipsDataBase
{
	class CivilShip : public Ship
	{
	private:
		Platform::String^ companyName;

	public:
		CivilShip(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, Platform::String^ companyName,int id) :Ship(nosaukums, valsts, tonnaazza,id)
		{
			this->companyName = companyName;
			

		}
		Platform::String^  getCompanyName() { return companyName; }

	};
}