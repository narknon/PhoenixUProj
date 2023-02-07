#include "Actor_SubsonicProximity.h"
#include "Components/SphereComponent.h"

AActor_SubsonicProximity::AActor_SubsonicProximity() {
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
}

