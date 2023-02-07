#pragma once
#include "CoreMinimal.h"
#include "CameraStackData.generated.h"

class UCameraStackBehavior;
class UCameraStackBehaviorCore;

USTRUCT(BlueprintType)
struct FCameraStackData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackBehaviorCore* CoreBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraStackBehavior*> Behaviors;
    
public:
    CAMERASTACK_API FCameraStackData();
};

