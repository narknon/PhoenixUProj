#pragma once
#include "CoreMinimal.h"
#include "MapDungeonSaveData.generated.h"

USTRUCT(BlueprintType)
struct FMapDungeonSaveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DungeonName;
    
    PHOENIX_API FMapDungeonSaveData();
};

