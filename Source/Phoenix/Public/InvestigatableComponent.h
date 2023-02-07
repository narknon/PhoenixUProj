#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InvestigatableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInvestigatableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 totalInvestigations;
    
    UInvestigatableComponent();
    UFUNCTION(BlueprintCallable)
    bool GetInvestigatable();
    
};

