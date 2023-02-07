#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "PhysicalBodyNameWeightPair.h"
#include "AlphaBlend.h"
#include "ablPhysicalBodyBlendTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablPhysicalBodyBlendTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPhysicalBodyNameWeightPair> PerBoneBlendWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlphaBlendOption BlendInOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlphaBlendOption BlendOutOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bContinous;
    
public:
    UablPhysicalBodyBlendTask();
};

