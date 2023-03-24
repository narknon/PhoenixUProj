#pragma once
#include "CoreMinimal.h"
#include "EHoboType.h"
#include "UObject/NoExportTypes.h"
#include "EGenderEnum.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "SignificanceInterface.h"
#include "HouseIds.h"
#include "LootSlot.h"
#include "WorldEventActor.generated.h"

class ABase_Character;
class ANPC_Character;
class AWorldEventLocationActor;
class UAnimationArchitectAsset;
class UAnimationArchitectComponent;
class UChildActorComponent;
class UPrimitiveComponent;
class UScheduledEntity;
class UWorldEventCondition;
class UWorldEventSocketComponent;

UCLASS(Blueprintable)
class PHOENIX_API AWorldEventActor : public AActor, public ISignificanceInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UScheduledEntity*> Participants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationArchitectComponent* AnimationArcitectComponent;
    
public:
    AWorldEventActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    bool SetTemporaryAnimationOnCharacter(ANPC_Character* Character, int32 AnimationIndex);
    
    UFUNCTION(BlueprintCallable)
    bool SetSpecificAnimationOnCharacter(ANPC_Character* Character, UAnimationArchitectAsset* AnimationArchitectAsset);
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* RequestHobo(const FVector& InLocation, const EHoboType HoboType, const TEnumAsByte<HouseIds> InHouse, const EGenderEnum InGender, const TArray<FString>& ValidVoiceIDs);
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* RequestCustomHobo(const FString& HoboName, const FVector& InLocation, const bool InIsMale);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveDynamicActivityFromSE(UScheduledEntity* ScheduledEntity, const FString& ActivityID);
    
    UFUNCTION(BlueprintCallable)
    bool ReleaseTemporaryAnimationFromCharacter(ANPC_Character* Character);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseHobo(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseAllHobos(bool InDestroyImmediate);
    
    UFUNCTION(BlueprintCallable)
    void PlayGhostStory(UScheduledEntity* InScheduledEntity, const FName Story, const FName Emotion);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartTriggerOverlapped(UWorldEventSocketComponent* Socket);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNoStartTriggerFound();
    
    UFUNCTION(BlueprintCallable)
    void MarkStageAsIncomplete(int32 Stage);
    
    UFUNCTION(BlueprintCallable)
    void MarkStageAsCompleted(int32 Stage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStageCompleted(int32 Stage);
    
    UFUNCTION(BlueprintCallable)
    bool InsertDynamicActivityOnSE(UScheduledEntity* ScheduledEntity, const FString& ActivityID, const FString& LocationID);
    
private:
    UFUNCTION(BlueprintCallable)
    void HitResult(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AWorldEventLocationActor* GetWorldEventLocatorActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FLootSlot> GetRandomLoot(const FString& Category);
    
    UFUNCTION(BlueprintCallable)
    int32 GetNumOfWorldEventHobos();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNextUncompleteStage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<HouseIds> GetLocationBasedStudentHouse();
    
    UFUNCTION(BlueprintCallable)
    bool FindStudentOnFreeTime(const FVector& InLocation, const float InRadius, const bool InAllowFindHobos, ABase_Character*& OutActor, UScheduledEntity*& OutScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    void EnableConversationSense(UScheduledEntity* SE, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void EnableChildActorComponent(UChildActorComponent* ChildActorComponent);
    
    UFUNCTION(BlueprintCallable)
    void EnableCharacter(ABase_Character* Character);
    
    UFUNCTION(BlueprintCallable)
    void DisableChildActorComponent(UChildActorComponent* ChildActorComponent);
    
    UFUNCTION(BlueprintCallable)
    void DisableCharacter(ABase_Character* Character);
    
    UFUNCTION(BlueprintCallable)
    bool CheckCondition(UWorldEventCondition* Conditon);
    
    
    // Fix for true pure virtual functions not being implemented
};

