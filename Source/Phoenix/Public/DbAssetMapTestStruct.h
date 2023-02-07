#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbAssetMapTestStruct.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FDbAssetMapTestStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> m_actorClass;
    
    PHOENIX_API FDbAssetMapTestStruct();
};

