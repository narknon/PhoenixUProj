#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "AIPerformTaskBase.generated.h"

class AActor;
class ASceneRigActor;
class UScheduledEntity;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class PHOENIX_API UAIPerformTaskBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* ParallelSceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipThisTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldWaitToFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ElementTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* HeadTrackingTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PerformTaskContainer;
    
    UAIPerformTaskBase();
protected:
    UFUNCTION(BlueprintCallable)
    void OnPerformTaskExecutionCompleteImp(UScheduledEntity* ScheduledEntity, int32 ActivityTypeBits);
    
    UFUNCTION(BlueprintCallable)
    void OnFleshLoadComplete(AActor* FleshActor);
    
};

