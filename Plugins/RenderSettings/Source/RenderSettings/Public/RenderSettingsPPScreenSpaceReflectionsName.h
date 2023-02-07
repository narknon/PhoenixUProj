#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPScreenSpaceReflectionsName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPPScreenSpaceReflectionsName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsPPScreenSpaceReflectionsName();
};

