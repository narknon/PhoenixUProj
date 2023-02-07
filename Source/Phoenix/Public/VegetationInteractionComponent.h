#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VegetationInteractionComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVegetationInteractionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuspend;
    
    UVegetationInteractionComponent();
};

