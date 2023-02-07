#pragma once
#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "OnDeferredChildActorSpawnedDelegate.h"
#include "DeferredChildActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UDeferredChildActorComponent : public UChildActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeferredChildActorSpawned OnDeferredChildActorSpawned;
    
    UDeferredChildActorComponent();
};

