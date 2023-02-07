#include "GameLogicGameSettings.h"

void UGameLogicGameSettings::SetElementSizeByPanelAndRealm(EGameLogicElementSize InSize, EGameLogicEditorPanel ElementType, FName RealmName) {
}

void UGameLogicGameSettings::RemoveElementByIndex(EGameLogicEditorPanel ElementType, int32 Index) {
}

void UGameLogicGameSettings::MoveElementByIndex(EGameLogicEditorPanel ElementType, int32 Index, int32 IndexDelta, bool bUseRealm, const FName RealmName) {
}

bool UGameLogicGameSettings::IsValidElementName(const FName& InName) {
    return false;
}

bool UGameLogicGameSettings::IsUniqueElementName(const FName& InName) {
    return false;
}

int32 UGameLogicGameSettings::GetIndexFromElement(EGameLogicEditorPanel ElementType, const FGlobal_GameLogicElement& InElement, bool bUseRealm, const FName RealmName) {
    return 0;
}

EGameLogicElementSize UGameLogicGameSettings::GetElementSizeByPanelAndRealm(EGameLogicEditorPanel ElementType, FName RealmName) {
    return EGameLogicElementSize::Smallest;
}

void UGameLogicGameSettings::GetElementNames(TArray<FName>& ElementNames) const {
}

int32 UGameLogicGameSettings::GetCountFromElement(EGameLogicEditorPanel ElementType, bool bUseRealm, const FName RealmName) {
    return 0;
}

bool UGameLogicGameSettings::ElementPanelHasReferences(EGameLogicEditorPanel ElementType, FName RealmName) {
    return false;
}

bool UGameLogicGameSettings::ElementHasReferences(FName ElementName) {
    return false;
}

void UGameLogicGameSettings::DestroyRealm(FName RealmName) {
}

bool UGameLogicGameSettings::DestroyElementsByRealm(EGameLogicEditorPanel ElementType, FName RealmName) {
    return false;
}

void UGameLogicGameSettings::CreateRealm(FName RealmName) {
}

FName UGameLogicGameSettings::ComputeUniqueElementName(const FName& BaseName) {
    return NAME_None;
}

FName UGameLogicGameSettings::AddElementToRealm(EGameLogicEditorPanel ElementType, FName RealmName, int32 Index, bool bCopyIndex, int32 IndexToCopy) {
    return NAME_None;
}

UGameLogicGameSettings::UGameLogicGameSettings() {
    this->Realms.AddDefaulted(9);
    this->BoolVars.AddDefaulted(331);
    this->Int32Vars.AddDefaulted(58);
    this->FloatVars.AddDefaulted(14);
    this->TimerVars.AddDefaulted(163);
    this->EnumVars.AddDefaulted(53);
    this->BitfieldVars.AddDefaulted(1);
    this->StringVars.AddDefaulted(50);
    this->PropInt32s.AddDefaulted(75);
    this->PropFloats.AddDefaulted(5);
    this->PropEnums.AddDefaulted(62);
    this->PropBitfields.AddDefaulted(13);
    this->PropStrings.AddDefaulted(187);
    this->Expressions.AddDefaulted(390);
}

