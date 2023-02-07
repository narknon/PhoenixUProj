#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeInstanceParametersBase.h"
#include "WorldFXCascadeSystemParams.h"
#include "WorldFXCascadeInstanceParametersGrouped.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXCascadeInstanceParametersGrouped : public UWorldFXCascadeInstanceParametersBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCascadeSystemParams InstanceParameters;
    
    UWorldFXCascadeInstanceParametersGrouped();
};

