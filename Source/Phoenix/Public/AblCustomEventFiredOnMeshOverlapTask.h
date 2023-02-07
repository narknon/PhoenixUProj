#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCustomEventFiredOnMeshOverlapTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCustomEventFiredOnMeshOverlapTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BodyNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionProfileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomEventName;
    
    UAblCustomEventFiredOnMeshOverlapTask();
};

