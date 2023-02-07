#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAnimBlendTickStyle.h"
#include "AlphaBlend.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEvaluatorRootMotion -FallbackName=EEvaluatorRootMotion
#include "EEvaluatorRootMotion.h"
#include "Name_GameLogicBoolResult.h"
#include "Templates/SubclassOf.h"
#include "AblGameLogicSwitchBranchTask.generated.h"

class UAblAbility;

UCLASS(Blueprintable, EditInlineNew)
class UAblGameLogicSwitchBranchTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName_GameLogicBoolResult, TSubclassOf<UAblAbility>> BoolResultToAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DefaultAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_CopyTargetsOnBranch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bOverrideTransitionBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bOverrideTransitionBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClampBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseSourceRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseDestRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_OverrideRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_OverrideBlendTickStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimBlendTickStyle m_BlendTickStyle;
    
    UAblGameLogicSwitchBranchTask();
};

