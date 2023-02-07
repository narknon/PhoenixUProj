#pragma once
#include "CoreMinimal.h"
#include "EnemyAIArrivedDelegateDelegate.generated.h"

class AActor;
class APathNode;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyAIArrivedDelegate, APathNode*, pPathNode, AActor*, pActor);

