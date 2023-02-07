#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParametersRelative.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightParamsRelativeFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsRelativeFull : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightParametersRelative Parameters;
    
    UDirectionalLightParamsRelativeFull();
};

