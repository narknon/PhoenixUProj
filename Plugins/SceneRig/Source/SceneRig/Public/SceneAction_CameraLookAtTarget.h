#pragma once
#include "CoreMinimal.h"
#include "ECameraStackLookAtStrength.h"
#include "SceneRigActionBase.h"
#include "SceneAction_CameraLookAtTarget.generated.h"

class UActorProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CameraLookAtTarget : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* LookAtLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackLookAtStrength LookAtStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* TriggerVolume;
    
    USceneAction_CameraLookAtTarget();
};

