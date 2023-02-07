#pragma once
#include "CoreMinimal.h"
#include "FlyingBroomPhysicsScratch.h"
#include "FlyingBroomPhysicsScratch_Spline.generated.h"

class UFlyingBroomPhysics_Spline;
class USplineComponent;

UCLASS(Blueprintable)
class UFlyingBroomPhysicsScratch_Spline : public UFlyingBroomPhysicsScratch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics_Spline* PhysicsData;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USplineComponent> SplineComponent;
    
    UFlyingBroomPhysicsScratch_Spline();
};

