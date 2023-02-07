#pragma once
#include "CoreMinimal.h"
#include "CollectionItem.h"
#include "CollectionSubcategory.generated.h"

USTRUCT(BlueprintType)
struct FCollectionSubcategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubcategoryID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCollectionItem> CollectionItems;
    
    PHOENIX_API FCollectionSubcategory();
};

