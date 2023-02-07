#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPLensFXName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPLensFXName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPLensFXName();
};

