#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingControlComponent.h"
#include "GroundSwarmingForceModifier.h"
#include "GroundSwarmingExternalForceModifierComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UGroundSwarmingExternalForceModifierComponent : public UGroundSwarmingControlComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingForceModifier ForceModifier;
    
    UGroundSwarmingExternalForceModifierComponent();
};

