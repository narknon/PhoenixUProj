#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolWithinDistanceToCamera.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolWithinDistanceToCamera : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceInMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInFrontOnly;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxCameraDistanceSquared;
    
public:
    UFXAutoTriggerBoolWithinDistanceToCamera();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetMaxCameraDistanceMeters(float MaxCameraDistanceMeters) const;
    
};

