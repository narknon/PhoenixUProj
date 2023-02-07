#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSetMeshHiddenInGameTask.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UAblSetMeshHiddenInGameTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMeshTargetInOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RestoreHiddenValueAtEndOfTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SetHiddenValue;
    
    UAblSetMeshHiddenInGameTask();
};

