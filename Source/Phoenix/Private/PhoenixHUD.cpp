#include "PhoenixHUD.h"

class UObject;
class UReticule;


void APhoenixHUD::StartSettingHUDVisible(bool bNewValue, EStandardManagedPriority Priority, const UObject* Provider, bool AllowAnimation) {
}

void APhoenixHUD::ShowHUDGroup(const FString& GroupName, UObject* Provider) {
}

void APhoenixHUD::SetDefaultHUDVisible(bool bDefaultValue, bool AllowSelectiveTicking) {
}

void APhoenixHUD::ReadActiveOwlMail() {
}

void APhoenixHUD::OnMailRecieved(FMailEntry Entry, int32 DisplayPriority) {
}

void APhoenixHUD::HideHUDGroup(const FString& GroupName, UObject* Provider) {
}

void APhoenixHUD::HandleHUDGroupUnregistration(const UObject* i_caller, const FName& HUDGroupName) {
}

void APhoenixHUD::HandleHUDGroupRegistration(const UObject* i_caller, const FName& HUDGroupName) {
}

UReticule* APhoenixHUD::GetReticuleWidget() {
    return NULL;
}

void APhoenixHUD::FinishSettingHUDVisible(EStandardManagedPriority Priority, const UObject* Provider, bool AllowAnimation) {
}

void APhoenixHUD::EnableAnimDebugInfo(bool bInFlag) {
}

APhoenixHUD::APhoenixHUD() {
    this->VerdanaFont = NULL;
    this->UE4Font = NULL;
    this->DefaultFontScale = 0.70f;
    this->GlobalHUDMult = 1.00f;
    this->CursorMain = NULL;
    this->CursorHoveringButton = NULL;
    this->ButtonBackground = NULL;
    this->MaterialBackground = NULL;
    this->m_subReticuleMoveToTargetTime = 1.00f;
    this->m_ReticuleWidgetClass = NULL;
    this->LoadingScreenWidgetClass = NULL;
    this->HUDWidgetRef = NULL;
    this->KnowledgeNotificationShown = false;
    this->bShowAnimDebugInfo = false;
    this->StickX = 0.00f;
    this->StickY = 0.00f;
    this->ModifiedStickX = 0.00f;
    this->ModifiedStickY = 0.00f;
    this->DeadZoneCurve = NULL;
    this->SpeedCurve = NULL;
}

