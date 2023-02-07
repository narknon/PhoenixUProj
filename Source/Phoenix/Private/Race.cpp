#include "Race.h"
#include "Components/SplineComponent.h"

class AFlyingBroom;
class UInventoryItemToolRecord;
class UObject;
class UPopupScreen;

void ARace::RaceHudDismissed() {
}

void ARace::OnStoryModeSkipScreenDismissed(UPopupScreen* Popup, int32 ConfirmationResult) {
}




void ARace::OnEndOfRaceFTComplete() {
}

void ARace::OnCollectTurboBubble(const UObject* i_caller) {
}

void ARace::ItemToolLoadedCallback(UInventoryItemToolRecord* ToolRecord) {
}

bool ARace::IsRaceMissionActive() const {
    return false;
}

bool ARace::IsNewBestTime() {
    return false;
}

float ARace::GetTotalRaceTime(const TArray<float>& Times) {
    return 0.0f;
}

float ARace::GetTotalPenaltyTime() const {
    return 0.0f;
}

float ARace::GetTimeElapsed() const {
    return 0.0f;
}

bool ARace::GetRacerBestTime(const FName InRacerName, const bool bMissionRelevant, float& OutBestTime) {
    return false;
}

FString ARace::GetRaceID() {
    return TEXT("");
}

AFlyingBroom* ARace::GetPlayerBroom() {
    return NULL;
}

int32 ARace::GetNumberOfGates() const {
    return 0;
}

float ARace::GetGatePrevBestTime(const int32 GateNumber) {
    return 0.0f;
}

FName ARace::GetBestRacer_Blueprint(const bool bMissionRelevant, float& OutBestTime) {
    return NAME_None;
}

TArray<FRacerTime> ARace::GetAllRacerTimes(bool bMissionRelevant) {
    return TArray<FRacerTime>();
}

ARace::ARace() {
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("TrackSpline"));
    this->TrackGatesParent = NULL;
    this->EndGateParent = NULL;
    this->CountdownTime = 3;
    this->TimePenaltySeconds = 5;
    this->bKeepPlayerCloseToSpline = true;
    this->MaxDistanceFromSpline = 100;
    this->MaxDistancePastRing = 100;
    this->StoryModeRaceAttempts = 2;
    this->RaceType = ERaceType::TimeTrial;
    this->GateSuccessDialoguePercentageChance = 0.50f;
    this->GateSuccessDialogueCooldown = 10.00f;
    this->GateMissDialoguePercentageChance = 0.50f;
    this->GateMissDialogueCooldown = 10.00f;
    this->TurboBubbleDialoguePercentageChance = 0.50f;
    this->TurboBubbleDialogueCooldown = 10.00f;
}

