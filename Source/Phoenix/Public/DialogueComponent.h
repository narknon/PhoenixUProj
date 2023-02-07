#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UDialogueComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UDialogueComponent();
};

