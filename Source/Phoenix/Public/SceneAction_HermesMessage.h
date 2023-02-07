#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_HermesMessage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_HermesMessage : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Message;
    
    USceneAction_HermesMessage();
};

