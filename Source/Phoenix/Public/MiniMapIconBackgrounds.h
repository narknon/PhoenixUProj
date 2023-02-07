#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MiniMapIconBackgrounds.generated.h"

USTRUCT(BlueprintType)
struct FMiniMapIconBackgrounds : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconBackgroundLayer2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconBackgroundLayer3;
    
    PHOENIX_API FMiniMapIconBackgrounds();
};

