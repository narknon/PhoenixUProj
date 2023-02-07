#include "ActionRingItem.h"

class UObject;
class UTexture2D;



void UActionRingItem::SetSpellTool() {
}

void UActionRingItem::SetItemInventoryData() {
}

void UActionRingItem::SetItemData(UIActionModes ActionMode, int32 iGroupIndex, int32 iMacroIndex, int32 iItemIndex, bool ShowNone) {
}



void UActionRingItem::OnSpellWhitelistDeactivated(const UObject* InCaller) {
}

void UActionRingItem::OnSpellWhitelistActivated(const UObject* InCaller) {
}

void UActionRingItem::OnSpellCooldownChanged(FName SpellName, float CooldownPct) {
}

void UActionRingItem::OnSpellCleared(const UObject* InCaller, const FName& SpellName) {
}


void UActionRingItem::OnSpellBlacklisted(const UObject* InCaller, const FName& SpellName) {
}







void UActionRingItem::OnCreateBipedPlayer(const UObject* InCaller) {
}


void UActionRingItem::LoadOverlayCallback(UTexture2D* Texture, UObject* Param) {
}

void UActionRingItem::LoadItemIconCallback(UTexture2D* Texture, UObject* Param) {
}

void UActionRingItem::LoadIconGlowCallback(UTexture2D* Texture, UObject* Param) {
}

void UActionRingItem::LoadIconCallback(UTexture2D* Texture, UObject* Param) {
}

void UActionRingItem::HandleSpellCastFailed(const UObject* InCaller, const FString& SpellStr) {
}

ESpellCategory UActionRingItem::GetSpellCategory() {
    return ESpellCategory::None;
}


UActionRingItem::UActionRingItem() : UUserWidget(FObjectInitializer::Get()) {
}

