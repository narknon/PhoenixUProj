#include "Actor_SubsonicProximity.h"
#include "Components/SphereComponent.h"

AActor_SubsonicProximity::AActor_SubsonicProximity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
}

