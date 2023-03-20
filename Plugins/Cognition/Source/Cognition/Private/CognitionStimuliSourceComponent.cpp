#include "CognitionStimuliSourceComponent.h"
#include "Templates/SubclassOf.h"

class AController;
class UAISense;
class UAISenseSpecificDetails;

void UCognitionStimuliSourceComponent::SetPriorityWeight(float weight) {
}

void UCognitionStimuliSourceComponent::SetIgnoreLineOfSight(bool bFlag) {
}

void UCognitionStimuliSourceComponent::SetFootprintRadius(float Radius) {
}

void UCognitionStimuliSourceComponent::SetAutoRegisterAsSource(bool bFlag) {
}

bool UCognitionStimuliSourceComponent::IsRegisteredForSense(TSubclassOf<UAISense> SenseToFind) {
    return false;
}

bool UCognitionStimuliSourceComponent::IsOwned() const {
    return false;
}

UAISenseSpecificDetails* UCognitionStimuliSourceComponent::GetSenseSpecificDetails(const TSubclassOf<UAISense> InSense) {
    return NULL;
}

float UCognitionStimuliSourceComponent::GetPriorityWeight() {
    return 0.0f;
}

bool UCognitionStimuliSourceComponent::GetIgnoreLineOfSight() {
    return false;
}

float UCognitionStimuliSourceComponent::GetFootprintRadius() {
    return 0.0f;
}

bool UCognitionStimuliSourceComponent::GetAutoRegisterAsSource() const {
    return false;
}

void UCognitionStimuliSourceComponent::ChangeInformation(const FCalloutInformation& NewInformation) {
}

float UCognitionStimuliSourceComponent::CalculateRadiusNeededToBePerceivedBy(float DistanceFromPerceiver, AController* PerceiverController, TSubclassOf<UAISense> SenseToUse, bool bIncludePerceiverRadius) {
    return 0.0f;
}

void UCognitionStimuliSourceComponent::AddRegisterAsSourceForSenses(const TSubclassOf<UAISense>& Sense) {
}

void UCognitionStimuliSourceComponent::OnRegister()
{
    Super::OnRegister();
}

UCognitionStimuliSourceComponent::UCognitionStimuliSourceComponent() : UAIPerceptionStimuliSourceComponent(FObjectInitializer::Get()) {
    this->FootprintRadius = 0.00f;
    this->TopOffset = 0.00f;
    this->BottomOffset = 0.00f;
    this->PriorityWeight = 1.00f;
    this->VsPlayerPriorityWeightBump = 0.00f;
    this->FarDistance_Override = -1.00f;
    this->FOV_Override = 0.00f;
    this->SocialORCombatMode = ESocialCombatMode::AllModes;
    this->bIgnoreLineOfSight = false;
    this->bIgnoreScreenSpace = false;
    this->bSpecialOnScreenTarget = false;
    this->bDisallowInteractInCombat = false;
    this->bDisallowAimTargeting = false;
    this->TargetPointClass = NULL;
    this->LookAtPointClass = NULL;
    this->bLockOnEnabled = true;
    this->MaxLockOnDistance = 3500.00f;
    this->bRecordInteractLocation = false;
    this->bAllowTargetWhileStandingOn = false;
    this->bOverrideMinAimDistance = false;
    this->MinAimDistance = 3000.00f;
    this->CalloutType = ECalloutType::Interact_Blip_Action;
    this->CalloutBlipType = ECalloutBlipType::Diamond;
    this->CalloutAction = ECalloutActions::NOT_SET;
    this->bGrayOutButton = false;
    this->bIsTargetTextTranslatable = true;
    this->ChargeTime = 0.00f;
    this->CalloutInteractDistance = 200.00f;
}

