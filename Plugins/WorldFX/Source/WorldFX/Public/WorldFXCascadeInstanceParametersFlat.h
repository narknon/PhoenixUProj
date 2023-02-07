#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeInstanceParametersBase.h"
#include "WorldFXCascadeSystemParam.h"
#include "WorldFXCascadeInstanceParametersFlat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXCascadeInstanceParametersFlat : public UWorldFXCascadeInstanceParametersBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParam> InstanceParameters;
    
    UWorldFXCascadeInstanceParametersFlat();
};

