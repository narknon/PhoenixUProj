#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightAdvancedParameters.h"
#include "DirectionalLightBasicParameters.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightShafts.h"
#include "DirectionalLightParamsSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsSimple : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightAdvancedParameters Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShafts LightShafts;
    
    UDirectionalLightParamsSimple();
};

