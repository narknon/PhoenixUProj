#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MaterialSwapMeshStateIntMap.h"
#include "MaterialSwapMeshStateLightingChannels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateLightingChannels : public UMaterialSwapMeshStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightingChannels LightingChannels;
    
    UMaterialSwapMeshStateLightingChannels();
};

