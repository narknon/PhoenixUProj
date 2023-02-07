#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectionalLightDirection.h"
#include "DirectionalLightConstantDirection.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightConstantDirection : public UDirectionalLightDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
    UDirectionalLightConstantDirection();
};

