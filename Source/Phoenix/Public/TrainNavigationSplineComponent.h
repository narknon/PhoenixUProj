#pragma once
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "TrainNavRenderSplines.h"
#include "TrainNavigationSplineComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTrainNavigationSplineComponent : public USplineComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTrainNavRenderSplines> GeometryTrackSplines;
    
public:
    UTrainNavigationSplineComponent();
};

