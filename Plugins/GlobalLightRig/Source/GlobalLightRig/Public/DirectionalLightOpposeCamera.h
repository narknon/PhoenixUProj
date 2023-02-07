#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightDirection.h"
#include "DirectionalLightOpposeCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightOpposeCamera : public UDirectionalLightDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFixedAltitude;
    
    UDirectionalLightOpposeCamera();
};

