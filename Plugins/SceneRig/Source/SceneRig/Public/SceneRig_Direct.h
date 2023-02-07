#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRig_Direct.generated.h"

class USceneRig;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRig_Direct : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* SceneRig;
    
    USceneRig_Direct();
};

