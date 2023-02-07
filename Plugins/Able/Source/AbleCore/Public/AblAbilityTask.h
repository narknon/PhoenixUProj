#pragma once
#include "CoreMinimal.h"
#include "AblAbilityNode.h"
#include "EAblAbilityTargetType.h"
#include "RelativeTime.h"
#include "AblAbilityTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAbilityTask : public UAblAbilityNode {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRelativeTime m_StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRelativeTime m_EndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EAblAbilityTargetType>> m_TaskTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Verbose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool m_IsDone;
    
public:
    UAblAbilityTask();
};

