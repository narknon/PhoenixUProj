#pragma once
#include "CoreMinimal.h"
#include "CameraOptionMappings.generated.h"

USTRUCT(BlueprintType)
struct CAMERASTACK_API FCameraOptionMappings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> Names;
    
public:
    FCameraOptionMappings();
};

