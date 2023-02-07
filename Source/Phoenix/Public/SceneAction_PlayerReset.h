#pragma once
#include "CoreMinimal.h"
#include "ECameraStackResetType.h"
#include "SceneRigActionBase.h"
#include "SceneAction_PlayerReset.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PlayerReset : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* TeleportTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackResetType CameraResetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* CameraResetLookAtLocation;
    
    USceneAction_PlayerReset();
};

