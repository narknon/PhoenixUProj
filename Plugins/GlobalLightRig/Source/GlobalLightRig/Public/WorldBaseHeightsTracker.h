#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeights.h"
#include "WorldBaseHeightsTracker.generated.h"

USTRUCT(BlueprintType)
struct FWorldBaseHeightsTracker : public FWorldBaseHeights {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Force;
    
    GLOBALLIGHTRIG_API FWorldBaseHeightsTracker();
};

