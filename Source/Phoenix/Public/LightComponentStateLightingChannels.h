#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "LightComponentStateIntMap.h"
#include "LightComponentStateLightingChannels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateLightingChannels : public ULightComponentStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightingChannels LightingChannels;
    
    ULightComponentStateLightingChannels();
};

