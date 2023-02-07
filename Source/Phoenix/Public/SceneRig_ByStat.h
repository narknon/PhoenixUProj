#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRig_ByStat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRig_ByStat : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<int32, USceneRigProvider*> SceneRigs;
    
    USceneRig_ByStat();
};

