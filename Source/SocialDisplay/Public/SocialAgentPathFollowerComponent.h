#pragma once
#include "CoreMinimal.h"
#include "SocialAgentPawnComponent.h"
#include "SocialAgentPathFollowerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SOCIALDISPLAY_API USocialAgentPathFollowerComponent : public USocialAgentPawnComponent {
    GENERATED_BODY()
public:
    USocialAgentPathFollowerComponent();
};

