#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbAssetMapStruct.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FDbAssetMapStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> m_actorClass;
    
    DBASSETMAPPER_API FDbAssetMapStruct();
};

