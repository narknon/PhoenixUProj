#pragma once
#include "CoreMinimal.h"
#include "PlayerCentricPostProcessingOverride.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FPlayerCentricPostProcessingOverride {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostProcessingViewpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpAlpha;
    
    RENDERSETTINGS_API FPlayerCentricPostProcessingOverride();
};

