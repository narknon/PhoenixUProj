#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCreatureMakeNoiseTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCreatureMakeNoiseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NoiseEventTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Loudness;
    
    UAblCreatureMakeNoiseTask();
};

