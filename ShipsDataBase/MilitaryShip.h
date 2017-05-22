#pragma once
#include "Ship.h"

namespace ShipsDataBase
{
	class Ship;
	  class MilitaryShip: public Ship 
	{
	private:
		int lielgabali;
		int missiles;
	
	public:
		MilitaryShip(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, int lielgabali, int missiles, int id); //:Ship(nosaukums, valsts, tonnaazza,id)
		//MilitaryShip(CXclass^ i);
		int getLielgabali() { return lielgabali; }
		int getMissiles() { return missiles; }

	};
}