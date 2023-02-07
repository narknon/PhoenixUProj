#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComputedLevelBounds.generated.h"

USTRUCT(BlueprintType)
struct CACHEDLEVELBOUNDS_API FComputedLevelBounds {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox Total;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox Landscape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsedLevelBoundsActor;
    
    FComputedLevelBounds();
};

