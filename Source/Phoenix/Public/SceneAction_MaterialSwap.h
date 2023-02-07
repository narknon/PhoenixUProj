#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneActionMaterialSwapParameterColor.h"
#include "SceneActionMaterialSwapParameterScalar.h"
#include "SceneActionMaterialSwapParameterVector.h"
#include "SceneAction_MaterialSwap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaterialSwap : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionMaterialSwapParameterScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionMaterialSwapParameterVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionMaterialSwapParameterColor> Colors;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeaveSwappedMaterials;
    
    USceneAction_MaterialSwap();
};

