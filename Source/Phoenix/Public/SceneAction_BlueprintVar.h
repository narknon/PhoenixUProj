#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_BlueprintVar.generated.h"

class USceneActionBlueprintVarProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_BlueprintVar : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneActionBlueprintVarProvider*> BlueprintVariables;
    
    USceneAction_BlueprintVar();
};

