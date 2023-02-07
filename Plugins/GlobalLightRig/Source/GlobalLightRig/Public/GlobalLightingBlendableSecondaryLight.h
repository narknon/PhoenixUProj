#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableSecondaryLight.generated.h"

class UDirectionalLightDirection;
class UDirectionalLightParams;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableSecondaryLight : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDirectionalLightDirection* SecondaryDirectionalLightDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDirectionalLightParams* SecondaryDirectionalLightParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType OverrideSource;
    
    UGlobalLightingBlendableSecondaryLight();
};

