#pragma once
#include <pch.h>

//#include <sstream>
//#include <vector>
//#include "MainPage.xaml.h"
namespace ShipsDataBase
{

	
	 class Ship 
	{
	protected:
		//type shipType;
		Platform::String^ nosaukums;
		Platform::String^ valsts;
		int tonnaaza;
		int id;
		
	public:
		virtual Platform::String^ oneLineSummary();
		Ship(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, int id);
	virtual	Platform::String^ getNosaukums() { return this->nosaukums; }
		Platform::String^ getValsts() { return this->valsts; }
		int getTonnage() { return tonnaaza; }
		int getID() { return id; }
	 };
}