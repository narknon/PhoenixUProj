#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "SceneRigActionState.h"
#include "SceneActionState_RenderSettings.generated.h"

UCLASS(Blueprintable)
class USceneActionState_RenderSettings : public USceneRigActionState/*, public IInterface_PostProcessVolume*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPostProcessSettings EnginePostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float InsertedPriortiy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentBlend;
    
    USceneActionState_RenderSettings();
    
    // Fix for true pure virtual functions not being implemented
};

