#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OdcFlags.h"
#include "EAreaUsageFlagSelection.h"
#include "OptionActorLocationWithinAreaFlagsConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorLocationWithinAreaFlagsConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAreaUsageFlagSelection AreaFlagSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags CustomAreaFlags;
    
public:
    UOptionActorLocationWithinAreaFlagsConsideration();
};

