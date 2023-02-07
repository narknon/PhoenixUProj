#pragma once
#include "CoreMinimal.h"
#include "CompositeLevelBounds.h"
#include "WorldLevelsBounds.generated.h"

class ULevel;

USTRUCT(BlueprintType)
struct CACHEDLEVELBOUNDS_API FWorldLevelsBounds {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<ULevel>, FCompositeLevelBounds> Bounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TickInitialized;
    
    FWorldLevelsBounds();
};

