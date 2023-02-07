#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_DisableConversationCamera.generated.h"

class UNameProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_DisableConversationCamera : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> EnabledRegisteredCameraNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> DisabledRegisteredCameraNames;
    
    USceneAction_DisableConversationCamera();
};

