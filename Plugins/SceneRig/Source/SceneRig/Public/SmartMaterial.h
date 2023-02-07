#pragma once
#include "CoreMinimal.h"
#include "ModifyMaterials_MaterialOverride.h"
#include "SmartMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FSmartMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DefaultMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FModifyMaterials_MaterialOverride> MaterialOverrides;
    
    SCENERIG_API FSmartMaterial();
};

