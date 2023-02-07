#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "OnRagdollHitActorEventSignatureDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRagdollHitActorEventSignature, AActor*, HitActor, const FVector&, NormalImpulse, const FHitResult&, HitResult);

