#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CameraStackTargetInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable)
class CAMERASTACK_API UCameraStackTargetInterface : public UInterface {
    GENERATED_BODY()
};

class CAMERASTACK_API ICameraStackTargetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* GetRuntimeTarget() const;
    
};

