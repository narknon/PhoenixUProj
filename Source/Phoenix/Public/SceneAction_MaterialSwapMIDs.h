#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoInPlaceMIDs.h"
#include "MaterialSwapParameters.h"
#include "SceneAction_MaterialSwap.h"
#include "SceneAction_MaterialSwapMIDs.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwapMIDs : public USceneAction_MaterialSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfoInPlaceMIDs Swap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    USceneAction_MaterialSwapMIDs();
};

