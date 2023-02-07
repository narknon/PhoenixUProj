#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MinimapHogwartsLevelData.generated.h"

USTRUCT(BlueprintType)
struct FMinimapHogwartsLevelData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BottomZValue;
    
    PHOENIX_API FMinimapHogwartsLevelData();
};

