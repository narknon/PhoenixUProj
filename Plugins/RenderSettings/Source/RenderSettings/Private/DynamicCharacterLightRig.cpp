#include "DynamicCharacterLightRig.h"
#include "Templates/SubclassOf.h"

class AActor;
class ADynamicCharacterLightRig;
class UObject;

void ADynamicCharacterLightRig::LightRigEnabled(bool& Enabled) {
}

void ADynamicCharacterLightRig::GetDynamicLightRig(AActor* ToActor, ADynamicCharacterLightRig*& DynamicLightRig) {
}

void ADynamicCharacterLightRig::Get(AActor* Actor, ADynamicCharacterLightRig*& DynamicLightRig) {
}

void ADynamicCharacterLightRig::EnableLightRig(bool Enable) {
}

void ADynamicCharacterLightRig::DynamicLightRigCinematicEnable(UObject* WorldContextObject) {
}

void ADynamicCharacterLightRig::DynamicLightRigCinematicDisable(UObject* WorldContextObject, bool bDisable) {
}

void ADynamicCharacterLightRig::DynamicLightRigCinematicDiabled(UObject* WorldContextObject, bool& bDisabled) {
}

void ADynamicCharacterLightRig::DisableLightRig() {
}

void ADynamicCharacterLightRig::AttachDynamicLightRig(AActor* ToActor, TSubclassOf<ADynamicCharacterLightRig> DynamicLightRigClass, ADynamicCharacterLightRig*& DynamicLightRig, FName AttachSocket) {
}

ADynamicCharacterLightRig::ADynamicCharacterLightRig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DayTemperature = 5000.00f;
    this->NightTemperature = 6500.00f;
    this->LightingChannel = EDynamicCharacterLightRigChannel::ChannelAuto;
    this->bEnabled = true;
    this->bUseAdaptationSettings = false;
    this->bInitializedOwnerChannels = false;
}

