#pragma once
#include "CoreMinimal.h"
#include "SocialAgentComponent.h"
#include "SocialAgentObstacleComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SOCIALDISPLAY_API USocialAgentObstacleComponent : public USocialAgentComponent {
    GENERATED_BODY()
public:
    USocialAgentObstacleComponent();
};

