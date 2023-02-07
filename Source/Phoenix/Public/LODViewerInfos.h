#pragma once
#include "CoreMinimal.h"
#include "LODViewerInfos.generated.h"

USTRUCT(BlueprintType)
struct FLODViewerInfos {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScreenSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Hysteresis;
    
    PHOENIX_API FLODViewerInfos();
};

