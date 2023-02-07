#pragma once
#include "CoreMinimal.h"
#include "ManagedCharacterComponent.h"
#include "PhoenixManagedCharacter.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPhoenixManagedCharacter : public UManagedCharacterComponent {
    GENERATED_BODY()
public:
    UPhoenixManagedCharacter();
};

