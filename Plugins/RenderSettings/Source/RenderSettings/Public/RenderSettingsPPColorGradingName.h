#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPColorGradingName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPColorGradingName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPColorGradingName();
};

