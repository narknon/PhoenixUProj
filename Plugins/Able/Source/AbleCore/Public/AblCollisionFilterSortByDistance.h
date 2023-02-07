#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetTypeLocation.h"
#include "AblCollisionFilter.h"
#include "EAblCollisionFilterSort.h"
#include "AblCollisionFilterSortByDistance.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionFilterSortByDistance : public UAblCollisionFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblCollisionFilterSort> m_SortDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAbilityTargetTypeLocation m_Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Use2DDistance;
    
public:
    UAblCollisionFilterSortByDistance();
};

