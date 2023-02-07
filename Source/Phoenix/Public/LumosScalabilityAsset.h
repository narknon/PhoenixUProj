#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LumosScalabilitySettings.h"
#include "LumosScalabilityAsset.generated.h"

UCLASS(Blueprintable)
class ULumosScalabilityAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLumosScalabilitySettings Settings;
    
    ULumosScalabilityAsset();
};

