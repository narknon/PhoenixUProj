#include "SpawnCustomizableActor.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACustomizableActor;
class APawn;
class UObject;
class USpawnCustomizableActor;

USpawnCustomizableActor* USpawnCustomizableActor::SpawnCustomizableActor(UObject* WorldContextObject, TSubclassOf<ACustomizableActor> Class, const FName RegistryId, const FTransform& Transform, AActor* Owner, APawn* Instigator, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride) {
    return NULL;
}

void USpawnCustomizableActor::OnFinishLoading(AActor* InOwner) {
}

USpawnCustomizableActor::USpawnCustomizableActor() {
}

