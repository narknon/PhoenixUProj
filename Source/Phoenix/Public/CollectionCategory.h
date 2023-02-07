#pragma once
#include "CoreMinimal.h"
#include "CollectionSubcategory.h"
#include "CollectionCategory.generated.h"

USTRUCT(BlueprintType)
struct FCollectionCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCollectionSubcategory> Subcategories;
    
    PHOENIX_API FCollectionCategory();
};

