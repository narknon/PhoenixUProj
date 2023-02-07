#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptEventCommand.h"
#include "ECommandLookAtType.h"
#include "DialogueScriptEventExplicitCameraShotCommand.generated.h"

class UNameProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptEventExplicitCameraShotCommand : public UDialogueScriptEventCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* CameraShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECommandLookAtType LookAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockLineImplicitCameraChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockEndingCameraChanges;
    
    UDialogueScriptEventExplicitCameraShotCommand();
};

