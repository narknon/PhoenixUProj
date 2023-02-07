#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRig_ByPlayerGender.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRig_ByPlayerGender : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* Male;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* Female;
    
    USceneRig_ByPlayerGender();
};

