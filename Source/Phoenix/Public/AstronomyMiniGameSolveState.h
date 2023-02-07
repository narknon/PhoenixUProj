#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstronomyMiniGameSolveState.generated.h"

USTRUCT(BlueprintType)
struct FAstronomyMiniGameSolveState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotator;
    
    PHOENIX_API FAstronomyMiniGameSolveState();
};

