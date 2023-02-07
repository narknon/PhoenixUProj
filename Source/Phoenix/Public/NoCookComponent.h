#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PerPlatformProperties.h"
#include "NoCookComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UNoCookComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerPlatformBool NoCookActor;
    
    UNoCookComponent();
};

