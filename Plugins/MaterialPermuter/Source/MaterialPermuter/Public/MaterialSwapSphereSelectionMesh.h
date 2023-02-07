#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MaterialSwapSphereSelectionMesh.generated.h"

class UMaterialSwap;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapSphereSelectionMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LastTouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 SwapSphereMaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSwappable;
    
    FMaterialSwapSphereSelectionMesh();
};

