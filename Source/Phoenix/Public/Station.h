#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "BeaconableObject.h"
#include "Biped_Interact_Interface.h"
#include "SocialActionTypes.h"
#include "SocialSemanticIDs.h"
#include "SpellInterface.h"
#include "WorldObject.h"
#include "Station.generated.h"

class AActor;
class AStation;
class UAnimSequence;
class UBTService_AvaAITree;
class USceneComponent;
class USkeletalMeshComponent;
class UStationComponent;

UCLASS(Blueprintable)
class AStation : public AWorldObject, public IBiped_Interact_Interface, public ISpellInterface, public IBeaconableObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStationComponent* StationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MissionUID;
    
    AStation(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void TriggerSoloActionOnParticipants(AStation* InTargetStation, TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStationComponent* GetStationComponent() const;
    
    UFUNCTION(BlueprintCallable)
    USkeletalMeshComponent* CreateAndAttachSkeletalMeshComponent(UAnimSequence* AnimPose, USceneComponent* ParentProp, const FName SocketName);
    
    
    // Fix for true pure virtual functions not being implemented
};

