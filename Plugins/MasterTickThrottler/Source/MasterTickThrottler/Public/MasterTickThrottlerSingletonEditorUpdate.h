#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MasterTickThrottlerSingletonEditorUpdate.generated.h"

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MASTERTICKTHROTTLER_API UMasterTickThrottlerSingletonEditorUpdate : public UActorComponent {
    GENERATED_BODY()
public:
    UMasterTickThrottlerSingletonEditorUpdate();
};

