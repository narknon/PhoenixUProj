#pragma once
#include "CoreMinimal.h"
#include "CollectionItem.generated.h"

USTRUCT(BlueprintType)
struct FCollectionItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemState;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 UpdateTime;
    
    PHOENIX_API FCollectionItem();
};

