#pragma once
#include "CoreMinimal.h"
#include "EInputContextLogicType.h"
#include "InputContextWithType.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FInputContextWithType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EInputContextLogicType::Type> ContextLogicType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugValueChange;
    
    FInputContextWithType();
};

