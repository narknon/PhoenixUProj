#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsEmissiveAdaptationName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsEmissiveAdaptationName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsEmissiveAdaptationName();
};

