#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPostProcessingGroupName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPostProcessingGroupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPostProcessingGroupName();
};

