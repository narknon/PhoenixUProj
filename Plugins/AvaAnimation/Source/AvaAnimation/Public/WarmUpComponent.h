#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WarmUpComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AVAANIMATION_API UWarmUpComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UWarmUpComponent();
};

