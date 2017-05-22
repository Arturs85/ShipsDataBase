#pragma once
#include <pch.h>
#include "MilitaryShip.h"
#include <sstream>
#include <vector>
#include "MainPage.xaml.h"
namespace ShipsDataBase
{
	public enum class ShipType : int { MIL, CIV };

	[Windows::UI::Xaml::Data::Bindable]
	public	ref class CXclass sealed
	{
	private:
		ShipType shipType;
		Platform::String^ nosaukums;
		Platform::String^ valsts;
		int tonnaaza;
		int id;
		int missiles;
		int lielgabali;

		Platform::String^ companyName="";
		Platform::String^ oneLineSummary="";

	public:
		CXclass(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, Platform::String^ companyName, int id) :
			nosaukums{ nosaukums },
			valsts{ valsts },
			tonnaaza{ tonnaazza },
			companyName{ companyName }
		{
			missiles = 0;
			lielgabali = 0;
			shipType = ShipType::CIV;
			this->id = id;
			std::wstringstream wstringstream;
			//wstringstream << this->Nosaukums->Data();

			//wstringstream << L" valsts: " << this->Valsts->Data();
			wstringstream << L" Tonnâþa: " << this->Tonnage;
			wstringstream << L", Kompânijas nosaukums: " << this->CompanyName->Data();
			
			oneLineSummary = ref new Platform::String(wstringstream.str().c_str());
		}
	//	CXclass(MilitaryShip* source)
		///{
			///nosaukums = source->getNosaukums();
			//valsts = source->getValsts();
			//missiles = source->getMissiles();
			//lielgabali = source->getLielgabali();
			//shipType = type::CIV;
		//}
		CXclass(Platform::String^ nosaukums, Platform::String^ valsts, int tonnaazza, int lielgabali, int missiles, int id) :
			nosaukums{ nosaukums },
			valsts{ valsts },
			tonnaaza{ tonnaazza },
			lielgabali{ lielgabali },
			missiles{ missiles }
		{
			companyName = "";
			shipType = ShipType::MIL;
			this->id = id;
			std::wstringstream wstringstream;
		//wstringstream << this->Nosaukums->Data();

		//wstringstream << L" valsts: " << this->Valsts->Data();
		wstringstream << L" Tonnâþa: " << this->Tonnage;
		wstringstream << L", Lielgabali: " << this->lielgabali;
		wstringstream << L", Raíetes: " << this->missiles;
		oneLineSummary = ref new Platform::String(wstringstream.str().c_str());
		
		
		}





		//Platform::String^ Nosaukums() { return this->nosaukums; }
		//Platform::String^ Valsts() { return this->valsts; }
		property ShipType SType {
			ShipType get() { return this->shipType; }
		}
		
property Platform::String^ Nosaukums
		{
			Platform::String^ get() { return this->nosaukums; }

		}
		property Platform::String^ Valsts
		{
			Platform::String^ get() { return this->valsts; }
		}
		property int Tonnage
		{
			int get() { return this->tonnaaza; }
		}
		property int Id
		{
			int get() { return this->id; }
		}
		property int Lielgabali
		{
			int get() { return this->lielgabali; }
		}
		property int Missiles
		{
			int get() { return this->missiles; }
		}
		property  Platform::String^ CompanyName {
			Platform::String^ get() { return this->companyName; }
		}
		property Platform::String^ OneLineSummary
		{
			Platform::String^ get()
			{
				return oneLineSummary;
			}
		}
	};
}