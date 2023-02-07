#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "ClothMountTargets.h"
#include "SceneAction_ClothRobeMount.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ClothRobeMount : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClothMountTargets ClothMountTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetsOnly;
    
    USceneAction_ClothRobeMount();
};

