#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetingFilter.h"
#include "EAblTargetingFilterSort.h"
#include "AblAbilityTargetingFilterSortByDistance.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblAbilityTargetingFilterSortByDistance : public UAblAbilityTargetingFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Use2DDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblTargetingFilterSort> m_SortDirection;
    
public:
    UAblAbilityTargetingFilterSortByDistance();
};

