#pragma once
#include "CoreMinimal.h"
#include "CameraDefaultData.generated.h"

USTRUCT(BlueprintType)
struct CAMERASTACK_API FCameraDefaultData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FieldOfView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Aperture;
    
public:
    FCameraDefaultData();
};

