#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_SoftDependencyContainer.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FBaseArchitectAsset_SoftDependencyContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AssetNames;
    
    FBaseArchitectAsset_SoftDependencyContainer();
};

