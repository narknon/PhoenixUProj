#include "SceneRigMayaExportSphere.h"
#include "Components/SphereComponent.h"

ASceneRigMayaExportSphere::ASceneRigMayaExportSphere() {
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
}

