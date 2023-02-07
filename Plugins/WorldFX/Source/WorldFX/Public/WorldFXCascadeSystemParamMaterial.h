#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystemParamBase.h"
#include "WorldFXCascadeSystemParamMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParamMaterial : public FWorldFXCascadeSystemParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    FWorldFXCascadeSystemParamMaterial();
};

