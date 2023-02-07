#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackLimitsInterface.h"
#include "CameraStackBehaviorPitchToTransformCurves.generated.h"

class UCameraStackTransformCurveData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorPitchToTransformCurves : public UCameraStackBehaviorBlend, public ICameraStackLimitsInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraStackTransformCurveData* CurveData;
    
public:
    UCameraStackBehaviorPitchToTransformCurves();
    
    // Fix for true pure virtual functions not being implemented
};

