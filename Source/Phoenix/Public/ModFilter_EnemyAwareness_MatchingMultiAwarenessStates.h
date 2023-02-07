#pragma once
#include "CoreMinimal.h"
#include "ModFilter_EnemyAwareness_Base.h"
#include "NPC_TargetAwareStateRateSource.h"
#include "ModFilter_EnemyAwareness_MatchingMultiAwarenessStates.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_EnemyAwareness_MatchingMultiAwarenessStates : public UModFilter_EnemyAwareness_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<NPC_TargetAwareStateRateSource> MatchingAwarenessStates;
    
public:
    UModFilter_EnemyAwareness_MatchingMultiAwarenessStates();
};

