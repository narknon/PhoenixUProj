#include "CurtainSubsystem.h"

class UObject;

void UCurtainSubsystem::LowerCurtain(const UObject* WhosAsking, FName WhatsYourName) {
}

bool UCurtainSubsystem::IsCurtainDown(const UObject* WhosAsking) {
    return false;
}

FString UCurtainSubsystem::GetLienholderNames() const {
    return TEXT("");
}

UCurtainSubsystem::UCurtainSubsystem() {
    this->CurtainWidgetClass = NULL;
    this->CurtainWidget = NULL;
}

