#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshTagRules.h"
#include "MaterialSwapMeshTypeRules.h"
#include "MaterialSwapObjectRules.h"
#include "MaterialSwapMeshRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapMeshRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapObjectRules ObjectFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshTypeRules TypeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshTagRules TagFilter;
    
    MATERIALPERMUTER_API FMaterialSwapMeshRules();
};

