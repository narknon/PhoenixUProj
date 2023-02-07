#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player_QuickActionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayer_QuickActionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPlayer_QuickActionComponent();
};

