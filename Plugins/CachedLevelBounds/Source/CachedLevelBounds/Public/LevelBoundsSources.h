#pragma once
#include "CoreMinimal.h"
#include "LevelBoundsSources.generated.h"

USTRUCT(BlueprintType)
struct CACHEDLEVELBOUNDS_API FLevelBoundsSources {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Sources;
    
    FLevelBoundsSources();
};

