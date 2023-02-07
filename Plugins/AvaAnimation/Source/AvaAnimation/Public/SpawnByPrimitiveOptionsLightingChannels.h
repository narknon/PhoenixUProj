#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsLightingChannels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsLightingChannels : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightingChannels LightingChannels;
    
    USpawnByPrimitiveOptionsLightingChannels();
};

