#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPBloomName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPBloomName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPBloomName();
};

