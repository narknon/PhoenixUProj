#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactCapsuleImpulseVelocitySource.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactCapsuleImpulseVelocitySource : uint8 {
    ReactionDataVelocity,
    ReactorBackwards,
    ReactorFowards,
    ReactorLeft,
    ReactorRight,
    InstigatorTowards,
    InstigatorAway,
    InstigatorLeft,
    InstigatorRight,
    ImpactDirectionTowards,
    ImpactDirectionAway,
    ImpactDirectionLeft,
    ImpactDirectionRight,
    TargetActorTowards,
    TargetActorAway,
    TargetActorLeft,
    TargetActorRight,
    ReactionDataDirection,
};

