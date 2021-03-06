﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "App.xaml.h"
#include "MainPage.xaml.h"
#include "XamlBindingInfo.g.hpp"
#include "App.g.hpp"
#include "MainPage.g.hpp"

template<typename T>
::Platform::Object^ ActivateType()
{
    return ref new T;
}

template<typename TInstance, typename TItem>
void CollectionAdd(::Platform::Object^ instance, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Append((TItem)item);
}

template<typename TInstance, typename TKey, typename TItem>
void DictionaryAdd(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Insert((TKey)key, (TItem)item);
}

template<typename T>
::Platform::Object^ FromStringConverter(::XamlTypeInfo::InfoProvider::XamlUserType^ userType, ::Platform::String^ input)
{
    return ref new ::Platform::Box<T>((T)userType->CreateEnumUIntFromString(input));
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_Missiles(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->Missiles);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_Lielgabali(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->Lielgabali);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_Id(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->Id);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_Tonnage(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->Tonnage);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_SType(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->SType);
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_ViewModel(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->ViewModel;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_OneLineSummary(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->OneLineSummary;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_CompanyName(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->CompanyName;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_Valsts(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->Valsts;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_Nosaukums(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->Nosaukums;
}

struct TypeInfo
{
    PCWSTR  typeName;
    PCWSTR contentPropertyName;
    ::Platform::Object^ (*activator)();
    void (*collectionAdd)(::Platform::Object^, ::Platform::Object^);
    void (*dictionaryAdd)(::Platform::Object^, ::Platform::Object^, ::Platform::Object^);
    ::Platform::Object^ (*fromStringConverter)(::XamlTypeInfo::InfoProvider::XamlUserType^, ::Platform::String^);
    int     baseTypeIndex;
    int     firstMemberIndex;
    int     firstEnumValueIndex;
    ::Windows::UI::Xaml::Interop::TypeKind kindofType;
    bool    isLocalType;
    bool    isSystemType;
    bool    isReturnTypeStub;
    bool    isBindable;
};

const TypeInfo TypeInfos[] = 
{
    //   0
    L"Int32", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, true,  false, false,
    //   1
    L"Object", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, true,  false, false,
    //   2
    L"String", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, true,  false, false,
    //   3
    L"System.Enum", L"",
    nullptr, nullptr, nullptr, nullptr,
    4, // System.ValueType
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, false, false, false,
    //   4
    L"System.ValueType", L"",
    nullptr, nullptr, nullptr, nullptr,
    1, // Object
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, false, false, false,
    //   5
    L"ShipsDataBase.CXclass", L"",
    nullptr, nullptr, nullptr, nullptr,
    1, // Object
    0, 0, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    true,  false, false, true, 
    //   6
    L"ShipsDataBase.MainPage", L"",
    &ActivateType<::ShipsDataBase::MainPage>, nullptr, nullptr, nullptr,
    9, // Windows.UI.Xaml.Controls.Page
    9, 0, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    true,  false, false, false,
    //   7
    L"ShipsDataBase.ShipType", L"",
    nullptr, nullptr, nullptr, &FromStringConverter<::ShipsDataBase::ShipType>,
    3, // System.Enum
    10, 0, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    true,  false, false, false,
    //   8
    L"ShipsDataBase.ShipViewModel", L"",
    nullptr, nullptr, nullptr, nullptr,
    1, // Object
    10, 2, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    true,  false, true,  false,
    //   9
    L"Windows.UI.Xaml.Controls.Page", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    10, 2, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, true,  false, false,
    //  10
    L"Windows.UI.Xaml.Controls.UserControl", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    10, 2, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    false, true,  false, false,
    //  Last type here is for padding
    L"", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1, 
    10, 2,::Windows::UI::Xaml::Interop::TypeKind::Custom,
    false, false, false, false,
};

const UINT TypeInfoLookup[] = { 
      0,   //   0
      0,   //   1
      0,   //   2
      0,   //   3
      0,   //   4
      0,   //   5
      1,   //   6
      3,   //   7
      3,   //   8
      3,   //   9
      3,   //  10
      3,   //  11
      4,   //  12
      4,   //  13
      4,   //  14
      4,   //  15
      4,   //  16
      5,   //  17
      5,   //  18
      5,   //  19
      5,   //  20
      5,   //  21
      6,   //  22
      8,   //  23
      8,   //  24
      8,   //  25
      8,   //  26
      8,   //  27
      9,   //  28
      9,   //  29
     10,   //  30
     10,   //  31
     10,   //  32
     10,   //  33
     10,   //  34
     10,   //  35
     10,   //  36
     11,   //  37
};

struct EnumValueInfo
{
    PCWSTR name;
    int eValue;
};

const EnumValueInfo EnumValues[] =
{ 
    L"MIL", (int) ::ShipsDataBase::ShipType::MIL,
    L"CIV", (int) ::ShipsDataBase::ShipType::CIV,
};

struct MemberInfo 
{
    PCWSTR shortName;
    ::Platform::Object^ (*getter)(::Platform::Object^);
    void (*setter)(::Platform::Object^, ::Platform::Object^);
    int typeIndex;
    int targetTypeIndex;
    bool isReadOnly;
    bool isDependencyProperty;
    bool isAttachable;
};

const MemberInfo MemberInfos[] = 
{
    //   0 - ShipsDataBase.CXclass.OneLineSummary
    L"OneLineSummary",
    &GetReferenceTypeMember_OneLineSummary<::ShipsDataBase::CXclass>,
    nullptr,
    2, // String
    -1,
    true,  false, false,
    //   1 - ShipsDataBase.CXclass.CompanyName
    L"CompanyName",
    &GetReferenceTypeMember_CompanyName<::ShipsDataBase::CXclass>,
    nullptr,
    2, // String
    -1,
    true,  false, false,
    //   2 - ShipsDataBase.CXclass.Missiles
    L"Missiles",
    &GetValueTypeMember_Missiles<::ShipsDataBase::CXclass, ::default::int32>,
    nullptr,
    0, // Int32
    -1,
    true,  false, false,
    //   3 - ShipsDataBase.CXclass.Lielgabali
    L"Lielgabali",
    &GetValueTypeMember_Lielgabali<::ShipsDataBase::CXclass, ::default::int32>,
    nullptr,
    0, // Int32
    -1,
    true,  false, false,
    //   4 - ShipsDataBase.CXclass.Id
    L"Id",
    &GetValueTypeMember_Id<::ShipsDataBase::CXclass, ::default::int32>,
    nullptr,
    0, // Int32
    -1,
    true,  false, false,
    //   5 - ShipsDataBase.CXclass.Tonnage
    L"Tonnage",
    &GetValueTypeMember_Tonnage<::ShipsDataBase::CXclass, ::default::int32>,
    nullptr,
    0, // Int32
    -1,
    true,  false, false,
    //   6 - ShipsDataBase.CXclass.Valsts
    L"Valsts",
    &GetReferenceTypeMember_Valsts<::ShipsDataBase::CXclass>,
    nullptr,
    2, // String
    -1,
    true,  false, false,
    //   7 - ShipsDataBase.CXclass.Nosaukums
    L"Nosaukums",
    &GetReferenceTypeMember_Nosaukums<::ShipsDataBase::CXclass>,
    nullptr,
    2, // String
    -1,
    true,  false, false,
    //   8 - ShipsDataBase.CXclass.SType
    L"SType",
    &GetValueTypeMember_SType<::ShipsDataBase::CXclass, ::ShipsDataBase::ShipType>,
    nullptr,
    7, // ShipsDataBase.ShipType
    -1,
    true,  false, false,
    //   9 - ShipsDataBase.MainPage.ViewModel
    L"ViewModel",
    &GetReferenceTypeMember_ViewModel<::ShipsDataBase::MainPage>,
    nullptr,
    8, // ShipsDataBase.ShipViewModel
    -1,
    true,  false, false,
};

PCWSTR GetShortName(PCWSTR longName)
{
    PCWSTR separator = wcsrchr(longName, '.');
    return separator != nullptr ? separator + 1: longName;
}

const TypeInfo* GetTypeInfo(::Platform::String^ typeName)
{
    int typeNameLength = typeName->Length();
    if (typeNameLength < _countof(TypeInfoLookup) - 1)
    {
        for (UINT i = TypeInfoLookup[typeNameLength]; i < TypeInfoLookup[typeNameLength+1]; i++)
        {
            if (typeName == ::Platform::StringReference(TypeInfos[i].typeName))
            {
                return &TypeInfos[i];
            }
        }
    }
    return nullptr;
}

const MemberInfo* GetMemberInfo(::Platform::String^ longMemberName)
{
    for (int lastDotIndex = longMemberName->Length(); lastDotIndex >= 0; lastDotIndex--)
    {
        if (longMemberName->Data()[lastDotIndex] == '.')
        {
            const TypeInfo* pTypeInfo = GetTypeInfo(ref new ::Platform::String(longMemberName->Data(), lastDotIndex));
            const TypeInfo* pNextTypeInfo = pTypeInfo + 1;
            if (pTypeInfo)
            {
                PCWSTR shortMemberName = GetShortName(longMemberName->Data());
                for (int i = pTypeInfo->firstMemberIndex; i < pNextTypeInfo->firstMemberIndex; i++)
                {
                    if (wcscmp(shortMemberName, MemberInfos[i].shortName) == 0)
                    {
                        return &MemberInfos[i];
                    }
                }
            }
            break;
        }
    }
    return nullptr;
}

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        auto otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
        _otherProviders = otherProviders;
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    const TypeInfo* pTypeInfo = GetTypeInfo(typeName);
    const TypeInfo* pNextTypeInfo = pTypeInfo + 1;
    if (pTypeInfo == nullptr || pNextTypeInfo == nullptr)
    {
        return nullptr;
    }
    else if (pTypeInfo->isSystemType)
    {
        return ref new ::XamlTypeInfo::InfoProvider::XamlSystemBaseType(typeName);
    }
    else
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(
            this, 
            ::Platform::StringReference(pTypeInfo->typeName), 
            this->GetXamlTypeByName(::Platform::StringReference(pTypeInfo->baseTypeIndex >= 0 ? TypeInfos[pTypeInfo->baseTypeIndex].typeName : L"")));
        userType->KindOfType = pTypeInfo->kindofType;
        userType->Activator = pTypeInfo->activator;
        userType->CollectionAdd = pTypeInfo->collectionAdd;
        userType->DictionaryAdd = pTypeInfo->dictionaryAdd;
        userType->FromStringConverter = pTypeInfo->fromStringConverter;
        userType->ContentPropertyName = ::Platform::StringReference(pTypeInfo->contentPropertyName);
        userType->IsLocalType = pTypeInfo->isLocalType;
        userType->IsReturnTypeStub = pTypeInfo->isReturnTypeStub;
        userType->IsBindable = pTypeInfo->isBindable;
        int nextMemberIndex = pTypeInfo->firstMemberIndex;
        for (int i=pTypeInfo->firstMemberIndex; i < pNextTypeInfo->firstMemberIndex; i++)
        {
            userType->AddMemberName(::Platform::StringReference(MemberInfos[i].shortName));
            nextMemberIndex++;
        }
        for (int i = pTypeInfo->firstEnumValueIndex; i < pNextTypeInfo->firstEnumValueIndex; i++)
        {
            userType->AddEnumValue(
                ::Platform::StringReference(EnumValues[i].name),
                ::Windows::Foundation::PropertyValue::CreateInt32(EnumValues[i].eValue));
        }
        return userType;
    }
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = nullptr;
    const MemberInfo* pMemberInfo = GetMemberInfo(longMemberName);
    if (pMemberInfo != nullptr)
    {
        xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(
            this,
            ::Platform::StringReference(pMemberInfo->shortName),
            ::Platform::StringReference(TypeInfos[pMemberInfo->typeIndex].typeName));
        xamlMember->Getter = pMemberInfo->getter;
        xamlMember->Setter = pMemberInfo->setter;
        xamlMember->TargetTypeName = pMemberInfo->targetTypeIndex >= 0 ? ::Platform::StringReference(TypeInfos[pMemberInfo->targetTypeIndex].typeName) : L"";
        xamlMember->IsReadOnly = pMemberInfo->isReadOnly;
        xamlMember->IsDependencyProperty = pMemberInfo->isDependencyProperty;
        xamlMember->IsAttachable = pMemberInfo->isAttachable;
    }
    return xamlMember;
}

