#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightOff : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceVisibilityOff;
    
    UDirectionalLightOff();
};

