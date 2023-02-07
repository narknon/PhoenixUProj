#pragma once
#include "CoreMinimal.h"
#include "BentDirectionalLightWindowAssets.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FBentDirectionalLightWindowAssets {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PaneMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ArrowMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PaneScalingFactor;
    
    GLOBALLIGHTRIG_API FBentDirectionalLightWindowAssets();
};

