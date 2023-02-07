#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
#include "AblAbilityEvent.h"
#include "Templates/SubclassOf.h"
#include "AblBranchEvent.generated.h"

class UAblAbility;
class UAblBranchCondition;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblBranchEvent : public UAblAbilityEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> m_BranchAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_DynamicBranchAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_DynamicBranchEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblBranchCondition*> m_Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_MustPassAllConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_CopyTargetsOnBranch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlendOut;
    
public:
    UAblBranchEvent();
};

