#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSkinFXTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSkinFXTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName skinEffectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEndEffectOnExit;
    
public:
    UAblSkinFXTask();
};

