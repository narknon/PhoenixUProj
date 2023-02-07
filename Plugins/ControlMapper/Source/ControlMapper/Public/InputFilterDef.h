#pragma once
#include "CoreMinimal.h"
#include "InputFilterDef.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FInputFilterDef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FilterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LogicElements;
    
    FInputFilterDef();
};

