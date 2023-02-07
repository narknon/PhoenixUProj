#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ESchedulerMoonPhase.h"
#include "WorldMoonPhaseConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldMoonPhaseConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESchedulerMoonPhase> DesiredMoonPhase;
    
public:
    UWorldMoonPhaseConsideration();
};

