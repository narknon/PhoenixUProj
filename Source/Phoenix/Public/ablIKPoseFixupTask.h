#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "IKPoseFixupDefinition.h"
#include "ablIKPoseFixupTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablIKPoseFixupTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKPoseFixupDefinition Definition;
    
public:
    UablIKPoseFixupTask();
};

