#include "QuickHealthActions.h"

class AActor;
class UObject;
class UTexture2D;


void UQuickHealthActions::SetMaxHealth(int32 NewMaxHealth) {
}



void UQuickHealthActions::OnHealthChanged(AActor* Actor, float Delta, bool IndicateHUD) {
}

void UQuickHealthActions::LoadIconCallback(UTexture2D* Texture, UObject* Param) {
}


UQuickHealthActions::UQuickHealthActions() {
    this->CurrentHealthItem = TEXT("WoundCleaning");
}

