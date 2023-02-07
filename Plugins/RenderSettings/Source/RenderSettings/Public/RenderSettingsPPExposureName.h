#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPExposureName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPExposureName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPExposureName();
};

