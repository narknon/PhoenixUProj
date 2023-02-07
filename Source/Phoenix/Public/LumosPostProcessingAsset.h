#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Scene.h"
#include "LumosPostProcessingAsset.generated.h"

UCLASS(Blueprintable)
class ULumosPostProcessingAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    ULumosPostProcessingAsset();
};

