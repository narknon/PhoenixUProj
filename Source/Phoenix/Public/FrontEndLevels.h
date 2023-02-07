#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FrontEndLevels.generated.h"

USTRUCT(BlueprintType)
struct FFrontEndLevels : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Path;
    
    PHOENIX_API FFrontEndLevels();
};

