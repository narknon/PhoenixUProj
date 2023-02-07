#pragma once
#include "CoreMinimal.h"
#include "OnLoadCompleteEventDelegate.h"
#include "DynamicObjectLoadData.generated.h"

USTRUCT(BlueprintType)
struct FDynamicObjectLoadData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadCompleteEvent m_onLoadCompleteDelegate;
    
    PHOENIX_API FDynamicObjectLoadData();
};

