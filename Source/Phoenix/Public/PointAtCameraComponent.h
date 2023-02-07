#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OrientToSlerp.h"
#include "PointAtComponent.h"
#include "PointAtCameraComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPointAtCameraComponent : public UPointAtComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOrientToSlerp Smoothing;
    
    UPointAtCameraComponent();
};

