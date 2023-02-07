#pragma once
#include "CoreMinimal.h"
#include "CollectionNotificationData.generated.h"

USTRUCT(BlueprintType)
struct FCollectionNotificationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollectionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollectionCategory;
    
    PHOENIX_API FCollectionNotificationData();
};

