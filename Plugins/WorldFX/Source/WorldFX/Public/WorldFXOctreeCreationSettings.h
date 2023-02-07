#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeCreationSettings.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXOctreeCreationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpandWorldBoundsFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpandWorldBoundsRadiusMeters;
    
    WORLDFX_API FWorldFXOctreeCreationSettings();
};

