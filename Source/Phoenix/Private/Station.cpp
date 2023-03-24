#include "Station.h"
#include "StationComponent.h"

class AActor;
class AStation;
class UAnimSequence;
class UBTService_AvaAITree;
class USceneComponent;
class USkeletalMeshComponent;

void AStation::TriggerSoloActionOnParticipants(AStation* InTargetStation, TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor) {
}

void AStation::Interact_Implementation(UBTService_AvaAITree* AvaService) {
}

UStationComponent* AStation::GetStationComponent() const {
    return NULL;
}

USkeletalMeshComponent* AStation::CreateAndAttachSkeletalMeshComponent(UAnimSequence* AnimPose, USceneComponent* ParentProp, const FName SocketName) {
    return NULL;
}

AStation::AStation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StationComponent = CreateDefaultSubobject<UStationComponent>(TEXT("StationData"));
    this->MissionUID = 0;
}

