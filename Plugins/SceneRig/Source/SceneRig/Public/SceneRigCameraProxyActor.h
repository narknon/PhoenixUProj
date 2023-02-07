#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ESceneRigCameraProxyActor_ValidCameraType.h"
#include "SceneRigProxyActor.h"
#include "SceneRigCameraProxyActor.generated.h"

class UNameProvider;

UCLASS(Blueprintable, EditInlineNew)
class SCENERIG_API USceneRigCameraProxyActor : public USceneRigProxyActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* RegisteredCameraName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RegisterCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckObstructions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckTransitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RegisteredTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigCameraProxyActor_ValidCameraType ValidCameraType;
    
    USceneRigCameraProxyActor();
};

