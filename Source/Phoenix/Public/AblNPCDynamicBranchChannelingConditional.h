#pragma once
#include "CoreMinimal.h"
#include "AblChannelingBase.h"
#include "AlphaBlend.h"
#include "EEnemy_Ability.h"
#include "AblNPCDynamicBranchChannelingConditional.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPCDynamicBranchChannelingConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_CopyTargetsOnBranch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability AbilityState;
    
public:
    UAblNPCDynamicBranchChannelingConditional();
};

