#pragma once
#include "CoreMinimal.h"
#include "MapDungeonSaveData.h"
#include "MapDungeonSaveDataBlob.generated.h"

USTRUCT(BlueprintType)
struct FMapDungeonSaveDataBlob {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapDungeonSaveData> DungeonFOWDataListData;
    
    PHOENIX_API FMapDungeonSaveDataBlob();
};

