﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------

#include "XamlBindingInfo.g.h"

namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class AppBarButton;
                ref class MenuFlyoutItem;
                ref class TextBlock;
                ref class Grid;
                ref class TextBox;
                ref class ListView;
            }
        }
    }
}

namespace ShipsDataBase
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
        class MainPage_obj19_Bindings;
        class MainPage_obj1_Bindings;
    
        ::XamlBindingInfo::XamlBindings^ Bindings;
        private: ::Windows::UI::Xaml::Controls::AppBarButton^ appBarButton;
        private: ::Windows::UI::Xaml::Controls::AppBarButton^ appBarButton1;
        private: ::Windows::UI::Xaml::Controls::AppBarButton^ appBarButtonSave;
        private: ::Windows::UI::Xaml::Controls::AppBarButton^ appBarButtonDelete;
        private: ::Windows::UI::Xaml::Controls::AppBarButton^ appBarButtonSort;
        private: ::Windows::UI::Xaml::Controls::MenuFlyoutItem^ addMilitary;
        private: ::Windows::UI::Xaml::Controls::MenuFlyoutItem^ addCivil;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ textBlock;
        private: ::Windows::UI::Xaml::Controls::Grid^ editGrid;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ idText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ nosaukumsText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ valstsText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tonnageText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ companyNameText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ lielgabaliText;
        private: ::Windows::UI::Xaml::Controls::TextBox^ missilesText;
        private: ::Windows::UI::Xaml::Controls::ListView^ listView;
    };
}

