#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectMonolithicAsset_Connection.h"
#include "BaseArchitectMonolithicAsset_Class.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FBaseArchitectMonolithicAsset_Class {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Categories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBaseArchitectMonolithicAsset_Connection> ConnectionArray;
    
    FBaseArchitectMonolithicAsset_Class();
};

