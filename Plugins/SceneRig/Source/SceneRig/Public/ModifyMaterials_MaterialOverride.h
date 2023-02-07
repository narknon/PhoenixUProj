#pragma once
#include "CoreMinimal.h"
#include "ModifyMaterials_MaterialOverride.generated.h"

class UFXRule;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FModifyMaterials_MaterialOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXRule*> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    SCENERIG_API FModifyMaterials_MaterialOverride();
};

