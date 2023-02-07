#pragma once
#include "CoreMinimal.h"
#include "SceneRigCameraParams.generated.h"

class UObjectProvider;

USTRUCT(BlueprintType)
struct FSceneRigCameraParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* InitialCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* FinalCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* Camera;
    
    SCENERIG_API FSceneRigCameraParams();
};

