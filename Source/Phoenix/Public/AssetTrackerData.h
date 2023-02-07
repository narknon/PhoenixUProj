#pragma once
#include "CoreMinimal.h"
#include "ChildSpawnData.h"
#include "ObjectCountChangedDelegate.h"
#include "AssetTrackerData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FAssetTrackerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AssetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChildrenInWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentChildCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FChildSpawnData> ChildSpawnData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectCountChanged ObjectCountChangedDelegate;
    
    PHOENIX_API FAssetTrackerData();
};

