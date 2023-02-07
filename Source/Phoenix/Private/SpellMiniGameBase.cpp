#include "SpellMiniGameBase.h"

class UObject;
class USpellMiniGameSpark;
class UTexture2D;


void USpellMiniGameBase::StartMiniGameReset(const UObject* sender, const int32 RemoveWaitRequest) {
}



void USpellMiniGameBase::ResetSparks() {
}

void USpellMiniGameBase::ResetMiniGame() {
}


void USpellMiniGameBase::PauseMiniGame() {
}

void USpellMiniGameBase::PathTextureCallback(UTexture2D* MI) {
}

void USpellMiniGameBase::PathMaskCallback(UTexture2D* T2D) {
}






















void USpellMiniGameBase::LogSpellMinigameData(const FString& LogData) {
}

FVector2D USpellMiniGameBase::GetProgressOnMask(const USpellMiniGameSpark* Spark) {
    return FVector2D{};
}

FName USpellMiniGameBase::GetMiniGameName() const {
    return NAME_None;
}

bool USpellMiniGameBase::GetIsWaitingForStart() const {
    return false;
}

bool USpellMiniGameBase::GetIsMiniGameActive() const {
    return false;
}

bool USpellMiniGameBase::GetIsInInputWindow() const {
    return false;
}

TArray<FInputCheckpoint> USpellMiniGameBase::GetInputCheckpoints() const {
    return TArray<FInputCheckpoint>();
}

FInputCheckpoint USpellMiniGameBase::GetCurrentCheckpointData() const {
    return FInputCheckpoint{};
}

void USpellMiniGameBase::AddResetWaitRequest(const UObject* sender) {
}


USpellMiniGameBase::USpellMiniGameBase() {
    this->PreDrawTime = 2.50f;
    this->PlayerSpark = NULL;
    this->BadSpark = NULL;
    this->PlayerProxy = NULL;
    this->ThreatChaserDelay = 0.00f;
    this->PreDrawProgress = 0.00f;
    this->SpellPathMask = NULL;
}

