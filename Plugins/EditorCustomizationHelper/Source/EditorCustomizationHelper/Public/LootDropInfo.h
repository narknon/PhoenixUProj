#pragma once
#include "CoreMinimal.h"
#include "LootDropInfo.generated.h"

USTRUCT(BlueprintType)
struct EDITORCUSTOMIZATIONHELPER_API FLootDropInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> AllowedObjectGroupList;
    
    FLootDropInfo();
};

