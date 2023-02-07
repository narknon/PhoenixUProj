#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapPriority.h"
#include "MaterialSwapInfoInPlaceMIDsBase.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapInfoInPlaceMIDs.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapInfoInPlaceMIDs : public FMaterialSwapInfoInPlaceMIDsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    FMaterialSwapInfoInPlaceMIDs();
};

