#pragma once
#include "CoreMinimal.h"
#include "ActorDiedSignatureDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorDiedSignature, AActor*, DeadActor);

