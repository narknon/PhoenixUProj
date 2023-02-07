#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ESexType.h"
#include "StationQueryData.h"
#include "StationInteractor_Interface.generated.h"

class AActor;
class ACharacter;
class APawn;
class ASocialReasoning;
class UStationComponent;

UINTERFACE(Blueprintable)
class UStationInteractor_Interface : public UInterface {
    GENERATED_BODY()
};

class IStationInteractor_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ThinkNow(const FString& InReason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StationStoryEndedWithoutConsent(UStationComponent* InStationComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool RequestStationInteraction(const FStationQueryData& InStationData, float InDuration, bool bUsedInDynamicInteraction, bool OverwritePreviousGoal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RequestStationExit(UStationComponent* InStationComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsTier4Actor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsTier3SeatFiller();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsTier3Character();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsHidden();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InteractionTerminated(UStationComponent* InStationComponent, const EEndPlayReason::Type InTerminationReason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool InDynamicInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetUniqueName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetUniqueID();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetSquaredDistanceToPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ESexType GetSexType();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ASocialReasoning* GetReasoning();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetPosition();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    APawn* GetPawn();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform GetInteractorTransform();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetFleshPrecacheRequested();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetFeetPosition();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetDbSubtypeID();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetDbHouseID();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UStationComponent* GetCurrentStation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCollisionRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ACharacter* GetCharacter();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ExitComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanJoinDynamicInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanBeLastOne();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AbortInteraction(UStationComponent* InStationComponent);
    
};

