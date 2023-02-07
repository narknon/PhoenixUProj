#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightDirection.h"
#include "DirectionalLightFollowCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightFollowCamera : public UDirectionalLightDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFixedAltitude;
    
    UDirectionalLightFollowCamera();
};

