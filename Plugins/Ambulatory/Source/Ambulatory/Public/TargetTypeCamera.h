#pragma once
#include "CoreMinimal.h"
#include "TargetTypeBase.h"
#include "TargetTypeCamera.generated.h"

class APlayerCameraManager;

UCLASS(Blueprintable)
class AMBULATORY_API UTargetTypeCamera : public UTargetTypeBase {
    GENERATED_BODY()
public:
    UTargetTypeCamera();
    UFUNCTION(BlueprintCallable)
    void SetPlayerCameraManager(APlayerCameraManager* InPlayerCameraManager);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerCameraManager* GetPlayerCameraManager() const;
    
};

