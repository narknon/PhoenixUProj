#pragma once
#include "CoreMinimal.h"
#include "ObjectTrackerData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FObjectTrackerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AssetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ChildObjects;
    
    PHOENIX_API FObjectTrackerData();
};

