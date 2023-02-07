#pragma once
#include "CoreMinimal.h"
#include "AITypes.h"
#include "Tasks/AITask.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTask.h"
#include "EMercunaMoveResult.h"
#include "MercunaMoveTaskCompletedSignatureDelegate.h"
#include "MercunaTask_MoveTo.generated.h"

class AAIController;
class AActor;
class UMercunaTask_MoveTo;

UCLASS(Blueprintable)
class MERCUNA_API UMercunaTask_MoveTo : public UAITask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameplayTask::FGenericGameplayTaskDelegate OnRequestFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaMoveTaskCompletedSignature OnMoveFinished;
    
public:
    UMercunaTask_MoveTo();
protected:
    UFUNCTION(BlueprintCallable)
    void OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result);
    
public:
    UFUNCTION(BlueprintCallable)
    static UMercunaTask_MoveTo* MercunaMoveTo(AAIController* Controller, FVector GoalLocation, AActor* GoalActor, float EndDistance, bool AcceptPartialPath, bool bLockAILogic);
    
};

