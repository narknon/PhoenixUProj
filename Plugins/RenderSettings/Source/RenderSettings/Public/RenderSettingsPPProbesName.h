#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPProbesName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPProbesName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPProbesName();
};

