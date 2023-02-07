#include "BTCustomGameSettings.h"

class UBTCustomGameSettings;

UBTCustomGameSettings* UBTCustomGameSettings::GetInputSettings() {
    return NULL;
}

void UBTCustomGameSettings::GetActionNames(TArray<FName>& ActionNames) const {
}

UBTCustomGameSettings::UBTCustomGameSettings() {
    this->Actions.AddDefaulted(173);
}

