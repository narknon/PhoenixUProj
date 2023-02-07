#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRig_Fallback.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRig_Fallback : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneRigProvider*> Providers;
    
    USceneRig_Fallback();
};

