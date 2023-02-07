#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterBinding_FString.h"
#include "DialogueEvent_Direct.h"
#include "DialogEvent_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UDialogEvent_SceneRigParameter : public UDialogueEvent_Direct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_FString BoundParameter;
    
    UDialogEvent_SceneRigParameter();
};

