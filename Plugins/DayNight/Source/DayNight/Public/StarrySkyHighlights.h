#pragma once
#include "CoreMinimal.h"
#include "StarrySkyHighlights.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FStarrySkyHighlights {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Constellations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Stars;
    
    FStarrySkyHighlights();
};

