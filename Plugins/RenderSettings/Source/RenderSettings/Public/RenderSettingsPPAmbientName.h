#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPAmbientName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPAmbientName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPAmbientName();
};

