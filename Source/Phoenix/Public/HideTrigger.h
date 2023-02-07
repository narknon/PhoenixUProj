#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TriggerBox.h"
#include "SceneRigParticipant.h"
#include "EDynamicObstacleShape.h"
#include "HideTrigger.generated.h"

class AActor;
class ANavigationDisruptor;
class UOdcObstacleComponent;
class UShapeComponent;

UCLASS(Blueprintable)
class PHOENIX_API AHideTrigger : public ATriggerBox, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HideFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PauseScheduleFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> ExcludeNamed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> ExcludeNamedCreatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> ExcludeCreatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShutdownExternalNpcs;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDynamicObstacleShape DynamicObstacleShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* DynamicObstacle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumHideFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOdcObstacleComponent* NavObstacle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ANavigationDisruptor* NavigationDisruptor;
    
public:
    AHideTrigger();
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndAggroActorOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnEndActorOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginAggroActorOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginActorOverlap(AActor* SelfActor, AActor* OtherActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void Deactivate(bool bInFromEndPlay);
    
    UFUNCTION(BlueprintCallable)
    void Activate();
    
    
    // Fix for true pure virtual functions not being implemented
};

