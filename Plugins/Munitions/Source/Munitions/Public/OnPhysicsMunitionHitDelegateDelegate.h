#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EPhysicsMunitionHitType.h"
#include "OnPhysicsMunitionHitDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPhysicsMunitionHitDelegate, EPhysicsMunitionHitType, PhysicsMunitionHitType, FHitResult, HitResult);

