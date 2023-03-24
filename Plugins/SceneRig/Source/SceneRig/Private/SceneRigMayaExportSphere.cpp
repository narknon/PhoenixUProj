#include "SceneRigMayaExportSphere.h"
#include "Components/SphereComponent.h"

ASceneRigMayaExportSphere::ASceneRigMayaExportSphere(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
}

