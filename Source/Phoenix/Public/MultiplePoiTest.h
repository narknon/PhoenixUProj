#pragma once
#include "CoreMinimal.h"
#include "MultiplePoiTest.generated.h"

USTRUCT(BlueprintType)
struct FMultiplePoiTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TestName;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MapName;
    
    PHOENIX_API FMultiplePoiTest();
};

