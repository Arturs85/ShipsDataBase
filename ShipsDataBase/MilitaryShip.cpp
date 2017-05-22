#pragma once
#include "pch.h"
#include "MilitaryShip.h"
//#include "CXclass.h"
namespace ShipsDataBase{

MilitaryShip::MilitaryShip(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, int lielgabali, int missiles, int id) :Ship(nosaukums, valsts, tonnaazza, id)
{
	this->lielgabali = lielgabali;
	this->missiles = missiles;

}
//MilitaryShip::MilitaryShip(CXclass^ i):Ship(i->Nosaukums, i->Valsts, i->Tonnage, i->Id)
//{
	//this->lielgabali = i->Lielgabali;
	//this->missiles = i->Missiles;

//}
}