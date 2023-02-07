#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlockingActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFlockingActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEditorOnly;
    
    UFlockingActorComponent();
};

