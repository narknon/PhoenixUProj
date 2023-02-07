#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraPostProcessHandler.generated.h"

class UCameraComponent;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraPostProcessHandler : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCameraComponent> BlendCamera;
    
public:
    UCameraPostProcessHandler();
};

