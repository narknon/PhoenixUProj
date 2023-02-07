#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPDepthOfFieldName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPDepthOfFieldName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPDepthOfFieldName();
};

