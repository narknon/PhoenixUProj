#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "ForbiddenAreaSpecificNPC.generated.h"

USTRUCT(BlueprintType)
struct FForbiddenAreaSpecificNPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo DbCharacterID;
    
    PHOENIX_API FForbiddenAreaSpecificNPC();
};

