#pragma once
#include "CoreMinimal.h"
#include "StationStoryAnimationContent.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct FStationStoryAnimationContent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> Animation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    PHOENIX_API FStationStoryAnimationContent();
};

