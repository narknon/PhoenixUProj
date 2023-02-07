#pragma once
#include "CoreMinimal.h"
#include "ActionParameter_FString.h"
#include "SceneRigActionBase.h"
#include "SceneAction_SimpleDialogueSequence.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_SimpleDialogueSequence : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_FString EventNameParameter;
    
    USceneAction_SimpleDialogueSequence();
};

