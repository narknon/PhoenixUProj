#pragma once
#include "CoreMinimal.h"
#include "ECameraFixupLayer.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_CameraFixup.generated.h"

class UCameraFixupOperation;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_CameraFixup : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraFixupLayer Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupOperation*> FixupOperations;
    
    USceneAction_CameraFixup();
};

