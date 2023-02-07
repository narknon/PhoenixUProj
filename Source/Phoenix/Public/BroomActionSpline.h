#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "BroomRiderActionContainer.h"
#include "EActionsCompleteBehaviour.h"
#include "Templates/SubclassOf.h"
#include "BroomActionSpline.generated.h"

class ABroomActionSpline;
class AFlyingBroom;
class UFlyingBroomPhysics;
class USplineComponent;

UCLASS(Blueprintable)
class ABroomActionSpline : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BroomActionSplineName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ScheduledEntityName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceHighLOD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMountIfNotAlready;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlyingBroom> BroomToUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics* BroomPhysicsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBroomRiderActionContainer> ActionsToBePerformedContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EActionsCompleteBehaviour EndBehaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABroomActionSpline* NextBroomActionSpline;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSaveState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSaveTaskState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFlyingBroom* NPCBroom;
    
public:
    ABroomActionSpline();
    UFUNCTION(BlueprintCallable)
    void TriggerEndBehaviour(bool bOverrideEndBehaviour, EActionsCompleteBehaviour EndBehaviourOverride);
    
    UFUNCTION(BlueprintCallable)
    void StartBroomActionSequence();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
};

