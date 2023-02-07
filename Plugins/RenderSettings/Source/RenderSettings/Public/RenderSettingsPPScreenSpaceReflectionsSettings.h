#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPPScreenSpaceReflections.h"
#include "RenderSettingsPPScreenSpaceReflectionsSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPPScreenSpaceReflectionsSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPPScreenSpaceReflections> Settings;
    
    URenderSettingsPPScreenSpaceReflectionsSettings();
};

