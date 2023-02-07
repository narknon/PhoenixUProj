#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEvaluatorRootMotion -FallbackName=EEvaluatorRootMotion
#include "AblAbilityTask.h"
#include "EAnimBlendTickStyle.h"
#include "EEvaluatorRootMotion.h"
#include "AblConditionalBranchTaskBase.generated.h"

class UAblTaskCondition;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblConditionalBranchTaskBase : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> BranchConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideAnimationBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend AnimationBlendInOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClampBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> SourceRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> DestRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideBlendTickStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimBlendTickStyle BlendTickStyleOverride;
    
public:
    UAblConditionalBranchTaskBase();
};

