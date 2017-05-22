#pragma once
#include "CXclass.h"

namespace ShipsDataBase{

 public ref class ShipViewModel sealed
{
private:
	//Ship^ defaultRecording;
	Windows::Foundation::Collections::IVector<CXclass^>^ ships;

public:
	ShipViewModel()
	{

	
	}
	
	
	property Windows::Foundation::Collections::IVector<CXclass^>^ Ships
	{
	Windows::Foundation::Collections::IVector<CXclass^>^ get()
	{
			if (this->ships == nullptr)
			{
			this->ships = ref new Platform::Collections::Vector<CXclass^>();
			}
			return this->ships;
		};
	}

};
}
