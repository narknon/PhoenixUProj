#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldFXPerWorldSettings.h"
#include "WorldFXPresets.h"
#include "WorldFXSettings.generated.h"

UCLASS(Blueprintable)
class WORLDFX_API UWorldFXSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXPerWorldSettings Defaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FWorldFXPerWorldSettings> PerWorldDefaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXPresets Presets;
    
    UWorldFXSettings();
};

