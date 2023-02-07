#pragma once
#include "CoreMinimal.h"
#include "AnimTrackRangedFloat.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimTrackRangedFloat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMax;
    
    FAnimTrackRangedFloat();
};

