#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPPLensFX.h"
#include "RenderSettingsPPLensFXSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPPLensFXSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPPLensFX> Settings;
    
    URenderSettingsPPLensFXSettings();
};

