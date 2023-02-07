#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptEventCommand.h"
#include "ECommandForType.h"
#include "DialogueScriptEventExplicitPoseGroupCommand.generated.h"

class UNameProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptEventExplicitPoseGroupCommand : public UDialogueScriptEventCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* PoseGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECommandForType For;
    
    UDialogueScriptEventExplicitPoseGroupCommand();
};

