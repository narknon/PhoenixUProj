#include "PhoenixHUDWidget.h"

class UObject;

bool UPhoenixHUDWidget::WorldToViewport(FVector WorldPos, FVector2D& o_Point, bool LockToViewableSpace) {
    return false;
}





void UPhoenixHUDWidget::ShowZoneNotification(FName Header_Name, FName Label_Name, FName Image_Left, FName Image_Right, float duration_seconds, bool PlaySound) {
}

void UPhoenixHUDWidget::ShowTransformationUI_Implementation(bool Show, const int32 IntroType) {
}

void UPhoenixHUDWidget::ShowSpellBar(bool Show) {
}





void UPhoenixHUDWidget::ShowCreatureNurturingHUD_Implementation(bool Show) {
}


void UPhoenixHUDWidget::ShowConjurationUI_Implementation(bool Show, const int32 IntroType) {
}









void UPhoenixHUDWidget::OverrideSpellBar() {
}

















void UPhoenixHUDWidget::HideZoneNotification() {
}










void UPhoenixHUDWidget::ClearSpellBarOverride() {
}



void UPhoenixHUDWidget::AddSpecialItemNotification(const FString& Name, const FString& IconName, int32 Count, const FString& UnlockMessage) {
}

void UPhoenixHUDWidget::AddFastTravelUnlockedNotification(const FString& Site, const FString& IconName) {
}

void UPhoenixHUDWidget::AddCompanionLevelUpNotification(const UObject* i_caller, const FString& CompanionName, int32 Level) {
}

void UPhoenixHUDWidget::AddCollectionNotification(const FString& Name, const FString& IconName, int32 Count, bool bSpecial, FName Variation) {
}


UPhoenixHUDWidget::UPhoenixHUDWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->LockOnReticlePanel = NULL;
    this->CapturingWidgetPanel = NULL;
    this->HUD_ZoneNotification = NULL;
    this->ComboHelperHud = NULL;
    this->Reticule = NULL;
    this->ConjurationIntroType = 0;
    this->TransfigurationIntroType = 0;
    this->BeaconMinVertElevationDistMeters = 2.00f;
    this->BeaconMaxHorizElevationDistMeters = 50.00f;
    this->BeaconElevationBufferMeters = 0.50f;
    this->MinVisibleBeaconTextDistMeters = 10.00f;
}

