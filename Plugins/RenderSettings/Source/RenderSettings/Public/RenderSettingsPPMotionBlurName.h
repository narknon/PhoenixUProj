#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPMotionBlurName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPMotionBlurName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPMotionBlurName();
};

