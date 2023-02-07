#include "SelectionRingItemBase.h"

class UObject;
class UTexture2D;

void USelectionRingItemBase::ShowUpdateVFX() {
}

void USelectionRingItemBase::SetItemData(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex, bool ShowNone) {
}




void USelectionRingItemBase::LoadIconCallback(UTexture2D* Texture, UObject* Param) {
}

void USelectionRingItemBase::LoadBackgroundCallback(UTexture2D* Texture, UObject* Param) {
}

ESpellCategory USelectionRingItemBase::GetSpellCategory() {
    return ESpellCategory::None;
}

USelectionRingItemBase::USelectionRingItemBase() {
}

