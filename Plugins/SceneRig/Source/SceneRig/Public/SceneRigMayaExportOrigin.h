#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneRigMayaExportOrigin.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API ASceneRigMayaExportOrigin : public AActor {
    GENERATED_BODY()
public:
    ASceneRigMayaExportOrigin(const FObjectInitializer& ObjectInitializer);
};

