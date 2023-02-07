#include "CreatureState.h"

class UCreatureDefinition;
class UCreatureState;

void UCreatureState::SetIsUncapturable(bool bInIsUncapturable) {
}

void UCreatureState::SetCanReturnToWild(bool bInCanReturnToWild) {
}

void UCreatureState::OnHarvestByproduct(FName CollectorID) {
}

bool UCreatureState::IsUnbornCreature() const {
    return false;
}

bool UCreatureState::IsPregnant() const {
    return false;
}

bool UCreatureState::IsNeedMet(const ECreatureNeed CreatureNeed) const {
    return false;
}

bool UCreatureState::IsInSanctuary() const {
    return false;
}

bool UCreatureState::IsIncubating() const {
    return false;
}

bool UCreatureState::IsInConflict() const {
    return false;
}

bool UCreatureState::IsHappyEnoughToPlayWithToy() const {
    return false;
}

bool UCreatureState::IsEgg() const {
    return false;
}

bool UCreatureState::IsCreatureCaptured() const {
    return false;
}

bool UCreatureState::IsByproductOnCooldown() const {
    return false;
}

bool UCreatureState::IsAlbino() const {
    return false;
}

UCreatureState* UCreatureState::GetUnbornChildState() const {
    return NULL;
}

FName UCreatureState::GetTypeID() const {
    return NAME_None;
}

FText UCreatureState::GetTranslatedCreatureDisplayName() const {
    return FText::GetEmpty();
}

FTimespan UCreatureState::GetTimeLeftToGrowUp() const {
    return FTimespan{};
}

float UCreatureState::GetScaleVariation() const {
    return 0.0f;
}

ECreaturePregnancyState UCreatureState::GetPregnancyState() const {
    return ECreaturePregnancyState::NotPregnant;
}

FDateTime UCreatureState::GetPregnancyStartDateTime() const {
    return FDateTime{};
}

int32 UCreatureState::GetPenUID() const {
    return 0;
}

FName UCreatureState::GetNurturingSpaceID() const {
    return NAME_None;
}

int32 UCreatureState::GetMotherUID() const {
    return 0;
}

bool UCreatureState::GetIsUncapturable() const {
    return false;
}

bool UCreatureState::GetIsMount() const {
    return false;
}

bool UCreatureState::GetIsMale() const {
    return false;
}

bool UCreatureState::GetIsByproductReady() const {
    return false;
}

bool UCreatureState::GetIsByproductHarvestableByPlayer(FString& OutErrorKey) const {
    return false;
}

FDateTime UCreatureState::GetIncubationStartDateTime() const {
    return FDateTime{};
}

FString UCreatureState::GetIconString() const {
    return TEXT("");
}

FTimespan UCreatureState::GetHatchingTimeRemaining() const {
    return FTimespan{};
}

float UCreatureState::GetHappinessCap() const {
    return 0.0f;
}

float UCreatureState::GetHappiness() const {
    return 0.0f;
}

FTimespan UCreatureState::GetGestationTimeRemaining() const {
    return FTimespan{};
}

int32 UCreatureState::GetFatherUID() const {
    return 0;
}

UCreatureDefinition* UCreatureState::GetDefinition() const {
    return NULL;
}

int32 UCreatureState::GetCreatureUID() const {
    return 0;
}

FString UCreatureState::GetCreatureName() const {
    return TEXT("");
}

void UCreatureState::GetCreatureDisplayName(FString& OutName, bool& OutIsLocalizationKey) const {
}

FName UCreatureState::GetColorVariation() const {
    return NAME_None;
}

bool UCreatureState::GetCanReturnToWild() const {
    return false;
}

bool UCreatureState::GetCanRename() const {
    return false;
}

FTimespan UCreatureState::GetByproductCooldownTimeLeft() const {
    return FTimespan{};
}

float UCreatureState::GetByproductCooldownProgress() const {
    return 0.0f;
}

int32 UCreatureState::GetBreedingGeneration() const {
    return 0;
}

FDateTime UCreatureState::GetBirthDateTime() {
    return FDateTime{};
}

FString UCreatureState::GetAdultIconString() const {
    return TEXT("");
}

TArray<FCreatureActivityThreshold> UCreatureState::GetActivityThresholds() const {
    return TArray<FCreatureActivityThreshold>();
}

bool UCreatureState::CanStartActivity() const {
    return false;
}

bool UCreatureState::CanCreatureBreed(FString& ErrorMessage) {
    return false;
}

bool UCreatureState::AreAllNeedsMet() const {
    return false;
}

UCreatureState::UCreatureState() {
}

