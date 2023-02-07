#pragma once
#include "CoreMinimal.h"
#include "WorldBaseHeightBase.h"
#include "WorldBaseHeightShape.generated.h"

UCLASS(Abstract, Blueprintable)
class GLOBALLIGHTRIG_API AWorldBaseHeightShape : public AWorldBaseHeightBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadiusPercentage;
    
    AWorldBaseHeightShape();
};

