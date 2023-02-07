#pragma once
#include "CoreMinimal.h"
#include "SendTargetComponentHitSignatureDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSendTargetComponentHitSignature, AActor*, SelfActor, AActor*, OtherActor);

