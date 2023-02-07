#pragma once
#include "CoreMinimal.h"
#include "RenderingCutBits.generated.h"

USTRUCT(BlueprintType)
struct FRenderingCutBits {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RenderingCuts;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Frames;
    
    PHOENIX_API FRenderingCutBits();
};

