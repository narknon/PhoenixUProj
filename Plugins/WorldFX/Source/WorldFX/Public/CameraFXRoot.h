#pragma once
#include "CoreMinimal.h"
#include "CameraFXRoot.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct WORLDFX_API FCameraFXRoot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CameraFXRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 UnattachedFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUnattachedFrames;
    
    FCameraFXRoot();
};

