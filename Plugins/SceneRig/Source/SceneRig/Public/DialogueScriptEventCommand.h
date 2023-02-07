#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptCommand.h"
#include "DialogueScriptEventCommand.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptEventCommand : public UDialogueScriptCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineFraction;
    
    UDialogueScriptEventCommand();
};

