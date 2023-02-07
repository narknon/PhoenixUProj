#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FlowWaveSystemSettingsData.h"
#include "FlowWaveSystemSettings.generated.h"

UCLASS(Blueprintable)
class UFlowWaveSystemSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlowWaveSystemSettingsData GlobalSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlowWaveSystemSettingsData> PerLevelSettings;
    
    UFlowWaveSystemSettings();
};

