#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightDirection.h"
#include "DirectionalLightSideLit.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightSideLit : public UDirectionalLightDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rotation;
    
    UDirectionalLightSideLit();
};

