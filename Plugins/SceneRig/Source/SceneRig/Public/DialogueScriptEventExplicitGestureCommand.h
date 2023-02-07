#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptEventCommand.h"
#include "ECommandForType.h"
#include "DialogueScriptEventExplicitGestureCommand.generated.h"

class UNameProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptEventExplicitGestureCommand : public UDialogueScriptEventCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* Gesture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECommandForType For;
    
    UDialogueScriptEventExplicitGestureCommand();
};

