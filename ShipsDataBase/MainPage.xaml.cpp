//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <sqlite3.h>
#include "DatabaseHelper.h"
#include "CivlShip.h"
class Ship;
using namespace ShipsDataBase;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace std;
//using namespace System::Data::SQLite;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409
//sqlite3 *testDB;

MainPage::MainPage()
{
	InitializeComponent();
	this->viewModel = ref new ShipViewModel();
	this->databaseHelper = new DatabaseHelper();

}

struct compareMyObjectByNumber { //sorting
	bool operator ()(CXclass^ left, CXclass^ right) const {
		return left->Tonnage < right->Tonnage;
	}
};
struct compareMyObjectByName { //sorting
	bool operator ()(CXclass^ left, CXclass^ right) const {
		return left->Nosaukums < right->Nosaukums;
	}
};
struct compareMyObjectByValsts { //sorting
	bool operator ()(CXclass^ left, CXclass^ right) const {
		return left->Valsts < right->Valsts;
	}
};

void ShipsDataBase::MainPage::refreshList()
{
	vector<Ship*> ships = *databaseHelper->getData();
	civilShipCount = militaryShipCount = 0;
	viewModel->Ships->Clear();
	for (Ship *p : ships) {
		if (MilitaryShip* militaryShip = dynamic_cast<MilitaryShip*>(p))//ir military
		{
			MainPage::LogMessage("Military Ship, converting for binding");
			viewModel->Ships->Append(ref new CXclass{ p->getNosaukums(), p->getValsts(),p->getTonnage() ,militaryShip->getLielgabali(),militaryShip->getMissiles(),p->getID() });
			militaryShipCount++;
		}
		else if (CivilShip* civilShip = dynamic_cast<CivilShip*>(p))//ir civil
		{
			MainPage::LogMessage("Civil Ship, converting for binding");
			viewModel->Ships->Append(ref new CXclass{ p->getNosaukums(), p->getValsts(),p->getTonnage() ,civilShip->getCompanyName(),p->getID() });
			civilShipCount++;
		}

	}
	 statusText = L"Military Ships: " +militaryShipCount +L" Civil Ships: "+civilShipCount;
	textBlock->Text = statusText;

}

void ShipsDataBase::MainPage::appBarButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Windows::Storage::StorageFolder^ f = Windows::Storage::ApplicationData::Current->LocalFolder;

	//databaseHelper->create();	
	databaseHelper->open();
	refreshList();
}


void ShipsDataBase::MainPage::appBarButton1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Platform::String^ a;
	if (sortNumber == 0)
	{
		std::sort(begin(viewModel->Ships), end(viewModel->Ships), compareMyObjectByNumber());
		a = "Tonnage";
	}
	if (sortNumber == 1)
	{
		std::sort(begin(viewModel->Ships), end(viewModel->Ships), compareMyObjectByName());
		a = "Name";
	}
	if (sortNumber == 2)
	{
		std::sort(begin(viewModel->Ships), end(viewModel->Ships), compareMyObjectByValsts());
		a = "Country";
	}
		sortNumber++;
	if (sortNumber > 2)sortNumber = 0;
	Platform::String^ additionText = L" Ordered by " + a;

	textBlock->Text = statusText+additionText;
}

void MainPage::LogMessage(Object ^ parameter)
 {
 	auto paraString = parameter->ToString();
 	auto formattedText = std::wstring(paraString->Data()).append(L"\r\n");
 	OutputDebugString(formattedText.c_str());
 }



void ShipsDataBase::MainPage::appBarButtonSave_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (selectedItem != nullptr)
	{
		Ship* ship = nullptr;
		if (selectedItem->Id >= 0) //update
	{
			Platform::String^ nosaukums = nosaukumsText->Text;
			Platform::String^ valsts = valstsText->Text;
			Platform::String^ companyName = companyNameText->Text;

			int tonnage = _wtoi(tonnageText->Text->Data());
			int lielgabali = _wtoi(lielgabaliText->Text->Data());
			int missiles = _wtoi(missilesText->Text->Data());

			if (selectedItem->SType == ShipType::MIL)//military
		{
			ship = new MilitaryShip(nosaukums, valsts, tonnage, lielgabali, missiles, selectedItem->Id);
		}
			else 	if (selectedItem->SType == ShipType::CIV)//civil
			{
				LogMessage("civil ship update starting");
				ship = new CivilShip(nosaukums, valsts, tonnage, companyName, selectedItem->Id);
			}
			
			LogMessage(ship->getNosaukums());
		databaseHelper->update(ship);
		delete ship;
		refreshList();
	}
}
}



void ShipsDataBase::MainPage::listView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (selectedItem = dynamic_cast<CXclass^>(listView->SelectedItem))
	{
		//textBlock->Text = selectedItem->Id.ToString();
		//textBlock->Text += " selection changed";
	
	}

}


void ShipsDataBase::MainPage::appBarButtonDelete_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (selectedItem != nullptr) {
		databaseHelper->deleteEntry(selectedItem->Id);
		refreshList();
	}
}


void ShipsDataBase::MainPage::AddMilitary_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Ship *ship = new MilitaryShip(L"Jauns", L"LV", 1,1,1, 1);
	databaseHelper->add(ship);
	delete ship;
	refreshList();
}


void ShipsDataBase::MainPage::addCivil_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Ship *ship = new CivilShip(L"Jauns", L"LV",1, L"", 1);
	databaseHelper->add(ship);
	delete ship;
	refreshList();
}





void ShipsDataBase::MainPage::Page_Loaded_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
databaseHelper->open();
	refreshList();
}
