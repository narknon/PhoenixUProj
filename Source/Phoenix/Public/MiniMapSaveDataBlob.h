#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MiniMapSanctuarySaveData.h"
#include "MiniMapTentsData.h"
#include "MiniMapSaveDataBlob.generated.h"

USTRUCT(BlueprintType)
struct FMiniMapSaveDataBlob {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiniMapSanctuarySaveData Sanctuary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiniMapTentsData Tents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInTent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LastTentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastOverlandLocation;
    
    PHOENIX_API FMiniMapSaveDataBlob();
};

