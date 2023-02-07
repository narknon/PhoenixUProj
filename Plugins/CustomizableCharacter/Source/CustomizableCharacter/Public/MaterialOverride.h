#pragma once
#include "CoreMinimal.h"
#include "MeshRule.h"
#include "MaterialOverride.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMeshRule> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UMaterialInterface*> Materials;
    
    CUSTOMIZABLECHARACTER_API FMaterialOverride();
};

