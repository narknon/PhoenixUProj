#pragma once
#include "CoreMinimal.h"
#include "AudioDialogueFlags.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_DialogueEvent.generated.h"

class UDialogueEventProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_DialogueEvent : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogueEventProvider* Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CutoffDialogueAtFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueFlags AudioDialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* AtLocation;
    
    USceneAction_DialogueEvent();
};

