#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RiverAudioPoint.generated.h"

USTRUCT(BlueprintType)
struct FRiverAudioPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedOfFlow;
    
    FLOW_API FRiverAudioPoint();
};

