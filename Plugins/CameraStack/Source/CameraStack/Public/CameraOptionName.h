#pragma once
#include "CoreMinimal.h"
#include "CameraOptionName.generated.h"

USTRUCT(BlueprintType)
struct CAMERASTACK_API FCameraOptionName {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
public:
    FCameraOptionName();
};

