#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TickSequencerUpdateBucketList.h"
#include "TickSequencerUpdateComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTickSequencerUpdateBucketList Buckets;
    
    UTickSequencerUpdateComponent();
};

