#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablNPCPhysicsTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNPCPhysicsTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideCapsulePhysicsSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableCapsuleGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSimulateCapsulePhysics;
    
public:
    UablNPCPhysicsTask();
};

