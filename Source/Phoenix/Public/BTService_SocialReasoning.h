#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "BTService_AvaAITree.h"
#include "TimeEvent.h"
#include "EStationInteraction.h"
#include "QueryFinishedData.h"
#include "BTService_SocialReasoning.generated.h"

class ASocialReasoning;
class UEnvQueryInstanceBlueprintWrapper;
class UStationComponent;

UCLASS(Abstract, Blueprintable)
class UBTService_SocialReasoning : public UBTService_AvaAITree {
    GENERATED_BODY()
public:
    UBTService_SocialReasoning();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Think(const ASocialReasoning* SocialReasoning, const FTimeEvent& TimeEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RunEQS_FindStations(const ASocialReasoning* SocialReasoning, EEnvQueryRunMode::Type RunMode, const FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RunEQS_FindSocialReasonings(const ASocialReasoning* SocialReasoning, EEnvQueryRunMode::Type RunMode, const FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayerSighted(const ASocialReasoning* SocialReasoning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PerformTask_WaitForPlayer(const ASocialReasoning* SocialReasoning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PerformTask_MoveToStation(const ASocialReasoning* SocialReasoning, const UStationComponent* InStation, const EStationInteraction InStationInteractionType, const FName InActionName, const int32 InConnectionIndex, const float InStationUseDuration, const bool InSkipValidationForTeleport);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PerformTask_MoveToLocation(const ASocialReasoning* SocialReasoning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InteractionCallback(const ASocialReasoning* SocialReasoning, UStationComponent* InStation);
    
private:
    UFUNCTION(BlueprintCallable)
    void ExecuteEQSQueryFinished(const FQueryFinishedData& QueryFinishedDelegate, UEnvQueryInstanceBlueprintWrapper* QueryInstance, TEnumAsByte<EEnvQueryStatus::Type> QueryStatus);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Companionship(const ASocialReasoning* SocialReasoning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Combat(const ASocialReasoning* SocialReasoning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Chat(const ASocialReasoning* SocialReasoning);
    
};

