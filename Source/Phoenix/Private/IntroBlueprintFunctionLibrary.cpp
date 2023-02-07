#include "IntroBlueprintFunctionLibrary.h"

class UObject;

void UIntroBlueprintFunctionLibrary::SetLoadingRootLevel(bool bLoadingRootLevel) {
}

void UIntroBlueprintFunctionLibrary::SetCheating(bool bCheating) {
}

bool UIntroBlueprintFunctionLibrary::IsLoadingRootLevel(bool bReset) {
    return false;
}

bool UIntroBlueprintFunctionLibrary::IsCheating() {
    return false;
}

void UIntroBlueprintFunctionLibrary::IntroStart(UObject* WorldContextObject) {
}

void UIntroBlueprintFunctionLibrary::IntroSave(UObject* WorldContextObject, EIntroCheckpoint Checkpoint, FVector PlayerSpawnLocation) {
}

void UIntroBlueprintFunctionLibrary::IntroEnd(UObject* WorldContextObject) {
}

EIntroCheckpoint UIntroBlueprintFunctionLibrary::GetIntroCheckpoint() {
    return EIntroCheckpoint::CP0;
}

UIntroBlueprintFunctionLibrary::UIntroBlueprintFunctionLibrary() {
}

