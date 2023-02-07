#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset_SoftDependencyContainer.h"
#include "BaseArchitectAsset.generated.h"

class UBaseArchitectAsset;

UCLASS(Abstract, Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UBaseArchitectAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBaseArchitectAsset*> HardDependencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBaseArchitectAsset_SoftDependencyContainer> SoftDependencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> DefaultKeyOrder;
    
    UBaseArchitectAsset();
};

