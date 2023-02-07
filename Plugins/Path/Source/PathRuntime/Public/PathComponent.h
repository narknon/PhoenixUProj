#pragma once
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "LinearizedPath.h"
#include "PathComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PATHRUNTIME_API UPathComponent : public USplineComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearizedPath LinearizedPath;
    
    UPROPERTY(EditAnywhere, NonPIEDuplicateTransient, meta=(AllowPrivateAccess=true))
    int64 UUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> ControlPointMap;
    
public:
    UPathComponent();
};

