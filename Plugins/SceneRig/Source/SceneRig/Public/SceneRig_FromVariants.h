#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRig_FromVariants.generated.h"

class USceneRigVariants;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRig_FromVariants : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigVariants* Variants;
    
    USceneRig_FromVariants();
};

