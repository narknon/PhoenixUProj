#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParameters.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsFull : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightParameters Parameters;
    
    UDirectionalLightParamsFull();
};

