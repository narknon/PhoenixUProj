#pragma once
#include "CoreMinimal.h"
#include "ActionParameter_FString.h"
#include "SceneRigActionBase.h"
#include "SceneAction_SuspendEnemies.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_SuspendEnemies : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_FString EventNameParameter;
    
    USceneAction_SuspendEnemies();
};

