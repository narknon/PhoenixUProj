#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComputedLevelBounds.h"
#include "GameFriendlyLevelName.h"
#include "CompositeLevelBounds.generated.h"

USTRUCT(BlueprintType)
struct CACHEDLEVELBOUNDS_API FCompositeLevelBounds {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputedLevelBounds Bounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameFriendlyLevelName LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan Timestamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMarkedRemoved;
    
    FCompositeLevelBounds();
};

