#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneRigMayaExportSphere.generated.h"

class USphereComponent;

UCLASS(Blueprintable)
class SCENERIG_API ASceneRigMayaExportSphere : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereComponent;
    
public:
    ASceneRigMayaExportSphere();
};

